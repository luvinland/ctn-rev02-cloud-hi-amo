/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModInvert.h
****************************************************************************
*
*     Description:  Phase invert module
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
 * @brief Phase invert module
 */

#ifndef _MOD_INVERT_H
#define _MOD_INVERT_H

#include "ModCommon.h"
#include "MathHelper.h"

#define MASK_Invert_isInverted 0x00000100
#define MASK_Invert_smoothingTime 0x00000200
#define MASK_Invert_currentGain 0x00000400
#define MASK_Invert_smoothingCoeff 0x00000800
#define OFFSET_Invert_isInverted 0x00000008
#define OFFSET_Invert_smoothingTime 0x00000009
#define OFFSET_Invert_currentGain 0x0000000A
#define OFFSET_Invert_smoothingCoeff 0x0000000B

#define CLASSID_INVERT (CLASS_ID_MODBASE + 21)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modInvertInstance
{
    ModuleInstanceDescriptor instance;
    INT32              isInverted;          // Boolean that specifies whether the signal is inverted (=1) or not (=0).
    FLOAT32            smoothingTime;       // Time constant of the smoothing process.
    FLOAT32            currentGain;         // Instantaneous gain applied by the module. This is also the starting gain of the module.
    FLOAT32            smoothingCoeff;      // Smoothing coefficient.
    
} awe_modInvertInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modInvertClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
// This points the constructor for this class to the base constructor
#define awe_modInvertConstructor(ARG1, ARG2, ARG3, ARG4, ARG5) ClassModule_Constructor(CLASSID_INVERT, ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // #ifndef AWE_STATIC_CODE


void awe_modInvertProcess(void *pInstance);

UINT32 awe_modInvertSet(void *pInstance, UINT32 mask);
 



#ifdef __cplusplus
}
#endif


#endif // _MOD_INVERT_H

/**
 * @}
 *
 * End of file.
 */