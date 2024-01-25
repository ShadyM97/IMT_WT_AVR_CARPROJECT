/*******************************************************************/
/* Author  : Shady                                                 */
/* SWC     : Seven_segment                                         */
/* Version : 1.0                                                   */
/* Date    : 10 Dec 2023                                           */
/*******************************************************************/
#include "BIT_Math.h"
#include "STD_Types.h"
#include "DIO_interface.h"
#include "seven_segment_config.h"
#include "seven_segment_interface.h"
#include "seven_segment_private.h"

/* Common Cathode */		  /* 0	   1     2     3      4    5     6     7     8      9*/
uint8 Sev_SegmentPattern[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};

void SevSeg_voidDisplay(uint8 u8NumberCpy, uint8 u8SevSegPort)
{
#if COMMON_TYPE == COMMON_CATHODE
		DIO_voidWritePort(u8SevSegPort, Sev_SegmentPattern[u8NumberCpy]);

#elif COMMON_TYPE == COMMON_ANODE
		DIO_voidWritePort(u8SevSegPort, ~Sev_SegmentPattern[u8NumberCpy]);
#endif
}
