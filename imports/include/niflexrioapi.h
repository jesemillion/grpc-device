/** @defgroup root_niflexrioapi niflexrioapi.h
 * <details>resourceid:flexrio-integrated-io-c-api-ref_root_niflexrio</details>
 *
 * This is the landing page for FlexRIO Integrated IO C API reference.
 */

/** @defgroup functions NI FlexRIO C Functions
 * @ingroup root_niflexrioapi
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions</details>
 *
 * @{
 */

#ifndef __niflexrioapi_h__
#define __niflexrioapi_h__

#include <niflexrioapi_defines.h>
#include <niflexrioapi_enums.h>
#include <niflexrioapi_attributes.h>
#include <niflexrioapi_wfminfo.h>
#include <niflexrioapi_i2cbusinstancename.h>
#include <IviVisaType.h>

/** @cond DOXYGEN_EXCLUDE */
#define NIFLEXRIO_MAX_ERROR_SIZE (4096)
/** @endcond */

/** @ingroup defines
 * <details>resourceid:flexrio-integrated-io-c-api-ref_defines_flexriostatus</details>
 * Reports the status of this operation. To obtain a text description of the status code, call @ref niFlexRIO_GetError.
 * The general meaning of the status code is as follows:
 * 
 * | Value | Meaning |
 * |-------|---------|
 * | 0     | Success |
 * | Positive values | Warnings |
 * | Negative values | Errors |
 */
typedef int32_t FlexRIO_Status;
/** @ingroup defines
 * <details>resourceid:flexrio-integrated-io-c-api-ref_defines_flexriorouteticket</details>
*/
typedef uint32_t FlexRIO_RouteTicket;




#ifdef __cplusplus
extern "C" {
#endif

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioopensession</details>
 *
 * Opens a session to the FlexRIO device using a specified bitfile and creates an NiFpga session
 * reference that you can use to identify this session in subsequent FlexRIO API function calls.
 *
 * @param[in] resourceName Specifies the resource name of the FlexRIO device.
 * @param[in] bitfile      Specifies the FPGA image to load to the FPGA.
 * @param[in] flags        Specifies additional NiFpga session attributes. Set this value to 0 or
 *                         bitwise OR of any of the NiFpga_OpenAttributes.
 * @param[out] newSession  Outputs the NiFpga session reference. Destroy this session reference by
 *                         calling niFlexRIO_CloseSession when the session is no longer needed.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_OpenSession(const char* const resourceName, const char* bitfile, int32_t flags,
                      NiFpga_Session* newSession);

#define niFlexRIO_OpenDefaultBitfile(resourceName, flags, newSession)    niFlexRIO_OpenSession(resourceName, NULL, flags, newSession)

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioclosesession</details>
 *
 * Closes the NiFpga session, destroys the session reference, and deallocates resources associated
 * with the session. Call this function once for each unique named session that you have created.
 *
 * @param[in] session Specifies the reference to the currently open NiFpga session.
 * @param[in] flags   Specifies additional NiFpga session attributes. Set this value to 0 or bitwise
 *                    OR of any of the NiFpga_CloseAttributes.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_CloseSession(NiFpga_Session session, int32_t flags);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriowaitforioready</details>
 *
 * Pauses execution until the FlexRIO module I/O is ready.
 *
 * @param[in] session     Specifies the reference to the currently open NiFpga session.
 * @param[in] timeoutInMs Specifies a time limit in milliseconds.
 * @param[out] ioReady    Indicates that the I/O is ready.
 * @param[out] ioError    Outputs error codes that indicate why the I/O module is not ready. You can
 *                        retrieve a description for an error code by passing the error code to
 *                        niFlexRIO_GetError.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_WaitForIoReady(NiFpga_Session session, int32_t timeoutInMs, uint32_t* ioReady,
                         int32_t* ioError);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioconfigureforreferenceclock</details>
 *
 * Configures the Reference Clock source. You can use this function to set the onboard clock, the
 * PXI backplane clock, or an external clock as the Reference Clock.
 *
 * @param[in] session              Specifies the reference to the currently open NiFpga session.
 * @param[in] referenceClockSource Specifies the Reference Clock source. <table> <tr> <th>Defined
 *                                 values</th> <th></th> </tr> <tr> <td>Onboard (1)</td>
 *                                 <td>Specifies the onboard Reference Clock.</td> </tr> <tr>
 *                                 <td>PXI_Clk10 (2)</td> <td>Specifies a PXI backplane clock.</td>
 *                                 </tr> <tr> <td>External (3)</td> <td>Specifies an external
 *                                 Reference Clock.</td> </tr> </table>
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ConfigureForReferenceClock(NiFpga_Session session,
                                     FlexRIO_RefClkSrc referenceClockSource);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioconfigureforexternalclock</details>
 *
 * Configures external clock source and frequency.
 *
 * @param[in] session     Specifies the reference to the currently open NiFpga session.
 * @param[in] clockSource Identifies the source of the external Sample Clock.
 * @param[in] frequency   Specifies the frequency of the external Sample Clock.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ConfigureForExternalClock(NiFpga_Session session, FlexRIO_ExtClkSrc clockSource,
                                    double frequency);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioconfigurestreamenabledchannels</details>
 *
 * Configures which channels are enabled for a specified stream.
 *
 * @param[in] session         Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance  Identifies an instance of a stream.
 * @param[in] channelsEnabled Specifies the channels to enable for the specified stream.
 * @param[out] channelCount   Indicates the total number of channels parsed during execution of this
 *                            function.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ConfigureStreamEnabledChannels(NiFpga_Session session, int32_t streamInstance,
                                         const char* channelsEnabled, int32_t* channelCount);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioconfigurestreamfinite</details>
 *
 * Configures a stream to operate in a finite transfer bound by a specified number of samples.
 * Streams configured to operate in a finite transfer will autonomously stop after completing the
 * requested number of samples or in response to an error state.
 *
 * @param[in] session         Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance  Identifies an instance of a stream.
 * @param[in] numberOfSamples Specifies the maximum number of samples to transfer.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ConfigureStreamFinite(NiFpga_Session session, int32_t streamInstance,
                                uint64_t numberOfSamples);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriocommit</details>
 *
 * Commits attribute settings to the hardware.
 *
 * @param[in] session Specifies the reference to the currently open NiFpga session.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_Commit(NiFpga_Session session);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioclearstream</details>
 *
 * Clears samples from the stream.
 *
 * @param[in] session        Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance Identifies an instance of a stream.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ClearStream(NiFpga_Session session, int32_t streamInstance);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriostartstream</details>
 *
 * Activates a stream.
 *
 * @param[in] session        Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance Identifies an instance of a stream.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_StartStream(NiFpga_Session session, int32_t streamInstance);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriowaitfortransfer</details>
 *
 * Waits until a specified number of samples have been transferred.
 *
 * @param[in] session             Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance      Identifies an instance of a stream.
 * @param[in] waitForNSamples     Specifies the number of samples after the transfer of which
 *                                execution will resume.
 * @param[in] timeoutInMs         Specifies a time limit in milliseconds.
 * @param[out] samplesTransferred Indicates the actual number of samples transferred in the stream
 *                                including samples the host has not yet retrieved.
 * @param[out] state              Returns the state of the stream.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_WaitForTransfer(NiFpga_Session session, int32_t streamInstance, uint64_t waitForNSamples,
                          int32_t timeoutInMs, uint64_t* samplesTransferred, uint8_t* state);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioreadstreami16</details>
 *
 * Reads data from a specified stream.
 *
 * @param[in] session          Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance   Identifies an instance of a stream.
 * @param[in] timeoutInMs      Specifies a time limit in milliseconds.
 * @param[in] numberOfElements Specifies the number of elements to include in elementArray.
 * @param[out] elementArray    Outputs the data read from the stream.
 * @param[out] wfmInfo         Contains information about the waveform read from the stream.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ReadStreamI16(NiFpga_Session session, int32_t streamInstance, int32_t timeoutInMs,
                        size_t numberOfElements, int16_t* elementArray, FlexRIO_WfmInfo* wfmInfo);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioreadstreamf64</details>
 *
 * Reads data from a specified stream.
 *
 * @param[in] session          Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance   Identifies an instance of a stream.
 * @param[in] timeoutInMs      Specifies a time limit in milliseconds.
 * @param[in] numberOfElements Specifies the number of elements to include in elementArray.
 * @param[out] elementArray    Outputs the data read from the stream.
 * @param[out] wfmInfo         Contains information about the waveform read from the stream.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ReadStreamF64(NiFpga_Session session, int32_t streamInstance, int32_t timeoutInMs,
                        size_t numberOfElements, double* elementArray, FlexRIO_WfmInfo* wfmInfo);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioreadstream2di16</details>
 *
 * Reads data from a specified stream.
 *
 * @param[in] session          Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance   Identifies an instance of a stream.
 * @param[in] timeoutInMs      Specifies a time limit in milliseconds.
 * @param[in] numberOfWfms     Specifies the number of waveforms to output in elementArray.
 * @param[in] numberOfElements Specifies the number of elements to include in elementArray.
 * @param[out] elementArray    Outputs the data read from the stream.
 * @param[out] wfmInfoArray    Contains information about waveforms read from the stream.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ReadStream2DI16(NiFpga_Session session, int32_t streamInstance, int32_t timeoutInMs,
                          size_t numberOfWfms, size_t numberOfElements, int16_t* elementArray, FlexRIO_WfmInfo* wfmInfoArray);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioreadstream2df64</details>
 *
 * Reads data from a specified stream.
 *
 * @param[in] session          Specifies the reference to the currently open NiFpga session.
 * @param[in] streamInstance   Identifies an instance of a stream.
 * @param[in] timeoutInMs      Specifies a time limit in milliseconds.
 * @param[in] numberOfWfms     Specifies the number of waveforms to output in elementArray.
 * @param[in] numberOfElements Specifies the number of elements to include in elementArray.
 * @param[out] elementArray    Outputs the data read from the stream.
 * @param[out] wfmInfoArray    Contains information about waveforms read from the stream.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ReadStream2DF64(NiFpga_Session session, int32_t streamInstance, int32_t timeoutInMs,
                          size_t numberOfWfms, size_t numberOfElements, double* elementArray, FlexRIO_WfmInfo* wfmInfoArray);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioquerybitfileregister</details>
 *
 * Looks up a control or indicator on the VI diagram in the current session's bitfile and outputs
 * the offset of the register.
 *
 * @param[in] session Specifies the reference to the currently open NiFpga session.
 * @param[in] name    Specifies the name of control or indicator on the VI diagram to look up in the
 *                    current session's bitfile.
 * @param[in] type    Specifies the type of the queried item. Currently only kFlexRIO_AnyType is
 *                    supported.
 * @param[out] offset Outputs the offset of the requested register. This can be passed back to
 *                    NiFpga entry points for setting and getting values from controls and
 *                    indicators.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_QueryBitfileRegister(NiFpga_Session session, const char* name, uint32_t type,
                               uint32_t* offset);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioquerybitfilefifo</details>
 *
 * Looks up a FIFO on the VI diagram in the current session's bitfile and outputs the offset of the
 * register.
 *
 * @param[in] session Specifies the reference to the currently open NiFpga session.
 * @param[in] name    Specifies the name of the FIFO on the VI diagram to look up in the current
 *                    session's bitfile.
 * @param[in] type    Specifies the type of the queried item. Currently only kFlexRIO_AnyType is
 *                    supported.
 * @param[out] offset Outputs the offset of the requested register. This can be passed back to
 *                    NiFpga entry points for interacting with FPGA FIFOs.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_QueryBitfileFifo(NiFpga_Session session, const char* name, uint32_t type,
                           uint32_t* offset);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriosetattributestring</details>
 *
 * Sets the value of a string attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[in] value              Specifies the value to which to set the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_SetAttributeString(NiFpga_Session session, const char* repeatedCapability,
                             FlexRIO_AttributeString attrID, const char* value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogetattributestring</details>
 *
 * Queries the value of a string attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[in] bufferSize         Specifies the string buffer size.
 * @param[out] value             Indicates the value of the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetAttributeString(NiFpga_Session session, const char* repeatedCapability,
                             FlexRIO_AttributeString attrID, size_t bufferSize, char* value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogetattributeint32</details>
 *
 * Queries the value of a 32-bit integer attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[out] value             Indicates the value of the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetAttributeInt32(NiFpga_Session session, const char* repeatedCapability,
                            FlexRIO_AttributeInt32 attrID, int32_t* value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriosetattributeint32</details>
 *
 * Sets the value of a 32-bit integer attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[in] value              Specifies the value to which to set the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_SetAttributeInt32(NiFpga_Session session, const char* repeatedCapability,
                            FlexRIO_AttributeInt32 attrID, int32_t value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogetattributeuint64</details>
 *
 * Queries the value of a 64-bit unsigned integer attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[out] value             Indicates the value of the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetAttributeUInt64(NiFpga_Session session, const char* repeatedCapability,
                             FlexRIO_AttributeUInt64 attrID, uint64_t* value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriosetattributeuint64</details>
 *
 * Sets the value of a 64-bit unsigned integer attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[in] value              Specifies the value to which to set the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_SetAttributeUInt64(NiFpga_Session session, const char* repeatedCapability,
                             FlexRIO_AttributeUInt64 attrID, uint64_t value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogetattributedouble</details>
 *
 * Queries the value of a double attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[out] value             Indicates the value of the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetAttributeDouble(NiFpga_Session session, const char* repeatedCapability,
                             FlexRIO_AttributeDouble attrID, double* value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriosetattributedouble</details>
 *
 * Sets the value of a double attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[in] value              Specifies the value to which to set the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_SetAttributeDouble(NiFpga_Session session, const char* repeatedCapability,
                             FlexRIO_AttributeDouble attrID, double value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogetattributeboolean</details>
 *
 * Queries the value of a Boolean attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[out] value             Indicates the value of the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetAttributeBoolean(NiFpga_Session session, const char* repeatedCapability,
                              FlexRIO_AttributeBool attrID, uint32_t* value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriosetattributeboolean</details>
 *
 * Sets the value of a Boolean attribute.
 *
 * @param[in] session            Specifies the reference to the currently open NiFpga session.
 * @param[in] repeatedCapability Specifies a repeated capability. If attrID is based on a repeated
 *                               capability, pass a repeated capability identifier. If attrID is not
 *                               based on a repeated capability, pass NULL or an empty string.
 * @param[in] attrID             Specifies an attribute.
 * @param[in] value              Specifies the value to which to set the attribute.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_SetAttributeBoolean(NiFpga_Session session, const char* repeatedCapability,
                              FlexRIO_AttributeBool attrID, uint32_t value);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioroutesignal</details>
 *
 * Routes a signal from a specified source to a specified destination and creates a route ticket
 * that identifies the route.
 *
 * @param[in] session      Specifies the reference to the currently open NiFpga session.
 * @param[in] source       Specifies the source of the signal to route.
 * @param[in] destination  Specifies the destination to which to route the signal.
 * @param[out] routeTicket Identifies a signal route.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_RouteSignal(NiFpga_Session session, const char* source, const char* destination,
                      FlexRIO_RouteTicket* routeTicket);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriounroutesignal</details>
 *
 * Unroutes a signal specified by a route ticket.
 *
 * @param[in] session     Specifies the reference to the currently open NiFpga session.
 * @param[in] routeTicket Identifies a signal route. The route ticket originates from
 *                        niFlexRIO_RouteSignal.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_UnrouteSignal(NiFpga_Session session, FlexRIO_RouteTicket routeTicket);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioconfiguredigitalstarttrigger</details>
 *
 * Configures the Start trigger for digital edge triggering.
 *
 * @param[in] session       Specifies the reference to the currently open NiFpga session.
 * @param[in] instance      Specifies an instance of a trigger.
 * @param[in] triggerSource Specifies the trigger source.
 * @param[in] sensitivity   Specifies digital trigger conditions. <table> <tr> <th>Defined
 *                          values</th> <th></th> <th></th> </tr> <tr> <td>2147483647</td>
 *                          <td>Rising Edge</td> <td>Trigger is active on a transition from low to
 *                          high.</td> </tr> <tr> <td>2147483646</td> <td>Falling Edge</td>
 *                          <td>Trigger is active on a transition from high to low.</td> </tr> <tr>
 *                          <td>2147483645</td> <td>High Level</td> <td>Trigger is active on a high-
 *                          level input.</td> </tr> <tr> <td>2147483644</td> <td>Low Level</td>
 *                          <td>Trigger is active on a low-level input.</td> </tr> </table>
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ConfigureDigitalStartTrigger(NiFpga_Session session, uint32_t instance,
                                       const char* triggerSource,
                                       FlexRIO_TriggerSensitivity sensitivity);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioconfigureimmediatetrigger</details>
 *
 * Configures the device to trigger itself immediately and independently of external signals.
 *
 * @param[in] session  Specifies the reference to the currently open NiFpga session.
 * @param[in] instance Specifies an instance of a trigger.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ConfigureImmediateTrigger(NiFpga_Session session, uint32_t instance);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioconfigureanalogedgetrigger</details>
 *
 * Configures the Start trigger for analog edge triggering.
 *
 * @param[in] session    Specifies the reference to the currently open NiFpga session.
 * @param[in] instance   Specifies an instance of a trigger.
 * @param[in] channel    Specifies the channel to monitor for trigger conditions.
 * @param[in] rising     Specifies whether to trigger on a rising edge. If this value is false, the
 *                       device will trigger on a falling edge.
 * @param[in] level      Specifies the trigger level in volts.
 * @param[in] hysteresis Specifies the size of the hysteresis window on either side of level in
 *                       volts.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ConfigureAnalogEdgeTrigger(NiFpga_Session session, uint32_t instance, const char* channel,
                                     uint32_t rising, double level, double hysteresis);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriowritecalibrationdata</details>
 *
 * Writes calibration data to the FlexRIO device's on-board flash memory. You can find the available
 * calibration storage by retrieving the value of kFlexRIO_CalibrationStorageSize.
 *
 * @param[in] session Specifies the reference to the currently open NiFpga session.
 * @param[in] offset  Specifies the byte address in the device's flash memory at which to begin the
 *                    operation.
 * @param[in] data    Specifies the data to write to the device's flash memory.
 * @param[in] size    Defines the number of bytes to read from the device's flash memory.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_WriteCalibrationData(NiFpga_Session session, uint32_t offset, const uint8_t *data,
                               size_t size);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioreadcalibrationdata</details>
 *
 * Reads calibration data from the FlexRIO device's on-board flash memory. You can find the
 * available calibration storage by retrieving the value of kFlexRIO_CalibrationStorageSize.
 *
 * @param[in] session Specifies the reference to the currently open NiFpga session.
 * @param[in] offset  Specifies the byte address in the device's flash memory at which to begin the
 *                    operation.
 * @param[in] size    Defines the number of bytes to read from the device's flash memory.
 * @param[out] data   Returns the data read from the device's flash memory.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ReadCalibrationData(NiFpga_Session session, uint32_t offset, uint8_t* data, size_t size);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogeterror</details>
 *
 * Provides descriptions of errors.
 *
 * @param[in] session           Specifies the reference to the currently open NiFpga session.
 * @param[in] errorIn           Specifies the error code returned by a FlexRIO API function.
 * @param[in] size              Specifies the size of the buffer for errorElaboration.
 * @param[out] errorElaboration Outputs the error description.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetError(NiFpga_Session session, FlexRIO_Status errorIn, size_t size, char* errorElaboration);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioupdateverificationinformation</details>
 *
 * Updates verification time and verification temperature fields in the device's flash memory to
 * current system time and device temperature, respectively.
 *
 * @param[in] session Specifies the reference to the currently open NiFpga session.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_UpdateVerificationInformation(NiFpga_Session session);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogetsessionreference</details>
 *
 * Outputs a session reference that you can use to identify this session in calls to the NI-TClk
 * API.
 *
 * @param[in] session           Specifies the reference to the currently open NiFpga session.
 * @param[out] sessionReference Identifies this session. Use this session reference in calls to the
 *                              NI-TClk API.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetSessionReference(NiFpga_Session session, ViSession* sessionReference);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioresetdspsynchronously</details>
 *
 * Asserts DSP Reset on the same rising edge of TClk across all sessions.
 *
 * @param[in] sessions          Specifies an array of sessions to reset.
 * @param[in] numberOfSessions  Specifies the number of sessions in the sessions array.
 * @param[in] instance          Specifies the DSP Reset instance to reset.
 * @param[in] size              Specifies the size of the buffer for errorElaboration.
 * @param[out] errorElaboration Outputs the error description.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ResetDspSynchronously(NiFpga_Session* sessions, size_t numberOfSessions,
                                int32_t instance, size_t size, char* errorElaboration);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioupdatefirmware</details>
 *
 * TODO: add documentation for niFlexRIO_UpdateFirmware
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_UpdateFirmware(const char *resource, const char * modelName, size_t size, const uint8_t *firmware, uint8_t alwaysOverwrite);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriogetfirmwareupdateprogress</details>
 *
 * TODO: add documentation for niFlexRIO_GetFirmwareUpdateProgress
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_GetFirmwareUpdateProgress(const char *resource, uint32_t *progress, uint8_t *isUpdateInProgress, uint8_t *updateFailed);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioqsfpwrite</details>
 *

 *
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_QSFPWrite(NiFpga_Session session, uint8_t port, uint8_t address, uint8_t data);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioqsfpread</details>
 *

 *
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_QSFPRead(NiFpga_Session session, uint8_t port, uint8_t address, uint8_t* data);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioqsfpresetports</details>
 *

 *
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_QSFPResetPorts(NiFpga_Session session);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioqsfpenablelowpowermode</details>
 *

 *
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_QSFPEnableLowPowerMode(NiFpga_Session session, uint32_t enable);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioqsfpgetmodulepresent</details>
 *

 *
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_QSFPGetModulePresent(NiFpga_Session session, uint8_t port, uint32_t* modulePresent);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriostartcablesense</details>
 *

 *
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_StartCableSense(NiFpga_Session session);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriostopcablesense</details>
 *

 *
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_StopCableSense(NiFpga_Session session);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioreadi2c</details>
 *
 * Issues an I2C read to the specified I2C bus instance.
 *
 * @param[in] session         Specifies the reference to the currently open NiFpga session.
 * @param[in] busInstanceName Specifies the I2C bus instance to which the read should be issued.
 * @param[in] slaveAddress    Specifies the I2C slave address of the device to which the read should
 *                            be issued.
 * @param[out] data           returns the data read from the I2C bus.
 * @param[in] numBytesToRead  Specifies the number of bytes to be read.
 * @param[in] repeatedStart   When repeatedStart is true, the I2C master will not send a stop
 *                            condition at end of the I2C transaction.
 * @param[out] numBytesRead   Returns the number of bytes read.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ReadI2C(NiFpga_Session session, const char* busInstanceName, uint16_t slaveAddress, uint8_t* data,
                  size_t numBytesToRead, uint8_t repeatedStart, size_t* numBytesRead);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriowritei2c</details>
 *
 * Issues an I2C write to the specified I2C bus instance.
 *
 * @param[in] session          Specifies the reference to the currently open NiFpga session.
 * @param[in] busInstanceName  Specifies the I2C bus instance to which the read should be issued.
 * @param[in] slaveAddress     Specifies the I2C slave address of the device to which the read
 *                             should be issued.
 * @param[in] data             Specifies the data to write to the I2C bus.
 * @param[in] numBytesToWrite  Specifies the number of bytes to write to the stream.
 * @param[in] repeatedStart    When repeatedStart is true, the I2C master will not send a stop
 *                             condition at end of the I2C transaction.
 * @param[out] numBytesWritten Returns the number of bytes written.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_WriteI2C(NiFpga_Session session, const char* busInstanceName, uint16_t slaveAddress, const uint8_t* data,
                   size_t numBytesToWrite, uint8_t repeatedStart, size_t* numBytesWritten);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriotransferi2c</details>
 *
 * Issues an I2C write, without a stop condition, before issuing an I2C read.
 *
 * @param[in] session          Specifies the reference to the currently open NiFpga session.
 * @param[in] busInstanceName  Specifies the I2C bus instance to which the read should be issued.
 * @param[in] slaveAddress     Specifies the I2C slave address of the device to which the read
 *                             should be issued.
 * @param[in] writeData        Specifies the data to write to the I2C bus.
 * @param[in] numBytesToWrite  Specifies the number of bytes to write to the stream.
 * @param[out] readData        Returns the data read from the I2C bus.
 * @param[in] numBytesToRead   Specifies the number of bytes to be read.
 * @param[in] repeatedStart    When repeatedStart is true, the I2C master will not send a stop
 *                             condition at end of the I2C transaction.
 * @param[out] numBytesWritten Returns the number of bytes written.
 * @param[out] numBytesRead    Returns the number of bytes read.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_TransferI2C(NiFpga_Session session, const char* busInstanceName, uint16_t slaveAddress, const uint8_t* writeData,
                      size_t numBytesToWrite, uint8_t* readData, size_t numBytesToRead, uint8_t repeatedStart,
                      size_t* numBytesWritten, size_t* numBytesRead);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriosetuserautoloadflag</details>
 *
 * TODO: add documentation for niFlexRIO_SetUserAutoloadFlag
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_SetUserAutoloadFlag(NiFpga_Session session, uint32_t autoload);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriopromotesessiontouserimage</details>
 *
 * TODO: add documentation for niFlexRIO_PromoteSessionToUserImage
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_PromoteSessionToUserImage(NiFpga_Session session);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrioclearuserimage</details>
 *
 * TODO: add documentation for niFlexRIO_ClearUserImage
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_ClearUserImage(NiFpga_Session session);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrio6569configuretxclocks</details>
 *
 * TODO: add documentation for niFlexRIO_6569_ConfigureTXClocks
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_6569_ConfigureTXClocks(NiFpga_Session session, FlexRIO_NI6569_TXClockSource clockSource, double frequency);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrio6569configurerxclocks</details>
 *
 * TODO: add documentation for niFlexRIO_6569_ConfigureRXClocks
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_6569_ConfigureRXClocks(NiFpga_Session session, FlexRIO_NI6569_RXClockSource clockSource, FlexRIO_NI6569_Bank bank);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexrio6569getrxclockconfiguration</details>
 *
 * TODO: add documentation for niFlexRIO_6569_GetRXClockConfiguration
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_6569_GetRXClockConfiguration(NiFpga_Session session, FlexRIO_NI6569_RXClockSource* clockSource, FlexRIO_NI6569_Bank bank);

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_functions_niflexriowaitforpocsafetodisconnect</details>
 *
 * Waits and blocks until specified channels with power-over-coax are safe to disconnect.
 *
 * @param[in] session             Specifies the reference to the currently open NiFpga session.
 * @param[in] channels            Specifies the channels to wait until safe to disconnect.
 * @param[in] timeoutInMs         Specifies a time limit in milliseconds to wait until safe to
 *                                disconnect. A value of -1 indicates to wait indefinitely
 * @param[in] bufferSize          Specifies the string buffer size for the timed out channels.
 * @param[out] channelsTimedOutIn Indicates which channels failed to deenergize.
 * @returns @ref FlexRIO_Status
 */
FlexRIO_Status
_NIFLEXRIOAPI_EXPORT
niFlexRIO_WaitForPoCSafeToDisconnect(NiFpga_Session session, const char* channels, int32_t timeoutInMs, size_t bufferSize, char* channelsTimedOutIn);

#ifdef __cplusplus
}
#endif

#endif /* __niflexrioapi_h__ */

/**
* @}
*/
