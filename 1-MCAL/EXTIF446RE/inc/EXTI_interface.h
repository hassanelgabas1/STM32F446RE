/*
 * EXTI_interface.h
 *
 *  Created on: Jul 21, 2023
 *      Author: DELL
 */

#ifndef INC_EXTI_INTERFACE_H_
#define INC_EXTI_INTERFACE_H_
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
}EXTI_LineNume;
typedef enum
{
	FALLING_TRIG,
	RISING_TRIG,
	FALLING_RISING_TRIG
}EXTI_TrigSrc_t;
typedef enum
{
	ENABLED,
	DISABLED
}EXTI_InitState_t;
typedef struct
{
	EXTI_LineNume PinNum;
	EXTI_TrigSrc_t TrigSrc;
	EXTI_InitState_t InitState;
	void(*callbackfunc)(void);
}EXTI_config_t;

uint8_t EXTI_u8Init(EXTI_config_t* Copy_Cfg);
uint8_t EXTI_u8SetTrigSrc(EXTI_TrigSrc_t Copy_TrigSrc,EXTI_LineNume Copy_PinNum );
void EXTI_voidEnableInt(EXTI_LineNume Copy_line);
void EXTI_voidDisableInt(EXTI_LineNume Copy_line);
void EXTI_voidClearPendingFlag(EXTI_LineNume Copy_line);
uint8_t EXTI_GetPendingFlag(EXTI_LineNume Copy_line,uint8_t* Copy_FlagStatus);



#endif /* INC_EXTI_INTERFACE_H_ */
