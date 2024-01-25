/*****************************************************************/
/* Author  : Shady                                               */
/* SWC     : UART                                                */
/* Version : 1.0                                                 */
/* Date    : 25 Dec 2023                                         */
/*****************************************************************/
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

void UART_vInit(void);
void UART_vDisableEmptyInterrupt(void);
void UART_vSendData(const uint8 CpyData);
uint8 UART_u8ReceiveData(void);
void SendCallBack(void (*pf)(void));
void ReceiveCallBack(void (*pf)(void));

#endif
