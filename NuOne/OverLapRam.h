#ifndef __OVERLAPRAM_H__
#define __OVERLAPRAM_H__

//#include "base_types.h"
#include "NVTTypes.h"
#include "NuOneEx.h"

#ifdef __cplusplus
extern "C"{
#endif

//#define AUDIOBUFFERSIZE		160		   //duplicated defined
#define k_nMemSize				(40*1024)//9600

union _overlapMem {
	struct {
		UINT8 lpbyMemPool[k_nMemSize];					//VR.c Use
//		INT16 MicBuffer[2][AUDIOBUFFERSIZE];	//WaveRecord.c Use	�ϥο����|�Ψ�
	} vrUseMemPool;													//�ϥ�VR���Ѯɷ|�Ψ�
	/*
	���ݭn�b��L�ɫ�ϥΨ쪺�j�e�q�O����A�i�H�Q�γo�@���ϥΡA�`�N���n�MVR�P�ɴN�i�C
	*/
	
	struct{
		UINT32 au32DecodeWorkBuf[(NUONEEX_DECODE_WORK_BUF_SIZE+3)/4];
		UINT32 u32NuOneExTempBuf[(NUONEEX_DECODE_TEMP_BUF_SIZE+3)/4];
		INT16 i16OutBuf[2][NUONEEX_DECODE_SAMPLE_PER_FRAME*2];
	} NuOneMemPool;
};

extern union _overlapMem overlapMem;

#ifdef __cplusplus
}
#endif

#endif // __OVERLAPRAM_H__
