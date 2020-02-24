/****************************************************************************
*
*               Audio Framework
*               ---------------
*
****************************************************************************
*     ModSOFControlFract32.h
****************************************************************************
*
*     Description:  2nd order filter with coefficients derived from input pins
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
 * @brief 2nd order filter with coefficients derived from input pins
 */

#ifndef _MOD_SOFCONTROLFRACT32_H
#define _MOD_SOFCONTROLFRACT32_H

#include "ModCommon.h"
#include "MathHelper.h"

#define MASK_SOFControlFract32_filterType 0x00000100
#define MASK_SOFControlFract32_freq 0x00000200
#define MASK_SOFControlFract32_gain 0x00000400
#define MASK_SOFControlFract32_Q 0x00000800
#define MASK_SOFControlFract32_smoothingTime 0x00001000
#define MASK_SOFControlFract32_postShift 0x00002000
#define MASK_SOFControlFract32_coeffGain 0x00004000
#define MASK_SOFControlFract32_updateActive 0x00008000
#define MASK_SOFControlFract32_smoothingCoeff 0x00010000
#define MASK_SOFControlFract32_pinID 0x00020000
#define MASK_SOFControlFract32_coeffs 0x00040000
#define MASK_SOFControlFract32_coeffsFract32 0x00080000
#define MASK_SOFControlFract32_current_coeffsFract32 0x00100000
#define MASK_SOFControlFract32_state 0x00200000
#define OFFSET_SOFControlFract32_filterType 0x00000008
#define OFFSET_SOFControlFract32_freq 0x00000009
#define OFFSET_SOFControlFract32_gain 0x0000000A
#define OFFSET_SOFControlFract32_Q 0x0000000B
#define OFFSET_SOFControlFract32_smoothingTime 0x0000000C
#define OFFSET_SOFControlFract32_postShift 0x0000000D
#define OFFSET_SOFControlFract32_coeffGain 0x0000000E
#define OFFSET_SOFControlFract32_updateActive 0x0000000F
#define OFFSET_SOFControlFract32_smoothingCoeff 0x00000010
#define OFFSET_SOFControlFract32_pinID 0x00000011
#define OFFSET_SOFControlFract32_coeffs 0x00000012
#define OFFSET_SOFControlFract32_coeffsFract32 0x00000013
#define OFFSET_SOFControlFract32_current_coeffsFract32 0x00000014
#define OFFSET_SOFControlFract32_state 0x00000015

#define CLASSID_SOFCONTROLFRACT32 (CLASS_ID_MODBASE + 1336)

#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------------------------------------
// Overall instance class
// ----------------------------------------------------------------------

typedef struct _awe_modSOFControlFract32Instance
{
    ModuleInstanceDescriptor instance;
    INT32              filterType;          // Selects the type of filter that is implemented by the module: Bypass=0, Gain=1, Butter1stLPF=2, Butter2ndLPF=3, Butter1stHPF=4, Butter2ndHPF=5, Allpass1st=6, Allpass2nd=7, Shelf2ndLow=8, Shelf2ndLowQ=9, Shelf2ndHigh=10, Shelf2ndHighQ=11, PeakEQ=12, Notch=13, Bandpass=14, Bessel1stLPF=15, Bessel1stHPF=16, AsymShelf1stLow=17, AsymShelf1stHigh=18, SymShelf1stLow=19, SymShelf1stHigh=20, VariableQLPF=21, VariableQHPF=22.
    FLOAT32            freq;                // Cutoff frequency of the filter, in Hz.
    FLOAT32            gain;                // Amount of boost or cut to apply, in dB if applicable.
    FLOAT32            Q;                   // Specifies the Q of the filter, if applicable.
    FLOAT32            smoothingTime;       // Time constant of the smoothing process.
    INT32              postShift;           // Number of bits to shift
    FLOAT32            coeffGain;           // Scale coefficients based on postShift.
    INT32              updateActive;        // Specifies whether the filter coefficients are updating (=1) or fixed (=0).
    fract32            smoothingCoeff;      // Smoothing coefficient. This is computed based on the smoothingTime, sample rate, and block size of the module.
    UINT32             pinID;               // Specifies which control pins are available.
    FLOAT32*           coeffs;              // Desired coefficients
    fract32*           coeffsFract32;       // Desired coefficients in fract32
    fract32*           current_coeffsFract32; // Instantaneous coefficients
    fract32*           state;               // State variables.  4 per channel.
} awe_modSOFControlFract32Instance;

#if !defined(NOREDEF)
extern const ModClassModule awe_modSOFControlFract32Class;
#endif // #if !defined(NOREDEF)

/* Dynamic instantiation is used by default.  When building for static
** code, define AWE_STATIC_CODE to eliminate the constructor function. */

#ifndef AWE_STATIC_CODE
ModInstanceDescriptor * awe_modSOFControlFract32Constructor(INT32 * FW_RESTRICT retVal, UINT32 nIO, WireInstance ** FW_RESTRICT pWires, size_t argCount, const Sample * FW_RESTRICT args);
#endif // #ifndef AWE_STATIC_CODE


void awe_modSOFControlFract32Process(void *pInstance);

UINT32 awe_modSOFControlFract32Set(void *pInstance, UINT32 mask);
 

void awe_modSOFControlFract32Bypass(void *pInstance);


#ifdef __cplusplus
}
#endif


#endif // _MOD_SOFCONTROLFRACT32_H

/**
 * @}
 *
 * End of file.
 */
