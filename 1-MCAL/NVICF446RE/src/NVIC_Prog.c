/******************************************/
/*@file NVIC_Prog.c
 * @author Hassan Elgabas
 * @brief The NVIC main source file, including functions definitions
 *
 */
#include <stdint.h>
#include "StmF446.h"
#include "ErrType.h"
#include "NVIC_prv.h"
#include "NVIC_interface.h"
void NVIC_voidEnPeripheral(Peripheral_IRQn Copy_irq)
{
	uint8_t Local_ISERNum =Copy_irq / 32u;
	uint8_t Local_BitNum =Copy_irq % 32u;
	NVIC_ISER[Local_ISERNum]=(1<<Local_BitNum);
}
void NVIC_voidDisablePeripheral(Peripheral_IRQn Copy_irq)
{
	uint8_t Local_ISERNum =Copy_irq / 32u;
	uint8_t Local_BitNum =Copy_irq % 32u;
	NVIC_ICER[Local_ISERNum]=(1<<Local_BitNum);
}
void NVIC_voidSetPendingFlagPeripheral(Peripheral_IRQn Copy_irq)
{
	uint8_t Local_ISERNum =Copy_irq / 32u;
	uint8_t Local_BitNum =Copy_irq % 32u;
	NVIC_ISPR[Local_ISERNum]=(1<<Local_BitNum);

}
void NVIC_voidClearPendingFlagPeripheral(Peripheral_IRQn Copy_irq)
{
	uint8_t Local_ISERNum =Copy_irq / 32u;
	uint8_t Local_BitNum =Copy_irq % 32u;
	NVIC_ICPR[Local_ISERNum]=(1<<Local_BitNum);
}
uint8_t NVIC_u8GetActiveFlagPeripheral(Peripheral_IRQn Copy_irq)
{
	uint8_t Local_ActiveFlagValue;
	uint8_t Local_ISERNum = Copy_irq / 32u;
	uint8_t Local_BitNum = Copy_irq % 32u;
	Local_ActiveFlagValue = NVIC_IABR[Local_ISERNum]=(1<<Local_BitNum);
	return Local_ActiveFlagValue;
}
uint8_t NVIC_u8SetIRQPriority(Peripheral_IRQn Copy_irq ,uint8_t Copy_Priority)
{
	uint8_t Local_Error_State=OK;
	if(Copy_irq<=FMPI2C1_ER_IRQn)
	{
		NVIC_IPR[Copy_irq] = IPR_REGISTER_MASK;
		NVIC_IPR[Copy_irq] = (Copy_Priority << 4);

	}
	else
	{
		Local_Error_State=NOK;
	}
	return Local_Error_State;
}



