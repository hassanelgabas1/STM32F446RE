/*
 * SYSCFG_Prog.c
 *
 *  Created on: Aug 1, 2023
 *      Author: DELL
 */
#include <stdio.h>
#include "ErrType.h"
#include "StmF446xx.h"
#include "SYSCFG_Interface.h"
#include "SYSCFG_Prv.h"
void SysCfg_voidSetEXTIPort(SYSCFG_LineNume_t Copy_PinNum,SYSCFG_Port_t Copy_Port)
{
	uint8_t Local_u8RegisterNum=Copy_PinNum /DIVIDE_BY_FOUR;
	uint8_t Local_u8BitNum=(Copy_PinNum %DIVIDE_BY_FOUR)*DIVIDE_BY_FOUR;
	SYSCFG->CR[Local_u8RegisterNum] &= (~(CR_REGISTER_MASK<<Local_u8BitNum));/*cleared the required bits*/
	SYSCFG->CR[Local_u8RegisterNum] |=(Copy_Port<<Local_u8BitNum); /*set the port number value*/
}


