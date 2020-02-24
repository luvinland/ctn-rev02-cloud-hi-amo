/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModScalerControlBlockSmoothedFract32.h
****************************************************************************
*
*     Description:  Linear multichannel smoothly varying scaler with control pin
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
 * @brief Linear multichannel smoothly varying scaler with control pin
 */

#ifndef _MOD_SCALERCONTROLBLOCKSMOOTHEDFRACT32_H
#define _MOD_SCALERCONTROLBLOCKSMOOTHEDFRACT32_H

#include "ModCommon.h"
#include "MathHelper.h"

#define MASK_ScalerControlBlockSmoothedFract32_smoothingTime 0x00000100
#define MASK_ScalerControlBlockSmoothedFract32_dataType 0x00000200
#define MASK_ScalerControlBlockSmoothedFract32_currentGain 0x00000400
#define MASK_ScalerControlBlockSmoothedFract32_smoothingCoeff 0x00000800
#define OFFSET_ScalerControlBlockSmoothedFract32_smoothingTime 0x00000008
#define OFFSET_ScalerControlBlockSmoothedFract32_dataType 0x00000009
#define OFFSET_ScalerControlBlockSmoothedFract32_currentGain 0x0000000A
#define OFFSET_ScalerControlBlockSmoothedFract32_smoothingCoeff 0x0000000B

#define CLASSID_SCALERCONTROLBLOCKSMOOTHEDFRACT32 (CLASS_ID_MODBASE + 181)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modScalerControlBlockSmoothedFract32Instance
{
    ModuleInstanceDescriptor instance;
    FLOAT32            smoothingTime;       // Time constant of the smoothing process
    INT32              dataType;            // Specifies data type at input control pin (0=Q9.31, 1=float)
    fract32            currentGain;         // Instantaneous gain applied by the module.  This is also the starting gain of the module.
    fract32            smoothingCoeff;      // Smoothing coefficient
    
} awe_modScalerControlBlockSmoothedFract32Instance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modScalerControlBlockSmoothedFract32Class;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
// This points the constructor for this class to the base constructor
#define awe_modScalerControlBlockSmoothedFract32Constructor(ARG1, ARG2, ARG3, ARG4, ARG5) ClassModule_Constructor(CLASSID_SCALERCONTROLBLOCKSMOOTHEDFRACT32, ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // #ifndef AWE_STATIC_CODE


void awe_modScalerControlBlockSmoothedFract32Process(void *pInstance);

UINT32 awe_modScalerControlBlockSmoothedFract32Set(void *pInstance, UINT32 mask);
 

void awe_modScalerControlBlockSmoothedFract32Bypass(void *pInstance);


#ifdef __cplusplus
}
#endif


#endif // _MOD_SCALERCONTROLBLOCKSMOOTHEDFRACT32_H

/**
 * @}
 *
 * End of file.
 */
