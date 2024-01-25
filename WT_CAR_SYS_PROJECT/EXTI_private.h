#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR     *((volatile uint8*)(0x55))
#define GIFR      *((volatile uint8*)(0x5A))
#define  GICR     *((volatile uint8*)(0x5B))
#define MCUCSR    *((volatile uint8*)(0x54))

#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0

#define INTF1 7
#define INTF0 6
#define INTF2 5

#define INT1 7
#define INT0 6
#define INT2 5

#define ISC2 6

#define LOW_LEVEL 0
#define IOC 1 //interrupt on Change.
#define FALLING_EDGE 2
#define RISING_EDGE 3

#endif /* EXTI_PRIVATE_H_ */
