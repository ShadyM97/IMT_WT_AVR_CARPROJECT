/*******************************************************************/
/* Author  : Shady                                                 */
/* SWC     : Seven_segment                                         */
/* Version : 1.0                                                   */
/* Date    : 10 Dec 2023                                           */
/*******************************************************************/
#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_

#define COMMON_CATHODE  1
#define COMMON_ANODE    0

#define SEVEN_SEGMENT_PORT_NAME	       PORT_C


void SevSeg_voidDisplay(uint8 u8NumberCpy, uint8 u8SevSegPort);

#endif
