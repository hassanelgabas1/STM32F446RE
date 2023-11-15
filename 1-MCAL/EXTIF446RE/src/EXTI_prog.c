/*
 * EXTI_prog.c
 *
 *  Created on: Jul 21, 2023
 *      Author: DELL
 */
#include <stdio.h>
#include "StmF446xx.h"
#include "ErrType.h"
#include "EXTI_interface.h"
#include "EXTI_prv.h"
/*global array of pointer to function to hold the callback function*/
void (*EXTI_SetCallBackFunc[EXTI_LINE_NUM])(void)={NULL};
uint8_t EXTI_u8Init(EXTI_config_t* Copy_Cfg)
{
	uint8_t Local_ErrorState=OK;
	if(Copy_Cfg!= NULL)
	{
		/*setting trigger source configuration*/
		switch(Copy_Cfg->TrigSrc)
		{
		case RISING_TRIG:
			EXTI->FTSR &= ~(1<<Copy_Cfg->PinNum);/*clear falling*/
			EXTI->RTSR |=(1<<Copy_Cfg->PinNum);		/*set rising*/
			break;
		case FALLING_TRIG:
			EXTI->RTSR &= ~(1<<Copy_Cfg->PinNum);/*clear rising*/
			EXTI->FTSR |=(1<<Copy_Cfg->PinNum);/*set falling*/
			break;
		case FALLING_RISING_TRIG:
			EXTI->RTSR |=(1<<Copy_Cfg->PinNum);/*set rising*/
			EXTI->FTSR |=(1<<Copy_Cfg->PinNum);/*set falling*/
			break;
		default:Local_ErrorState=NOK; break;

		}
		/*set interrupt enable/disable initial state*/
		if(Copy_Cfg->InitState==ENABLED)
		{
			EXTI->EMR |=(1<<Copy_Cfg->PinNum);
		}
		else if (Copy_Cfg->InitState==DISABLED)
		{
			EXTI->EMR &= ~(1<<Copy_Cfg->PinNum);
		}
		else
		{
			Local_ErrorState=NOK;
		}
		/*setting callback function pointer*/
		if(Copy_Cfg->callbackfunc!=NULL)
		{
			EXTI_SetCallBackFunc[Copy_Cfg->PinNum]=Copy_Cfg->callbackfunc;
		}
		else
		{
			Local_ErrorState=NULL_PTR_ERR;
		}


	}
	else
	{
		Local_ErrorState=NULL_PTR_ERR;
	}
	return Local_ErrorState;
}
uint8_t EXTI_u8SetTrigSrc(EXTI_TrigSrc_t Copy_TrigSrc,EXTI_LineNume Copy_PinNum )
{
	uint8_t Local_ErrorState=OK;


	/*setting trigger source configuration*/
	switch(Copy_TrigSrc)
	{
	case RISING_TRIG:
		EXTI->FTSR &= ~(1<<Copy_PinNum);/*clear falling*/
		EXTI->RTSR |=(1<<Copy_PinNum);		/*set rising*/
		break;
	case FALLING_TRIG:
		EXTI->RTSR &= ~(1<<Copy_PinNum);/*clear rising*/
		EXTI->FTSR |=(1<<Copy_PinNum);/*set falling*/
		break;
	case FALLING_RISING_TRIG:
		EXTI->RTSR |=(1<<Copy_PinNum);/*set rising*/
		EXTI->FTSR |=(1<<Copy_PinNum);/*set falling*/
		break;
	default:Local_ErrorState=NOK; break;
	}
	return Local_ErrorState;
}

void EXTI_voidEnableInt(EXTI_LineNume Copy_line)
{
	EXTI->EMR |=(1<<Copy_line);

}
void EXTI_voidDisableInt(EXTI_LineNume Copy_line)
{
	EXTI->EMR &= ~(1<<Copy_line);

}
void EXTI_voidClearPendingFlag(EXTI_LineNume Copy_line)
{
	EXTI->PR = (1<<Copy_line);
}
uint8_t EXTI_u8GetPendingFlag(EXTI_LineNume Copy_line,uint8_t* Copy_FlagStatus)
{
	uint8_t Local_ErrorState=OK;
	if(Copy_FlagStatus!=NULL)
	{
		*Copy_FlagStatus=((EXTI->PR>>Copy_line)&1);
	}
	else
	{
		Local_ErrorState=NOK;
	}
	return Local_ErrorState;
}



