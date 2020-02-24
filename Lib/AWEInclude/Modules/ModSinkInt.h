/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModSinkInt.h
****************************************************************************
*
*     Description:  Copies the data at the input pin and stores it in an internal buffer
*
*     Copyright:    DSP Concepts, Inc, 2007 - 2017
*                   1800 Wyatt Drive, Suite 14
*                   Santa Clara, CA 95054
*
***************************************************************************/

/**
 * @addtogroup Modules
 * @{
 */

/**
 * @file
 * @brief Copies the data at the input pin and stores it in an internal buffer
 */

#ifndef _MOD_SINKINT_H
#define _MOD_SINKINT_H

#include "ModCommon.h"
#include "MathHelper.h"

#define MASK_SinkInt_value 0x00000100
#define OFFSET_SinkInt_value 0x00000008

#define CLASSID_SINKINT (CLASS_ID_MODBASE + 110)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modSinkIntInstance
{
    ModuleInstanceDescriptor instance;
    
    INT32*             value;               // Captured values
} awe_modSinkIntInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modSinkIntClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
ModInstanceDescriptor * awe_modSinkIntConstructor(INT32 * FW_RESTRICT retVal, UINT32 nIO, WireInstance ** FW_RESTRICT pWires, size_t argCount, const Sample * FW_RESTRICT args);
#endif // #ifndef AWE_STATIC_CODE


void awe_modSinkIntProcess(void *pInstance);

 



#ifdef __cplusplus
}
#endif


#endif // _MOD_SINKINT_H

/**
 * @}
 *
 * End of file.
 */
