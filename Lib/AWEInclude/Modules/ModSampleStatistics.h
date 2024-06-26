/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModSampleStatistics.h
****************************************************************************
*
*     Description:  Computes sample statistics over multichannel signals
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
 * @brief Computes sample statistics over multichannel signals
 */

#ifndef _MOD_SAMPLESTATISTICS_H
#define _MOD_SAMPLESTATISTICS_H

#include "ModCommon.h"
#include "MathHelper.h"

#define MASK_SampleStatistics_statisticsType 0x00000100
#define OFFSET_SampleStatistics_statisticsType 0x00000008

#define CLASSID_SAMPLESTATISTICS (CLASS_ID_MODBASE + 1320)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modSampleStatisticsInstance
{
    ModuleInstanceDescriptor instance;
    INT32              statisticsType;      // Type of statistics calculated: 0=maximum, 1=minimum, 2=maximum absolute value, 3=minimum absolute value.
    
} awe_modSampleStatisticsInstance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modSampleStatisticsClass;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
// This points the constructor for this class to the base constructor
#define awe_modSampleStatisticsConstructor(ARG1, ARG2, ARG3, ARG4, ARG5) ClassModule_Constructor(CLASSID_SAMPLESTATISTICS, ARG1, ARG2, ARG3, ARG4, ARG5)
#endif // #ifndef AWE_STATIC_CODE


void awe_modSampleStatisticsProcess(void *pInstance);

 



#ifdef __cplusplus
}
#endif


#endif // _MOD_SAMPLESTATISTICS_H

/**
 * @}
 *
 * End of file.
 */
