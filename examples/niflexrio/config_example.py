"""Configure FlexRIO loopbacks and access the example FPGA VI's I/O.

The FPGA is opened without running so configuration can be committed first.
Run must then start the VI before reading inputs or driving physical outputs;
reading back an output control alone does not verify the pin's state.
"""

import grpc
import math
import niflexrio_pb2 as niflexrio_types
import niflexrio_pb2_grpc as niflexrio_grpc
import nifpga_pb2 as nifpga_types
import nifpga_pb2_grpc as grpc_nifpga
import sys
from ctypes import c_int32


SERVER_ADDRESS = "10.2.160.6"
SERVER_PORT = "31763"
SESSION_NAME = "NI-Flexrio-Session"
RESOURCE = "RIO0"

NI_FPGA_EXAMPLE_BITFILE_PATH = "/home/admin/flexrio7981-test/NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA.lvbitx"
NI_FPGA_EXAMPLE_SIGNATURE = "8348923CDBEA89627981E9D53B0F39EC"

DIO_OUT_CHANNEL = "DIO0"
DIO_IN_CHANNEL = "DIO2"

NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlU16_datatype = 0x80000032
NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlI32_softwaredrivenaochannelnumber = 0x80000020
NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlFxp_softwaredrivenaovalue_Resource = 0x80000024
NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorFxpArray_aivalues_Resource = 0x80000018
NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorFxpArray_aivalues_PackedSizeInBytes = 112
FXP_IS_SIGNED = True
FXP_WORD_LENGTH = 20
FXP_INTEGER_WORD_LENGTH = 5
AI_FXP_IS_SIGNED = True
AI_FXP_WORD_LENGTH = 28
AI_FXP_INTEGER_WORD_LENGTH = 6
AO0_TEST_VALUE = 5.5
AO_DATA_TYPE_FIXED_POINT = 1
AI0_CHANNEL = "Conn2/AI0"
AO0_CHANNEL = "Conn1/AO0"
AI0_RANGE = 10.0
AO0_RANGE = 10.0

NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlU32_conn0dovalues = 0x8
NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorU32_conn0divalues = 0x10
DIO_IN_BIT = 1 << 2
DIO_OUT_BIT = 1 << 0


# Read in cmd args
if len(sys.argv) >= 2:
    SERVER_ADDRESS = sys.argv[1]
if len(sys.argv) >= 3:
    SERVER_PORT = sys.argv[2]
if len(sys.argv) >= 4:
    RESOURCE = sys.argv[3]

channel = grpc.insecure_channel(f"{SERVER_ADDRESS}:{SERVER_PORT}")
client_niflexrio = niflexrio_grpc.NiFlexRIOStub(channel)
client_nifpga = grpc_nifpga.NiFpgaStub(channel)

def check_for_warning(response):
    """Print to console if the status indicates a warning."""
    if response.status > 0:
        sys.stderr.write(f"Warning status: {response.status}\n")


def double_to_fxp_u32(value, is_signed, word_length, integer_word_length):
    """Encode an in-range FXP value for WriteU32; reject invalid inputs."""
    if not 1 <= word_length <= 32:
        raise ValueError("This helper supports FXP widths from 1 to 32 bits.")
    if not math.isfinite(value):
        raise ValueError("The FXP input must be finite.")

    delta = math.ldexp(1.0, integer_word_length - word_length)
    minimum = -(1 << (word_length - 1)) if is_signed else 0
    maximum = (1 << (word_length - int(is_signed))) - 1

    if not minimum * delta <= value <= maximum * delta:
        raise ValueError("The value is outside the FXP representable range.")

    # NI's conversion truncates toward zero rather than rounding.
    return math.trunc(value / delta) & ((1 << word_length) - 1)


def fxp_to_double(raw_value, is_signed, word_length, integer_word_length):
    """Convert a raw fixed-point integer to a Python float."""
    if not 1 <= word_length <= 32:
        raise ValueError("This helper supports FXP widths from 1 to 32 bits.")
    if not 0 <= integer_word_length <= word_length:
        raise ValueError("The integer word length must be between 0 and word length.")
    if not isinstance(raw_value, int):
        raise TypeError("The raw FXP value must be an integer.")

    maximum_raw_value = (1 << word_length) - 1
    if not 0 <= raw_value <= maximum_raw_value:
        raise ValueError(
            f"The raw FXP value must fit in {word_length} bits."
        )

    if is_signed and raw_value & (1 << (word_length - 1)):
        raw_value -= 1 << word_length

    delta = math.ldexp(1.0, integer_word_length - word_length)
    return raw_value * delta


def unpack_ai_values(packed_data):
    """Unpack the AI indicator's 32 packed 28-bit values."""
    expected_size = NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorFxpArray_aivalues_PackedSizeInBytes
    if len(packed_data) != expected_size:
        raise ValueError(
            f"Expected {expected_size} packed AI bytes, got {len(packed_data)}."
        )

    values = []
    for offset in range(0, len(packed_data), 7):
        values.append(
            ((packed_data[offset] & 0xFF) << 20)
            | ((packed_data[offset + 1] & 0xFF) << 12)
            | ((packed_data[offset + 2] & 0xFF) << 4)
            | ((packed_data[offset + 3] >> 4) & 0xF)
        )
        values.append(
            ((packed_data[offset + 3] & 0xF) << 24)
            | ((packed_data[offset + 4] & 0xFF) << 16)
            | ((packed_data[offset + 5] & 0xFF) << 8)
            | (packed_data[offset + 6] & 0xFF)
        )
    return values

new_session = None
try:
    open_session_response = client_nifpga.Open(
        nifpga_types.OpenRequest(
            session_name=SESSION_NAME,
            bitfile=NI_FPGA_EXAMPLE_BITFILE_PATH,
            signature=NI_FPGA_EXAMPLE_SIGNATURE,
            resource=RESOURCE,
            attribute_mapped=nifpga_types.OpenAttribute.OPEN_ATTRIBUTE_UNSPECIFIED,
        )
    )
    check_for_warning(open_session_response)
    new_session = open_session_response.session
    read_AiChannelCount_response = client_niflexrio.GetAttributeInt32(
        niflexrio_types.GetAttributeInt32Request(
            session=new_session,
            repeated_capability="",
            attr_id=niflexrio_types.AttributeInt32.ATTRIBUTE_INT32_AiChannelCount,
        )
    )
    check_for_warning(read_AiChannelCount_response)
    print(f"AI Channel Count: {read_AiChannelCount_response.value}")

    read_AoChannelCount_response = client_niflexrio.GetAttributeInt32(
        niflexrio_types.GetAttributeInt32Request(
            session=new_session,
            repeated_capability="",
            attr_id=niflexrio_types.AttributeInt32.ATTRIBUTE_INT32_AoChannelCount,
        )
    )
    check_for_warning(read_AoChannelCount_response)
    print(f"AO Channel Count: {read_AoChannelCount_response.value}")

    read_DioChannelCount_response = client_niflexrio.GetAttributeInt32(
        niflexrio_types.GetAttributeInt32Request(
            session=new_session,
            repeated_capability="",
            attr_id=niflexrio_types.AttributeInt32.ATTRIBUTE_INT32_DioChannelCount,
        )
    )
    check_for_warning(read_DioChannelCount_response)
    print(f"DIO Channel Count: {read_DioChannelCount_response.value}")

    set_DiConfiguration_response = client_niflexrio.SetAttributeInt32(
        niflexrio_types.SetAttributeInt32Request(
            session=new_session,
            repeated_capability=DIO_IN_CHANNEL,
            attr_id=niflexrio_types.AttributeInt32.ATTRIBUTE_INT32_DioLineConfig,
            value=niflexrio_types.DioConfiguration.DIO_CONFIGURATION_DioConfiguration_Input,  # Replace with the desired configuration value
        )
    )
    check_for_warning(set_DiConfiguration_response)
    print(f"{DIO_IN_CHANNEL} line configuration set to input.")

    set_DoConfiguration_response = client_niflexrio.SetAttributeInt32(
        niflexrio_types.SetAttributeInt32Request(
            session=new_session,
            repeated_capability=DIO_OUT_CHANNEL,
            attr_id=niflexrio_types.AttributeInt32.ATTRIBUTE_INT32_DioLineConfig,
            value=niflexrio_types.DioConfiguration.DIO_CONFIGURATION_DioConfiguration_Output,  # Replace with the desired configuration value
        )
    )
    check_for_warning(set_DoConfiguration_response)
    print(f"{DIO_OUT_CHANNEL} line configuration set to output.")

    commit_response = client_niflexrio.Commit(
        niflexrio_types.CommitRequest(
            session=new_session
        )
    )
    check_for_warning(commit_response)

    print("Committed configuration.")

    run_response = client_nifpga.Run(
        nifpga_types.RunRequest(
            session=new_session,
            attribute=nifpga_types.RunAttribute.RUN_ATTRIBUTE_UNSPECIFIED,
        )
    )
    if run_response.status < 0:
        raise RuntimeError(f"Run FPGA VI failed: {run_response.status}")
    check_for_warning(run_response)
    print("FPGA VI started.")

    read_DiConfiguration_response = client_niflexrio.GetAttributeInt32(
        niflexrio_types.GetAttributeInt32Request(
            session=new_session,
            repeated_capability=DIO_IN_CHANNEL,
            attr_id=niflexrio_types.AttributeInt32.ATTRIBUTE_INT32_DioLineConfig,
        )
    )
    check_for_warning(read_DiConfiguration_response)
    print(f"{DIO_IN_CHANNEL} line configuration read back as {read_DiConfiguration_response.value}")

    read_DoConfiguration_response = client_niflexrio.GetAttributeInt32(
        niflexrio_types.GetAttributeInt32Request(
            session=new_session,
            repeated_capability=DIO_OUT_CHANNEL,
            attr_id=niflexrio_types.AttributeInt32.ATTRIBUTE_INT32_DioLineConfig,
        )
    )
    check_for_warning(read_DoConfiguration_response)
    print(f"{DIO_OUT_CHANNEL} line configuration read back as {read_DoConfiguration_response.value}")

    read_di_value_response = client_nifpga.ReadU32(
        nifpga_types.ReadU32Request(
            session=new_session,
            indicator=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorU32_conn0divalues
        )
    )
    check_for_warning(read_di_value_response)
    input_value = 1 if (read_di_value_response.value & DIO_IN_BIT) else 0
    print(f"{DIO_IN_CHANNEL} read back as {input_value}")

    read_do_values_response = client_nifpga.ReadU32(
        nifpga_types.ReadU32Request(
            session=new_session,
            # ReadU32Request usa el campo "indicator" en el proto.
            # Aquí pasamos la dirección del mismo registro DO.
            indicator=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlU32_conn0dovalues,
        )
    )
    check_for_warning(read_do_values_response)

    print(f"{DIO_OUT_CHANNEL} value before setting: {read_do_values_response.value}")

    output_values = read_do_values_response.value
    output_values |= DIO_OUT_BIT

    do_write_response = client_nifpga.WriteU32(
        nifpga_types.WriteU32Request(
            session=new_session,
            control=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlU32_conn0dovalues,
            value=output_values,
        )
    )
    if do_write_response.status < 0:
        raise RuntimeError(
            f"Write DO value failed: {do_write_response.status}"
        )
    check_for_warning(do_write_response)

    read_do_value_response = client_nifpga.ReadU32(
        nifpga_types.ReadU32Request(
            session=new_session,
            indicator=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlU32_conn0dovalues
        )
    )
    check_for_warning(read_do_value_response)

    print(f"{DIO_OUT_CHANNEL} value after setting: {read_do_value_response.value}")

    read_di_value_response = client_nifpga.ReadU32(
        nifpga_types.ReadU32Request(
            session=new_session,
            indicator=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorU32_conn0divalues
        )
    )
    check_for_warning(read_di_value_response)
    input_value = 1 if (read_di_value_response.value & DIO_IN_BIT) else 0
    print(f"{DIO_IN_CHANNEL} read back as {input_value}")

    print("Configuration and I/O operations completed successfully.")

    set_AiRange_response = client_niflexrio.SetAttributeDouble(
        niflexrio_types.SetAttributeDoubleRequest(
            session=new_session,
            repeated_capability=AI0_CHANNEL,
            attr_id=niflexrio_types.AttributeDouble.ATTRIBUTE_DOUBLE_AiRange,
            value=AI0_RANGE,
        )
    )
    check_for_warning(set_AiRange_response)

    set_AoRange_response = client_niflexrio.SetAttributeDouble(
        niflexrio_types.SetAttributeDoubleRequest(
            session=new_session,
            repeated_capability=AO0_CHANNEL,
            attr_id=niflexrio_types.AttributeDouble.ATTRIBUTE_DOUBLE_AoRange,
            value=AO0_RANGE,
        )
    )
    check_for_warning(set_AoRange_response)

    commit_response = client_niflexrio.Commit(
        niflexrio_types.CommitRequest(
            session=new_session
        )
    )
    check_for_warning(commit_response)

    print("Configuration for AOI committed successfully.")

    read_AiRange_response = client_niflexrio.GetAttributeDouble(
        niflexrio_types.GetAttributeDoubleRequest(
            session=new_session,
            repeated_capability=AI0_CHANNEL,
            attr_id=niflexrio_types.AttributeDouble.ATTRIBUTE_DOUBLE_AiRange,
        )
    )
    check_for_warning(read_AiRange_response)
    print(f"{AI0_CHANNEL} AiRange is {read_AiRange_response.value}")

    read_AoRange_response = client_niflexrio.GetAttributeDouble(
        niflexrio_types.GetAttributeDoubleRequest(
            session=new_session,
            repeated_capability=AO0_CHANNEL,
            attr_id=niflexrio_types.AttributeDouble.ATTRIBUTE_DOUBLE_AoRange,
        )
    )
    check_for_warning(read_AoRange_response)
    print(f"{AO0_CHANNEL} AoRange is {read_AoRange_response.value}")

    set_DataType_response = client_nifpga.WriteU16(
        nifpga_types.WriteU16Request(
            session=new_session,
            control=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlU16_datatype,
            value=AO_DATA_TYPE_FIXED_POINT,
        )
    )
    check_for_warning(set_DataType_response)

    set_softwaredrivenaochannelnumber_response = client_nifpga.WriteI32(
        nifpga_types.WriteI32Request(
            session=new_session,
            control=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlI32_softwaredrivenaochannelnumber,
            value=0,
        )
    )
    check_for_warning(set_softwaredrivenaochannelnumber_response)

    raw_value = double_to_fxp_u32(
        AO0_TEST_VALUE,
        is_signed=FXP_IS_SIGNED,
        word_length=FXP_WORD_LENGTH,
        integer_word_length=FXP_INTEGER_WORD_LENGTH,
    )
    write_ao_response = client_nifpga.WriteU32(
        nifpga_types.WriteU32Request(
            session=new_session,
            control=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_ControlFxp_softwaredrivenaovalue_Resource,
            value=raw_value,
        )
    )
    if write_ao_response.status < 0:
        raise RuntimeError(
            f"Write AO0 fixed-point value failed: {write_ao_response.status}"
        )
    check_for_warning(write_ao_response)
    print(f"AO0 fixed-point value written: {AO0_TEST_VALUE} (raw: {raw_value:#x})")

    read_aivalues_response = client_nifpga.ReadArrayU8(
        nifpga_types.ReadArrayU8Request(
            session=new_session,
            indicator=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorFxpArray_aivalues_Resource,
            size=NiFpga_PXIe789XFPGAlvlibPXIe789XFPGA_IndicatorFxpArray_aivalues_PackedSizeInBytes,
        )
    )
    if read_aivalues_response.status < 0:
        raise RuntimeError(
            f"Read AI values failed: {read_aivalues_response.status}"
        )
    check_for_warning(read_aivalues_response)
    print(f"AI values read (raw): {read_aivalues_response.array}")

    raw_ai_values = unpack_ai_values(read_aivalues_response.array)
    print(f"AI values unpacked (raw): {raw_ai_values}")
    ai_values = [
        fxp_to_double(
            value,
            is_signed=AI_FXP_IS_SIGNED,
            word_length=AI_FXP_WORD_LENGTH,
            integer_word_length=AI_FXP_INTEGER_WORD_LENGTH,
        )
        for value in raw_ai_values
    ]
    print(f"AI values converted to double: {[f'{value:.6f}' for value in ai_values]}")

except grpc.RpcError as rpc_error:
    print(f"failed with error: {rpc_error}")

finally :
    close_response = client_nifpga.Close(
        nifpga_types.CloseRequest(
            session=new_session,
            attribute=nifpga_types.CloseAttribute.CLOSE_ATTRIBUTE_UNSPECIFIED
        )
    )
    check_for_warning(close_response)