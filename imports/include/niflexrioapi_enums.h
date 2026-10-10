/** @defgroup enums NI FlexRIO C Enums
 *  @ingroup root_niflexrioapi
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums</details>
 * @{
 */



#ifndef __niflexrioapi_enums_h__
#define __niflexrioapi_enums_h__

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriosopocsink</details>
 */
typedef enum {
   kFlexRIO_SoPoCSink_None        = 0,  /**< Power over Coax None */
   kFlexRIO_SoPoCSink_Auxiliary   = 2,  /**< Power over Coax Auxiliary */
} FlexRIO_SoPoCSink;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriotriggersensitivity</details>
 */
typedef enum {
   kFlexRIO_TriggerSensitivity_RisingEdge = 2147483647,  /**< Trigger is active on a transition from low to high */
   kFlexRIO_TriggerSensitivity_FallingEdge = 2147483646,  /**< Trigger is active on a transition from high to low */
   kFlexRIO_TriggerSensitivity_HighLevel = 2147483645,  /**< Trigger is active on a high-level input */
   kFlexRIO_TriggerSensitivity_LowLevel = 2147483644,  /**< Trigger is active on a low-level input */
} FlexRIO_TriggerSensitivity;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexrioni6569bank</details>
 */
typedef enum {
   kFlexRIO_NI6569_Bank_Bank44    = 0,  /**< Bank 44 */
   kFlexRIO_NI6569_Bank_Bank45    = 1,  /**< Bank 45 */
   kFlexRIO_NI6569_Bank_Bank46    = 2,  /**< Bank 46 */
   kFlexRIO_NI6569_Bank_AllBanks  = 2147483647,  /**< All Banks */
} FlexRIO_NI6569_Bank;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriostarttriggersync</details>
 */
typedef enum {
   kFlexRIO_StartTriggerSync_Disabled = 0,  /**< Start trigger synchronizers disabled. */
   kFlexRIO_StartTriggerSync_Master = 1,  /**< Start trigger synchronizers configured for being a TClk master. */
   kFlexRIO_StartTriggerSync_Slave = 2,  /**< Start trigger synchronizers configured for being a TClk slave. */
} FlexRIO_StartTriggerSync;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexrioiomodulerefclkpinsrc</details>
 */
typedef enum {
   kFlexRIO_IoModuleRefClkPinSrc_Disabled = 0,  /**< Disabled */
   kFlexRIO_IoModuleRefClkPinSrc_PXI_Clk10 = 1,  /**< Backplane 10MHz clock */
   kFlexRIO_IoModuleRefClkPinSrc_PXIe_Clk100 = 2,  /**< Backplane 100MHz clock */
} FlexRIO_IoModuleRefClkPinSrc;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriostreamdataformat</details>
 */
typedef enum {
   kFlexRIO_StreamDataFormat_Interleaved = 0,  /**< Indicates that data from all channels is interleaved and transferred via a single FIFO. */
   kFlexRIO_StreamDataFormat_FifoPerChannel = 1,  /**< Indicates that each channel has its own associated FIFO through which data is transferred. */
} FlexRIO_StreamDataFormat;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriocsi2numlanes</details>
 */
typedef enum {
   kFlexRIO_Csi2NumLanes_1        = 1,  /**< 1 Lane */
   kFlexRIO_Csi2NumLanes_2        = 2,  /**< 2 Lanes */
   kFlexRIO_Csi2NumLanes_4        = 4,  /**< 4 Lanes */
} FlexRIO_Csi2NumLanes;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriobaseboardrefclksrc</details>
 */
typedef enum {
   kFlexRIO_BaseboardRefClkSrc_Onboard = 0,  /**< Onboard reference clock. */
   kFlexRIO_BaseboardRefClkSrc_SynchronizationConnector = 1,  /**< Reference clock sourced from the FlexRIO synchronization connector. */
} FlexRIO_BaseboardRefClkSrc;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriosipocsource</details>
 */
typedef enum {
   kFlexRIO_SiPoCSource_None      = 0,  /**< Power over Coax None */
   kFlexRIO_SiPoCSource_Internal  = 1,  /**< Power over Coax Internal */
   kFlexRIO_SiPoCSource_Auxiliary = 2,  /**< Power over Coax Auxiliary */
} FlexRIO_SiPoCSource;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriosampleclksrc</details>
 */
typedef enum {
   kFlexRIO_SampleClkSrc_Internal = 0,  /**< Internally generated sample clock */
   kFlexRIO_SampleClkSrc_FrontPanel = 1,  /**< External clock terminal on the front panel */
} FlexRIO_SampleClkSrc;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriocablesensemode</details>
 */
typedef enum {
   kFlexRIO_CableSenseMode_Disabled = 0,  /**< CableSense Disabled */
   kFlexRIO_CableSenseMode_OnDemand = 1,  /**< CableSense On Demand */
} FlexRIO_CableSenseMode;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriocoupling</details>
 */
typedef enum {
   kFlexRIO_Coupling_Ac           = 0, 
   kFlexRIO_Coupling_Dc           = 1, 
} FlexRIO_Coupling;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriobustype</details>
 */
typedef enum {
   kFlexRIO_BusType_PXIe          = 0,  /**< PXI Express */
   kFlexRIO_BusType_PCIe          = 1,  /**< PCI Express */
} FlexRIO_BusType;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriodiffpficonfiguration</details>
 */
typedef enum {
   kFlexRIO_DiffPfiConfiguration_Input = 0,  /**< Input Mode */
   kFlexRIO_DiffPfiConfiguration_Output = 1,  /**< Output Mode */
} FlexRIO_DiffPfiConfiguration;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriorefclksrc</details>
 */
typedef enum {
   kFlexRIO_RefClkSrc_Default     = 0,  /**< Default for the board */
   kFlexRIO_RefClkSrc_Onboard     = 1,  /**< Onboard reference clock */
   kFlexRIO_RefClkSrc_PXI_Clk10   = 2,  /**< 10 MHz Backplane clock */
   kFlexRIO_RefClkSrc_External    = 3,  /**< External reference source */
   kFlexRIO_RefClkSrc_None        = 4,  /**< No reference clock */
   kFlexRIO_RefClkSrc_BaseboardReference = 5,  /**< Reference clock provided by the baseboard. The baseboard's reference can be controlled using the Baseboard Reference Clock Source attribute. */
   kFlexRIO_RefClkSrc_PXI_Clk100  = 6,  /**< 100 MHz Backplane clock */
} FlexRIO_RefClkSrc;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexrioextclksrc</details>
 */
typedef enum {
   kFlexRIO_ExtClkSrc_FrontPanel  = 0,  /**< External clock terminal on the front panel */
} FlexRIO_ExtClkSrc;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexrioni6569txclocksource</details>
 */
typedef enum {
   kFlexRIO_NI6569_TXClockSource_Lmk = 0,  /**< LMK04832 */
   kFlexRIO_NI6569_TXClockSource_Si514 = 2,  /**< Si514 */
} FlexRIO_NI6569_TXClockSource;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriodacdigitalupconvertermode</details>
 */
typedef enum {
   kFlexRIO_DacDigitalUpconverterMode_Disabled = 0,  /**< Upconverter disabled */
   kFlexRIO_DacDigitalUpconverterMode_EnabledAo0 = 1,  /**< Enabled AO 0 */
   kFlexRIO_DacDigitalUpconverterMode_EnabledAo1 = 2,  /**< Enabled AO 1 */
   kFlexRIO_DacDigitalUpconverterMode_EnabledAo0Ao1 = 3,  /**< Enabled AO 0 and AO 1 */
} FlexRIO_DacDigitalUpconverterMode;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriodioconfiguration</details>
 */
typedef enum {
   kFlexRIO_DioConfiguration_Input = 0,  /**< Input Mode */
   kFlexRIO_DioConfiguration_Output = 1,  /**< Output Mode */
} FlexRIO_DioConfiguration;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriopficonfiguration</details>
 */
typedef enum {
   kFlexRIO_PfiConfiguration_Input = 0,  /**< Input Mode */
   kFlexRIO_PfiConfiguration_Output = 1,  /**< Output Mode */
} FlexRIO_PfiConfiguration;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexrioaochannelstatus</details>
 */
typedef enum {
   kFlexRIO_AoChannelStatus_Normal = 0,  /**< Channel is in normal state */
   kFlexRIO_AoChannelStatus_Overpower = 1,  /**< Channel is shut down due to excessive power consumption */
   kFlexRIO_AoChannelStatus_Overtemperature = 2,  /**< Channel is shut down due to excessive temperature */
} FlexRIO_AoChannelStatus;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexrioni6569rxclocksource</details>
 */
typedef enum {
   kFlexRIO_NI6569_RXClockSource_ExternalClock = 0,  /**< External Clock */
   kFlexRIO_NI6569_RXClockSource_TxClock = 1,  /**< Transmit Clock */
} FlexRIO_NI6569_RXClockSource;

/**
 * <details>resourceid:flexrio-integrated-io-c-api-ref_enums_flexriotriggertype</details>
 */
typedef enum {
   kFlexRIO_TriggerType_Immediate = 0,  /**< Specifies an immediate trigger */
   kFlexRIO_TriggerType_Digital   = 1,  /**< Specifies a digital trigger */
   kFlexRIO_TriggerType_User      = 2,  /**< Specifies a user-defined trigger */
   kFlexRIO_TriggerType_Dio       = 3,  /**< Specifies a DIO trigger */
   kFlexRIO_TriggerType_Analog    = 4,  /**< Specifies an analog trigger */
   kFlexRIO_TriggerType_ExternalAnalog = 5,  /**< Specifies an external analog trigger */
} FlexRIO_TriggerType;


#endif /* __niflexrioapi_enums_h__ */

/**
* @}
*/