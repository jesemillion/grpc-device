#ifndef __niflexrioapi_wfminfo_h__
#define __niflexrioapi_wfminfo_h__

/** @ingroup defines
 *
 *  @brief This structure is used by stream read endpoints to return additional information
 *  about the waveform.
 *
 * <details>resourceid:flexrio-integrated-io-c-api-ref_defines_flexriowfminfo</details>
 *
 *  The API is capable of returning less data than requested for a variety of reasons.
 *  The actualNumSamples will reflect the amount written to the user's buffer for
 *  this waveform.  However, if the function returns any error other than a timeout,
 *  this field may not contain the correct information.
 *
 *  In the event of a timeout, all fields that can be filled out shall be.
 *
 *  The timestamps absoluteInitialX will be 0 in situations where it is unsupported.
 *  Otherwise, the value will be a time offset to the first sample in this read that
 *  is how far that sample is in time from an arbitrary starting point.  This can be
 *  used to compare times across different streaming acquisitions, as long as the
 *  timing source is maintained (ie: the clock isn't reconfigured).
 *
 *  There are two absoluteInitialX values (upper and lower).  The actual time is the
 *  sum of these two values.  However, because of the precision in doubles (about
 *  15 significant decimal digits), one double can't contain enough information
 *  to convey this information over a long period of time.  This method is chosen
 *  to ensure portability to all programming environments.
 *
 *  The timestamp relativeInitialX will be 0 in situations where it is unsupported.
 *  Otherwise, the value will be a time offset to the first sample in this read that
 *  is how far that sample is in time from the reference point.  The reference point
 *  is typically the start of this waveform.  The relativeInitialX has the same
 *  limitations as absoluteInitialX in that the precision can roll off, however since
 *  it is always relative to the trigger event, it is uncommon for this to matter
 *  in practice.
 *
 *  In practice, relativeInitialX is supported in all cases.  But if it were not,
 *  the value shall be zero.
 *
 *  If dt   == 0, then the driver does not know the dt.
 *  If gain == 0, then the driver does not know the gain (and offset).
 *
 *  For integer output data, the scaling coefficients to transform binary data into
 *  scaled data (typically volts), are indicated as
 *  data_in_volts = (data[i] * gain) + offset;
 *
 *  For floating point data, the scaling coefficients are still the same, but they
 *  can be used in reverse to recover the unscaled data.
 *
 *  Do not reference the reserved fields.  If they become used some day, then the
 *  name will change to reflect that and your code will no longer compile.
 */
typedef struct 
{
   double   absoluteInitialXUpper; /**< Difference in seconds from an arbitrary starting point */
   double   absoluteInitialXLower; /**< Residual difference in seconds from absoluteInitialXUpper */
   double   relativeInitialX;      /**< Difference in seconds from the trigger position */
   double   dt;                    /**< Difference in seconds between samples */
   double   gain;                  /**< Difference in volts between adjacent elements */
   double   offset;                /**< Difference in volts between the scaled waveform value '0' and zero volts */
   double   reserved1;             /**< Reserved for future use. */
   double   reserved2;             /**< Reserved for future future use. */
   uint64_t actualNumSamples;      /**< Indicates the number of samples stored in this waveform */
   uint64_t reserved3;             /**< Reserved for future use. */
} FlexRIO_WfmInfo;

#endif /* __niflexrioapi_wfminfo_h__ */
