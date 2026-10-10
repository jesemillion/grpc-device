# -*- coding: utf-8 -*-
config = {
    'api_version': '26.0.0f134',
    'c_header': 'niflexrioapi.h',
    'c_function_prefix': 'niFlexRIO_',
    'c_dll_function_prefix': 'niFlexRIO_',
    'service_class_prefix': 'NiFlexRIO',
    'java_package': 'com.ni.grpc.niflexrio',
    'csharp_namespace': 'NationalInstruments.Grpc.NiFlexRIO',
    'namespace_component': 'niflexrio',
    'init_function': 'OpenSession',
    'close_function': 'CloseSession',
    'code_readiness': 'Release',
    'driver_name': 'NI-FlexRIO',
    'status_ok': 'status >= 0',
    'additional_protos': ['data_moniker.proto'],
    'resource_handle_type': ['NiFpga_Session'],
    'type_to_grpc_type': {
        'NiFpga_Session': 'nidevice_grpc.Session',
        'char[]': 'string',
        'FlexRIO_Status': 'int32',
        'FlexRIO_AttributeInt32': 'int32',
        'FlexRIO_AttributeDouble': 'int32',
        'size_t': 'uint32',
        'int32_t': 'int32',
    },
    'has_moniker_streaming_apis': True,
    'custom_types': [],
    'library_info': {
        'Linux': {
            '64bit': {
                'name': 'niflexrioapi',
                'type': 'cdll'
            }
        },
        'Windows': {
            '32bit': {
                'name': 'niflexrioapi.dll',
                'type': 'windll'
            },
            '64bit': {
                'name': 'niflexrioapi.dll',
                'type': 'cdll'
            }
        }
    },
    'linux_rt_support': True,
    'metadata_version': '0.1',
    'module_name': 'niflexrio',
    'session_class_description': 'An NI-FlexRIO session.',
    'session_handle_parameter_name': 'session'
}