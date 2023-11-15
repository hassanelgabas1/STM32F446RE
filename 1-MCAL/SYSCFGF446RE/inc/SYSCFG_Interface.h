/*
 * SYSCFG_Interface.h
 *
 *  Created on: Aug 1, 2023
 *      Author: DELL
 */

#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_
typedef enum
{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG,
	PORTH
}SYSCFG_Port_t;
typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
	PIN8,
	PIN9,
	PIN10,
	PIN11,
	PIN12,
	PIN13,
	PIN14,
	PIN15
}SYSCFG_LineNume_t;
void SysCfg_voidSetEXTIPort(SYSCFG_LineNume_t Copy_PinNum,SYSCFG_Port_t Copy_Port);


#endif /* SYSCFG_INTERFACE_H_ */
