/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModUndb10Fract32.h
****************************************************************************
*
*     Description:  Computes the undb10 using fixed-point math.
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
 * @brief Computes the undb10 using fixed-point math.
 */

#ifndef _MOD_UNDB10FRACT32_H
#define _MOD_UNDB10FRACT32_H

#include "ModCommon.h"
#include "MathHelper.h"


#define CLASSID_UNDB10FRACT32 (CLASS_ID_MODBASE + 212)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modUndb10Fract32Instance
{
    ModuleInstanceDescriptor instance;
    
    
} awe_modUndb10Fract32Instance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modUndb10Fract32Class;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
// This points the constructor for this class to the base constructor
#define awe_modUndb10Fract32Constructor(ARG1, ARG2, ARG3, ARG4, ARG5) ClassModule_Constructor(CLASSID_UNDB10FRACT32, ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // #ifndef AWE_STATIC_CODE


void awe_modUndb10Fract32Process(void *pInstance);

 



#ifdef __cplusplus
}
#endif


#endif // _MOD_UNDB10FRACT32_H

/**
 * @}
 *
 * End of file.
 */
