#ifndef __niflexrioapi_i2cbusinstancename_h__
#define __niflexrioapi_i2cbusinstancename_h__

/* FlexRIO_I2CBusInstanceName
   This structure is used by I2C functions to describe the bus instance.
 */

/** @cond DOXYGEN_EXCLUDE */
#define NIFLEXRIO_I2C_BUS_INSTANCE_NAME_SIZE 16

typedef struct
{
   char buffer[NIFLEXRIO_I2C_BUS_INSTANCE_NAME_SIZE];
} FlexRIO_I2CBusInstanceName;
/** @endcond */

#endif /* __niflexrioapi_i2cbusinstancename_h__ */
