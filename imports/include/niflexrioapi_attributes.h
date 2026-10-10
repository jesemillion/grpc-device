/** @defgroup attributes NI FlexRIO C Attributes
 *  @ingroup root_niflexrioapi
 * <details>resourceid:flexrio-integrated-io-c-api-ref_attributes</details>
 * @{
 */






#ifndef __niflexrioapi_attributes_h__
#define __niflexrioapi_attributes_h__

/** 
 * <details>resourceid:flexrio-integrated-io-c-api-ref_attributes_flexrioattributeint32</details>
 */
typedef enum {
   kFlexRIO_FirstInt32Sentinel              = 0x10000000, 
   kFlexRIO_ChannelsInStream                = 0x10000000,  /**< Specifies the number of channels available in the named stream. */
   kFlexRIO_StreamDataFormat                = 0x10000003, 
   kFlexRIO_AdcResolution                   = 0x10000005,  /**< Indicates the number of bits of data returned to the FPGA diagram. */
   kFlexRIO_AdcSampleContainer              = 0x10000006,  /**< Indicates the number of bits used to represent data to the diagram. */
   kFlexRIO_TClkSessionReference            = 0x10000007,  /**< Internal TClk session reference memory */
   kFlexRIO_AnalogEdgeTriggerChannel        = 0x10000008,  /**< Specifies the channel to monitor for edge trigger conditions. */
   kFlexRIO_StartTriggerType                = 0x10000009,  /**< Specifies the trigger type. */
   kFlexRIO_ReferenceClockSource            = 0x1000000b,  /**< Specifies the Reference Clock source. */
   kFlexRIO_CalibrationStorageSize          = 0x1000000c,  /**< Indicates the size in bytes of available calibration storage. */
   kFlexRIO_IoError                         = 0x1000000d,  /**< Reports error codes when the I/O module enters an error state. */
   kFlexRIO_AiNyquistZone                   = 0x1000000e,  /**< Specifies the Nyquist Zone in which the input signal resides. */
   kFlexRIO_AiChannelCount                  = 0x1000000f,  /**< Indicates the number of analog input channels on the device. */
   kFlexRIO_AdcClockDivisor                 = 0x10000010,  /**< Indicates the ratio between the sample clock timebase rate and the ADC sample clock. */
   kFlexRIO_AiCoupling                      = 0x10000011,  /**< Specifies the coupling of the channel. */
   kFlexRIO_PhaseDacValue                   = 0x10000012,  /**< Specifies the value of the clock phase digital-to-analog converter (DAC). */
   kFlexRIO_SampleClockSource               = 0x10000013,  /**< Specifies the Sample Clock source. */
   kFlexRIO_AiDecimationFilterBand          = 0x10000014,  /**< Specifies a highpass or lowpass filter response for the ADC decimation filter. */
   kFlexRIO_DataClockDivisor                = 0x10000015,  /**< Indicates the ratio between the Sample Clock timebase rate and the Data Clock. */
   kFlexRIO_StartTriggerSensitivity         = 0x10000016,  /**< Specifies the trigger sensitivity. */
   kFlexRIO_BaseboardReferenceClockSource   = 0x10000018,  /**< Specifies the source for the baseboard reference clock. */
   kFlexRIO_AdcInterleavingFactor           = 0x10000019,  /**< Specifies the number of ADC cores to interleave for time-interleaved sampling. */
   kFlexRIO_DacClockDivisor                 = 0x1000001a,  /**< Indicates the ratio between the sample clock timebase rate and the DAC sample clock. */
   kFlexRIO_AoChannelCount                  = 0x1000001b,  /**< Indicates the number of analog output channels on the device. */
   kFlexRIO_AiOffsetDac                     = 0x1000001c,  /**< Specifies the vertical offset of the channel in DAC codes. Setting this property will cause the value of the AI Offset property to be ignored. */
   kFlexRIO_BusType                         = 0x1000001d,  /**< Indicates the bus type for the device. */
   kFlexRIO_PrimaryTClkStreamInstance       = 0x10000020,  /**< Specifies which stream instance is the primary stream for TClk when serving as a TClk trigger master. */
   kFlexRIO_StartTriggerSynchronizer        = 0x10000021,  /**< Specifies the trigger synchronizer configuration. */
   kFlexRIO_DacResolution                   = 0x10000023,  /**< Indicates the number of bits of data used to represent an output sample in the FPGA diagram. */
   kFlexRIO_UserClockCount                  = 0x10000024,  /**< Specifies the number of user clocks available. */
   kFlexRIO_CableSenseMode                  = 0x10000025,  /**< Specifies whether the CableSense signal will be generated on the specified channel. */
   kFlexRIO_SiChannelCount                  = 0x10000026,  /**< Indicates the number of serial input channels on the device. */
   kFlexRIO_SoChannelCount                  = 0x10000027,  /**< Indicates the number of serial output channels on the device. */
   kFlexRIO_SiPoCSource                     = 0x10000028,  /**< Configures the power over coax source on the specified serial input channel. */
   kFlexRIO_SoPoCSink                       = 0x10000029,  /**< Configures the power over coax sink on the specified serial output channel. */
   kFlexRIO_DiChannelCount                  = 0x1000002a,  /**< Indicates the number of digital input channels on the device. */
   kFlexRIO_DoChannelCount                  = 0x1000002b,  /**< Indicates the number of digital output channels on the device. */
   kFlexRIO_PfiChannelCount                 = 0x1000002c,  /**< Indicates the number of PFI channels on the device. */
   kFlexRIO_DiffPfiChannelCount             = 0x1000002d,  /**< Indicates the number of differential PFI channels on the device. */
   kFlexRIO_PfiLineConfig                   = 0x1000002e,  /**< Specifies the line direction of the active channel. */
   kFlexRIO_DiffPfiLineConfig               = 0x1000002f,  /**< Specifies the line direction of the active channel. */
   kFlexRIO_DioChannelCount                 = 0x10000030,  /**< Indicates the number of digital I/O channels on the device. */
   kFlexRIO_DioLineConfig                   = 0x10000031,  /**< Specifies the line direction of the active channel. */
   kFlexRIO_AoChannelStatus                 = 0x10000033,  /**< Indicates the status of the channel. */
   kFlexRIO_SiCsi2Lanes                     = 0x10000035,  /**< Specifies the number of active CSI-2 lanes. */
   kFlexRIO_SoCsi2Lanes                     = 0x10000036,  /**< Specifies the number of active CSI-2 lanes. */
   kFlexRIO_CircularBufferSegments          = 0x10000118,  /**< Specifies the number of segments the FPGA-side circular buffer is divided into. */
   kFlexRIO_LastInt32Sentinel               = 0x1000ffff, 
} FlexRIO_AttributeInt32;


/** 
 * <details>resourceid:flexrio-integrated-io-c-api-ref_attributes_flexrioattributedouble</details>
 */
typedef enum {
   kFlexRIO_FirstDoubleSentinel             = 0x20000000, 
   kFlexRIO_AnalogEdgeTriggerLevel          = 0x20000002,  /**< Specifies the trigger level in volts. */
   kFlexRIO_AnalogEdgeTriggerHysteresis     = 0x20000003,  /**< Specifies the trigger hysteresis in volts. */
   kFlexRIO_ExternalAnalogEdgeTriggerLevel  = 0x20000004,  /**< Specifies the trigger level in volts. */
   kFlexRIO_FpgaTemperature                 = 0x20000005,  /**< Indicates the current FPGA temperature in degrees Celsius. */
   kFlexRIO_TotalPower                      = 0x20000006,  /**< Indicates the total power consumed by the device in watts. */
   kFlexRIO_12vPower                        = 0x20000007,  /**< Indicates the power consumed by the 12V rail in watts. */
   kFlexRIO_3v3Power                        = 0x20000008,  /**< Indicates the power consumed by the 3.3V rail in watts. */
   kFlexRIO_12vIoPower                      = 0x20000009,  /**< Indicates the power consumed by the 12V rail to the IO in watts. */
   kFlexRIO_TemperatureLimit                = 0x2000000a,  /**< Indicates the temperature in degrees Celsius at which the device will shut down to prevent damage. */
   kFlexRIO_PowerLimit                      = 0x2000000b,  /**< Indicates the level of total power consumption in watts at which the device will shut down to prevent damage. */
   kFlexRIO_AdcTemperature                  = 0x2000000c,  /**< Indicates the current ADC temperature in degrees Celsius. */
   kFlexRIO_CalibrationTemperature          = 0x2000000d,  /**< Indicates the FPGA temperature at last write to calibration storage in degrees Celsius. */
   kFlexRIO_VerificationTemperature         = 0x2000000e,  /**< Indicates the FPGA temperature at last verification in degrees Celsius. */
   kFlexRIO_AiImpedance                     = 0x2000000f,  /**< Specifies the impedance of the channel in ohms. */
   kFlexRIO_AiRange                         = 0x20000010,  /**< Specifies the vertical range of the channel in volts. */
   kFlexRIO_AiScalingGain                   = 0x20000011,  /**< Specifies the ratio between volts and ADC codes on the channel data. */
   kFlexRIO_AiScalingOffset                 = 0x20000012,  /**< Specifies the offset between volts and ADC codes on the channel data. */
   kFlexRIO_SampleDt                        = 0x20000013,  /**< Overrides the dt metadata returned in waveforms. */
   kFlexRIO_DioVoltage                      = 0x20000014,  /**< Specifies the DIO voltage. */
   kFlexRIO_DataClockRate                   = 0x20000015,  /**< Indicates the Data Clock rate for the I/O module. */
   kFlexRIO_AdcSampleRate                   = 0x20000016,  /**< Indicates the rate at which the analog-to-digital converter samples and digitizes a signal. */
   kFlexRIO_SampleClockTimebaseRate         = 0x20000017,  /**< Specifies the Sample Clock timebase rate. */
   kFlexRIO_ReferenceClockRate              = 0x20000018,  /**< Indicates the Reference Clock rate. */
   kFlexRIO_DataDelay                       = 0x20000019,  /**< Specifies the delay after the sample clock rising edge when the device acquires a new data sample. */
   kFlexRIO_DacSampleRate                   = 0x2000001a,  /**< Indicates the rate at which the digital-to-analog converter outputs samples. */
   kFlexRIO_AoImpedance                     = 0x2000001b,  /**< Specifies the impedance of the channel in ohms. */
   kFlexRIO_AoScalingGain                   = 0x2000001c,  /**< Specifies the ratio between volts and DAC codes on the channel data. */
   kFlexRIO_AoScalingOffset                 = 0x2000001d,  /**< Specifies the offset between volts and DAC codes on the channel data. */
   kFlexRIO_AoRange                         = 0x2000001e,  /**< Specifies the vertical range of the channel in volts. */
   kFlexRIO_AiOffset                        = 0x2000001f,  /**< Specifies the vertical offset of the channel in volts. */
   kFlexRIO_ExternalAnalogEdgeTriggerHysteresis = 0x20000021,  /**< Specifies the trigger hysteresis in volts. */
   kFlexRIO_DspFrequencyShiftMagnitude      = 0x2000002a,  /**< Directly specifies the magnitude of the frequency shift applied to the signal.  This is intended for advanced users who need to directly configure the magnitude without the units of the API. */
   kFlexRIO_DspFrequencyShift               = 0x2000002b,  /**< When DSP is enabled, this attribute specifies the amount that the frequency spectrum will be shifted.  For input streams, this means shifting the frequency spectrum down by the specified frequency.  For output streams, this means shifting the spectrum up by the specified frequency. */
   kFlexRIO_UserClockFrequency              = 0x2000002c,  /**< Configures the specified user clock to generate the requested frequency. */
   kFlexRIO_SiPoCVoltage                    = 0x2000002d,  /**< Indicates the power over coax voltage on the specified serial input channel. */
   kFlexRIO_SoPoCVoltage                    = 0x2000002e,  /**< Indicates the power over coax voltage on the specified serial output channel. */
   kFlexRIO_SiPoCCurrent                    = 0x2000002f,  /**< Indicates the power over coax current in amps on the specified serial input channel. */
   kFlexRIO_SoPoCCurrent                    = 0x20000030,  /**< Indicates the power over coax current in amps on the specified serial output channel. */
   kFlexRIO_PfiVoltage                      = 0x20000031,  /**< Specifies the PFI voltage. */
   kFlexRIO_DioLineVoltage                  = 0x20000032,  /**< Specifies the DIO line voltage. */
   kFlexRIO_TotalIoPower                    = 0x20000033,  /**< Indicates the total power consumed by the IO module in watts. */
   kFlexRIO_SoCsi2DataRate                  = 0x20000034,  /**< Specifies the CSI-2 data rate. */
   kFlexRIO_SiRefClkFrequency               = 0x20000035,  /**< Specifies the reference clock associated with the serial input channel. */
   kFlexRIO_SoRefClkFrequency               = 0x20000036,  /**< Specifies the reference clock associated with the serial output channel. */
   kFlexRIO_LastDoubleSentinel              = 0x2000ffff, 
} FlexRIO_AttributeDouble;


/** 
 * <details>resourceid:flexrio-integrated-io-c-api-ref_attributes_flexrioattributestring</details>
 */
typedef enum {
   kFlexRIO_FirstStringSentinel             = 0x30000000, 
   kFlexRIO_DigitalStartTriggerSource       = 0x30000000,  /**< Specifies the source of the digital start trigger. */
   kFlexRIO_StreamFifoName                  = 0x30000002,  /**< Returns a semicolon delimited list of the names of the FIFOs used on the stream. */
   kFlexRIO_StartTriggerOutputTerminal      = 0x30000003,  /**< Specifies the export destination for the start trigger. */
   kFlexRIO_StartTriggerForTClkOutputTerminal = 0x30000007,  /**< Specifies the export destination for the TClk conditioned start trigger. */
   kFlexRIO_DspResetSendingTerm             = 0x3000000a,  /**< Indicates the terminal that will generate the TClk synchronized DSP Reset event if this device is the DSP Reset Master. The DSP Reset Master device is the first device in the array of devices passed to SynchronizedDspReset. */
   kFlexRIO_DspResetSource                  = 0x3000000b,  /**< Specifies the source of the TClk synchronized DSP Reset event. */
   kFlexRIO_TClkStartTriggerTerm            = 0x3000000c,  /**< Indicates the terminal that will export the TClk synchronized start trigger. */
   kFlexRIO_BitfileVersion                  = 0x3000000d, 
   kFlexRIO_BitfileVendor                   = 0x3000000e,  /**< Indicates the vendor of the bitfile */
   kFlexRIO_BitfileIdentity                 = 0x3000000f,  /**< Indicates the identity of the bitfile */
   kFlexRIO_SerialNumber                    = 0x30000010,  /**< Indicates the device serial number */
   kFlexRIO_SiI2cName                       = 0x30000011,  /**< Indicates the name of the I2C bus instance associated with the specified serial input channel. */
   kFlexRIO_SoI2cName                       = 0x30000012,  /**< Indicates the name of the I2C bus instance associated with the specified serial output channel. */
   kFlexRIO_SiRefClkName                    = 0x30000013,  /**< Indicates the name of the reference clock associated with the specified serial input channel. */
   kFlexRIO_SoRefClkName                    = 0x30000014,  /**< Indicates the name of the reference clock associated with the specified serial output channel. */
   kFlexRIO_FpgaTxClockSelect               = 0x30000015,  /**< Specifies the name of the user clock to be used as the FPGA generation clock. */
   kFlexRIO_SoDataClkName                   = 0x30000016,  /**< Indicates the name of the CSI-2 data rate clock associated with the specified serial output channel. */
   kFlexRIO_LastStringSentinel              = 0x3000ffff, 
} FlexRIO_AttributeString;


/** 
 * <details>resourceid:flexrio-integrated-io-c-api-ref_attributes_flexrioattributebool</details>
 */
typedef enum {
   kFlexRIO_FirstBoolSentinel               = 0x40000000, 
   kFlexRIO_AiChannelEnabled                = 0x40000000,  /**< Specifies whether the active channel is enabled. */
   kFlexRIO_StreamFinite                    = 0x40000001,  /**< Specifies whether the stream should be finite. */
   kFlexRIO_AnalogEdgeTriggerRising         = 0x40000002,  /**< Specifies whether the analog edge trigger triggers on a rising edge. Set this value to FALSE to trigger on a falling edge. */
   kFlexRIO_IoReady                         = 0x40000003,  /**< Indicates whether the I/O is ready. */
   kFlexRIO_IocFilterEnable                 = 0x40000004,  /**< Enables the interleaving offset correction filter for the ADC. */
   kFlexRIO_TClkApiControlEnabled           = 0x40000007,  /**< Specifies whether the TClk API will control this stream. */
   kFlexRIO_AoInvSincFilterEnabled          = 0x40000008,  /**< Enables the inverse sinc filter for the channel. */
   kFlexRIO_DacDigitalUpconverterEnabled    = 0x40000009,  /**< If true, this channel's output will be sourced from the DAC's digital upconverter.  The user is expected to provide a complex waveform that will be properly steered to the DAC channels. */
   kFlexRIO_BaseboardReferenceClockExported = 0x4000000a,  /**< Controls whether the baseboard reference clock is exported. */
   kFlexRIO_ExternalAnalogEdgeTriggerRising = 0x4000000b,  /**< Specifies whether the external analog edge trigger triggers on a rising edge. Set this value to FALSE to trigger on a falling edge. */
   kFlexRIO_BaseboardReferenceClockPllLocked = 0x4000000c,  /**< Indicates whether the baseboard PLL is locked. */
   kFlexRIO_IsInputStream                   = 0x4000000e,  /**< Indicates whether the driver considers this stream to be an input stream (device to host).  If false, then this is an output stream. */
   kFlexRIO_FpgaDdcEnabled                  = 0x4000000f,  /**< Enables the FPGA DDC chain for the device.  Normally this will enable the decimator on modules that support it, as well as enable frequency shifting.  However, details of the signal processing chain are dependent on the signal path in the FPGA.  This property is detected by discovering flexrio.dsp.ddc.enable N, where N is the stream number connected to this signal path. */
   kFlexRIO_DiEqualizationEnable            = 0x40000010,  /**< Specifies whether equalization is enabled for all digital input channels. */
   kFlexRIO_DoPreEmphasisEnable             = 0x40000011,  /**< Specifies whether pre-emphasis is enabled for all digital output channels. */
   kFlexRIO_DiffPfiInputEqualizationEnable  = 0x40000012,  /**< Specifies whether input equalization is enabled for all DIFF PFI channels. */
   kFlexRIO_DiffPfiOutputPreEmphasisEnable  = 0x40000013,  /**< Specifies whether output pre-emphasis is enabled for all DIFF PFI channels. */
   kFlexRIO_FpgaDdcIqEnabled                = 0x40000019,  /**< When IQ mode is enabled, both the I and Q data will be transferred to the stream.  When it is disabled, only the I portions are captured on the device and transferred to the host.  This property has no effect if the DDC is disabled. */
   kFlexRIO_FpgaDucEnabled                  = 0x4000001b,  /**< Enables the FPGA DUC chain for the device.  Normally this will enable the decimator on modules that support it, as well as enable frequency shifting.  However, details of the signal processing chain are dependent on the signal path in the FPGA.  This property is detected by discovering flexrio.dsp.duc.enable N, where N is the stream number connected to this signal path. */
   kFlexRIO_FpgaDucIqEnabled                = 0x4000001c,  /**< When IQ mode is enabled, both the I and Q data will be transferred to the stream.  When it is disabled, only the I portions are captured on the device and transferred to the host.  This property has no effect if the DUC is disabled. */
   kFlexRIO_DataPathIqEnabled               = 0x4000001e,  /**< The data path on the FPGA uses complex data.  This affects data steering in the FPGA.  For a device with upconversion, this will be true when either the FPGA has a DUC operating in IQ mode (see the attribute 'FPGA DUC IQ Enabled'), or the device has an upconverter built into the front end that requires IQ data (see the attribute 'DAC Digital Upconverter Enabled').  In IQ mode, you are required to supply IQ data to WriteStream. */
   kFlexRIO_LinkedStartTrigger              = 0x4000001f,  /**< Configures whether this stream's trigger is overridden to be linked to another stream's start event.  Ensure the target stream is *started* before the trigger arrives. */
   kFlexRIO_BypassPll                       = 0x40000020,  /**< Specifies whether the active user clock is a re-exported copy of the reference clock that bypasses the PLL. */
   kFlexRIO_UserClockEnabled                = 0x40000021,  /**< Specifies whether the active user clock is enabled. */
   kFlexRIO_SiPoCInRange                    = 0x40000022,  /**< Indicates whether power over coax is enabled, above the minimum valid voltage, and not receiving a fault signal on the specified serial input channel. */
   kFlexRIO_SoPoCInRange                    = 0x40000023,  /**< Indicates whether power over coax is enabled, above the minimum valid voltage, and not receiving a fault signal on the specified serial output channel. */
   kFlexRIO_SiRefClkEnabled                 = 0x40000024,  /**< Specifies whether the reference clock is enabled. */
   kFlexRIO_SoRefClkEnabled                 = 0x40000025,  /**< Specifies whether the reference clock is enabled. */
   kFlexRIO_LastBoolSentinel                = 0x4000ffff, 
} FlexRIO_AttributeBool;

/** 
 * <details>resourceid:flexrio-integrated-io-c-api-ref_attributes_flexrioattributeuint64</details>
 */
typedef enum {
   kFlexRIO_FirstUInt64Sentinel             = 0x50000000, 
   kFlexRIO_StreamNumberOfSamples           = 0x50000000,  /**< Specifies the number of samples to transfer in a finite stream. */
   kFlexRIO_StreamFifoSize                  = 0x50000001,  /**< Specifies the number of samples allocated in each stream FIFO. Set this value to 0 to allow the driver to allocate the buffer according to its own heuristics. */
   kFlexRIO_StreamChannelsEnabled           = 0x50000002,  /**< Returns a bitmask indicating which channels will be transferred in this stream. */
   kFlexRIO_CalibrationDateTime             = 0x50000003,  /**< Indicates the time of the last write to calibration storage in seconds since 1904. */
   kFlexRIO_VerificationDateTime            = 0x50000004,  /**< Indicates the time of last verification in seconds since 1904. */
   kFlexRIO_CircularBufferSize              = 0x50000006,  /**< Specifies the capacity of the FPGA-side circular buffer. */
   kFlexRIO_CircularBufferElementsWritten   = 0x50000007,  /**< Specifies number of elements written into the FPGA's circular buffer. */
   kFlexRIO_LastUInt64Sentinel              = 0x5000ffff, 
} FlexRIO_AttributeUInt64;

#endif /* __niflexrioapi_attributes_h__ */

/**
* @}
*/
