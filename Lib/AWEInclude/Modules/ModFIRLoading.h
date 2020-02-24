/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModFIRLoading.h
****************************************************************************
*
*     Description:  Simulates loading of fir filter
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
 * @brief Simulates loading of fir filter
 */

#ifndef _MOD_FIRLOADING_H
#define _MOD_FIRLOADING_H

#include "ModCommon.h"
#include "MathHelper.h"
#include "ModFIR.h"

#define MASK_FIRLoading_maxTaps 0x00000100
#define MASK_FIRLoading_numTaps 0x00000200
#define OFFSET_FIRLoading_maxTaps 0x00000008
#define OFFSET_FIRLoading_numTaps 0x00000009

#define CLASSID_FIRLOADING (CLASS_ID_MODBASE + 1276)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modFIRLoadingInstance
{
    ModuleInstanceDescriptor instance;
    INT32              maxTaps;             // Maximum FIR filter taps that can be run
    INT32              numTaps;             // Number of FIR filter taps currently running
        awe_modFIRInstance    *filt;               // FIR filter
} awe_modFIRLoadingInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modFIRLoadingClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
ModInstanceDescriptor * awe_modFIRLoadingConstructor(INT32 * FW_RESTRICT retVal, UINT32 nIO, WireInstance ** FW_RESTRICT pWires, size_t argCount, const Sample * FW_RESTRICT args);
#endif // #ifndef AWE_STATIC_CODE


void awe_modFIRLoadingProcess(void *pInstance);

UINT32 awe_modFIRLoadingSet(void *pInstance, UINT32 mask);
 



#ifdef __cplusplus
}
#endif


#endif // _MOD_FIRLOADING_H

/**
 * @}
 *
 * End of file.
 */
