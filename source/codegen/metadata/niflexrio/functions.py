functions = {
    'GetAttributeInt32': {
            'parameters': [
                {
                    'direction': 'in',
                    'name': 'session',
                    'type': 'NiFpga_Session'
                },
                {
                    'direction': 'in',
                    'name': 'repeatedCapability',
                    'type': 'char[]'
                },
                {
                    'direction': 'in',
                    'enum': 'AttributeInt32',
                    'name': 'attrID',
                    'type': 'FlexRIO_AttributeInt32'
                },       
                {
                    'direction': 'out',
                    'name': 'value',
                    'type': 'int32_t'
                }
            ],
            'returns': 'FlexRIO_Status',
    },
    'SetAttributeInt32': {
            'parameters': [
                {
                    'direction': 'in',
                    'name': 'session',
                    'type': 'NiFpga_Session'
                },
                {
                    'direction': 'in',
                    'name': 'repeatedCapability',
                    'type': 'char[]'
                },
                {
                    'direction': 'in',
                    'enum': 'AttributeInt32',
                    'name': 'attrID',
                    'type': 'FlexRIO_AttributeInt32'
                },
                {
                    'direction': 'in',
                    'name': 'value',
                    'type': 'int32_t'
                }
            ],
            'returns': 'FlexRIO_Status',
    },
    'Commit': {
            'parameters': [
                {
                    'direction': 'in',
                    'name': 'session',
                    'type': 'NiFpga_Session'
                }
            ],
            'returns': 'FlexRIO_Status'
    },
    'GetAttributeDouble': {
            'parameters': [
                {
                    'direction': 'in',
                    'name': 'session',
                    'type': 'NiFpga_Session'
                },
                {
                    'direction': 'in',
                    'name': 'repeatedCapability',
                    'type': 'char[]'
                },
                {
                    'direction': 'in',
                    'enum': 'AttributeDouble',
                    'name': 'attrID',
                    'type': 'FlexRIO_AttributeDouble'
                },
                {
                    'direction': 'out',
                    'name': 'value',
                    'type': 'double'
                }
            ],
            'returns': 'FlexRIO_Status',
    },
    'SetAttributeDouble': {
            'parameters': [
                {
                    'direction': 'in',
                    'name': 'session',
                    'type': 'NiFpga_Session'
                },
                {
                    'direction': 'in',
                    'name': 'repeatedCapability',
                    'type': 'char[]'
                },
                {
                    'direction': 'in',
                    'enum': 'AttributeDouble',
                    'name': 'attrID',
                    'type': 'FlexRIO_AttributeDouble'
                },
                {
                    'direction': 'in',
                    'name': 'value',
                    'type': 'double'
                }
            ],
            'returns': 'FlexRIO_Status',
    }  
}
