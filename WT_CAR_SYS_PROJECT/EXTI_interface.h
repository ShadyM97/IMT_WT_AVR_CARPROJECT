#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_



typedef enum
{
	EXT0 = 0,
	EXT1,
	EXT2
}EXTI_number_t;


void EXT_INTERRUPT_VID_INIT(void);
void EXT_INTERRUPT_VID_ENABLE(EXTI_number_t interrupt_number);
void EXT_INTERRUPT_VID_DISABLE(EXTI_number_t interrupt_number);
void EXT0_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT1_VID_SET_CALL_BACK(void (*PTR)(void));
void EXT2_VID_SET_CALL_BACK(void (*PTR)(void));

#endif /* EXTI_INTERFACE_H_ */
