# These dictionaries are applied to the generated attributes dictionary at build time
# Any changes to the API should be made here. attributes.py is code generated
#
# This addon enables sideband/moniker streaming support for FIFO functions.
# Each function marked with 'supports_streaming': True will generate:
# - BeginReadFifo* / BeginWriteFifo* RPC methods
# - MonikerReadFifo* / MonikerWriteFifo* message types
#
# The 'data' parameter is marked as 'is_streaming_type': True to indicate
# it should be handled as streaming data in the Moniker messages.

functions_override_metadata = {
    # Read FIFO Functions - Enable Moniker/Sideband Streaming
    # The 'data' parameter must be marked as 'is_streaming_type': True
    # so it's excluded from BeginReadFifo* messages but included in MonikerReadFifo* messages
    'ReadFifoBool': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'NiFpga_Bool[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoDbl': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'double[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI16': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'int16_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI32': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'int32_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI64': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'int64_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoI8': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'int8_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoSgl': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'float[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU16': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'uint16_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU32': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'uint32_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU64': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'uint64_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'ReadFifoU8': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'out',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'passed-in', 'value': 'numberOfElements'},
                'type': 'uint8_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'elementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    # Write FIFO Functions - Enable Moniker/Sideband Streaming
    # The 'data' parameter must be marked as 'is_streaming_type': True
    'WriteFifoBool': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'NiFpga_Bool[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoDbl': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'double[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI16': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'int16_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI32': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'int32_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI64': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'int64_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoI8': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'int8_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoSgl': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'float[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU16': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'uint16_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU32': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'uint32_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU64': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'uint64_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
    'WriteFifoU8': {
        'supports_streaming': True,
        'parameters': [
            {'direction': 'in', 'name': 'session', 'type': 'NiFpga_Session'},
            {'direction': 'in', 'name': 'fifo', 'type': 'uint32_t'},
            {
                'direction': 'in',
                'is_streaming_type': True,
                'name': 'data',
                'size': {'mechanism': 'len', 'value': 'numberOfElements'},
                'type': 'uint8_t[]'
            },
            {'direction': 'in', 'name': 'numberOfElements', 'type': 'size_t'},
            {'direction': 'in', 'name': 'timeout', 'type': 'uint32_t'},
            {'direction': 'out', 'name': 'emptyElementsRemaining', 'type': 'size_t'}
        ],
        'returns': 'NiFpga_Status'
    },
}

# Alternative: If metadata mutation doesn't automatically mark the 'data' parameter
# as 'is_streaming_type': True, you may need to also update parameter metadata.
# This would override the entire function definition to add the flag:
#
# functions_override_metadata = {
#     'ReadFifoBool': {
#         'supports_streaming': True,
#         'parameters': [
#             # session parameter
#             {
#                 'direction': 'in',
#                 'name': 'session',
#                 'type': 'NiFpga_Session'
#             },
#             # fifo parameter
#             {
#                 'direction': 'in',
#                 'name': 'fifo',
#                 'type': 'uint32_t'
#             },
#             # data parameter - MARKED AS STREAMING TYPE
#             {
#                 'direction': 'out',
#                 'is_streaming_type': True,
#                 'name': 'data',
#                 'size': {
#                     'mechanism': 'passed-in',
#                     'value': 'numberOfElements'
#                 },
#                 'type': 'NiFpga_Bool[]'
#             },
#             # numberOfElements parameter
#             {
#                 'direction': 'in',
#                 'name': 'numberOfElements',
#                 'type': 'size_t'
#             },
#             # timeout parameter
#             {
#                 'direction': 'in',
#                 'name': 'timeout',
#                 'type': 'uint32_t'
#             },
#             # elementsRemaining parameter
#             {
#                 'direction': 'out',
#                 'name': 'elementsRemaining',
#                 'type': 'size_t'
#             }
#         ],
#         'returns': 'NiFpga_Status'
#     },
#     # ... and so on for each FIFO function
# }
