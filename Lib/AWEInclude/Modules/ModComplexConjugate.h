/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModComplexConjugate.h
****************************************************************************
*
*     Description:  converts a complex signal into its conjugate
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
 * @brief converts a complex signal into its conjugate
 */

#ifndef _MOD_COMPLEXCONJUGATE_H
#define _MOD_COMPLEXCONJUGATE_H

#include "ModCommon.h"
#include "MathHelper.h"


#define CLASSID_COMPLEXCONJUGATE (CLASS_ID_MODBASE + 1233)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modComplexConjugateInstance
{
    ModuleInstanceDescriptor instance;
    
    
} awe_modComplexConjugateInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modComplexConjugateClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
// This points the constructor for this class to the base constructor
#define awe_modComplexConjugateConstructor(ARG1, ARG2, ARG3, ARG4, ARG5) ClassModule_Constructor(CLASSID_COMPLEXCONJUGATE, ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // #ifndef AWE_STATIC_CODE


void awe_modComplexConjugateProcess(void *pInstance);

 



#ifdef __cplusplus
}
#endif


#endif // _MOD_COMPLEXCONJUGATE_H

/**
 * @}
 *
 * End of file.
 */
