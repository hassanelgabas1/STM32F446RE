/******************************************/
/*@file GPIO_Prog.c
 * @author Hassan Elgabas
 * @brief The GPIO main source file, including functions definitions
 *
 */
#include <stdint.h>
#include "StmF446xx.h"
#include "ErrType.h"
#include "Gpio_Interface.h"
#include "GPIO_Prv.h"
static GPIO_RegDef_t* GPIOport[GPIO_PERIPHERAL_NUM]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG,GPIOH};
/**********************************************
 * @fn GPIO_u8Init
 * @brief the function initializes the GPIO pin according to input parameter
 * @parameter[in] PinConfig : the initialization values of the pin
 * @retrieval Error status
 *
 *
 */

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t *PinConfig)
{
	uint8_t Local_u8ErrorState=OK;
	if(PinConfig != NULL)
	{
		if((PinConfig->Port<=PORTH) && (PinConfig->PinNum<=PIN15))
		{
			/*select GPIO mode : input ,output, analog, alternate function*/
			(GPIOport[PinConfig->Port]->MODER)&= ~(MODER_MASK << ((PinConfig->PinNum) *MODER_PIN_ACCESS));//clear the mode bits
			(GPIOport[PinConfig->Port]->MODER)|= (PinConfig->Mode << ((PinConfig->PinNum) *MODER_PIN_ACCESS));//set the mode of pin
			/*select the GPIO pull state : pullup, pulldown, nopull */
			(GPIOport[PinConfig->Port]->PUPDR) &= ~(PUPDR_MASK << ((PinConfig->PinNum) *PUPDR_PIN_ACCESS));//clear the PUPDR bits
			(GPIOport[PinConfig->Port]->PUPDR) |= (PinConfig->PullType << ((PinConfig->PinNum) *PUPDR_PIN_ACCESS));//set the pullup/down of pin
			/*select output type & output speed in case of general purpose output or alternate function */
			if((PinConfig ->Mode == OUTPUT) || (PinConfig->Mode == ALTERNATE_FUNCTION) )
			{
				/*select the output type: pushpull, open drian*/

				(GPIOport[PinConfig->Port]->OTYPER) &= ~(OTYPER_MASK << (PinConfig->PinNum));//clear the output type bit
				(GPIOport[PinConfig->Port]->OTYPER) |=  (PinConfig->OutType << (PinConfig->PinNum));//SET the output type

				/*select the output speed: Low, High, Medium, fast*/
				(GPIOport[PinConfig->Port]->OSPEEDR) &= ~(OSPEEDR_MASK << ((PinConfig->PinNum) *OSPEEDR_MASK));//clear the PUPDR bits
				(GPIOport[PinConfig->Port]->OSPEEDR) |= (PinConfig->Speed << ((PinConfig->PinNum) *OSPEEDR_PIN_ACCESS));
				if(PinConfig->Mode == ALTERNATE_FUNCTION)
				{
					uint8_t Local_u8RegNum=(PinConfig->PinNum)/AFR_PIN_SHIFTING;
					uint8_t Local_u8BitNum=(PinConfig->PinNum)%AFR_PIN_SHIFTING;
					GPIOport[PinConfig->Port]->AFR[Local_u8RegNum] &= ~(AFR_MASK << (Local_u8BitNum*AFR_PIN_ACCESS));
					GPIOport[PinConfig->Port]->AFR[Local_u8RegNum] |= ((PinConfig->AltFunc)<<(Local_u8BitNum * AFR_PIN_ACCESS));

				}
			}


		}
		else
		{
			Local_u8ErrorState=NOK;
		}
	}
	else
	{
		Local_u8ErrorState=NULL_PTR_ERR;
	}

	return Local_u8ErrorState;
}

/**********************************************************************
 * @fn GPIO_u8SetPinValue
 * @brief the function outputs a certain value on an output pin
 * @param[in]  Port : the port number, get options @port_t enum
 * @param[in]  PinNum : the pin number, get options @Pin_t enum
 * @param[in]  PinVal_t : the pin value, get options @PinVal_t enum
 * @retrieval Error status
 *
 * */
uint8_t GPIO_u8SetPinValue(Port_t Port ,Pin_t PinNum,PinVal_t PinVal)
{
	uint8_t Local_u8ErrorState=OK;
	if((Port<=PORTH) && (PinNum<=PIN15))
	{
		if(PinVal==PIN_LOW)
		{
			GPIOport[Port]->ODR &= ~(1<<PinNum);
			/*GPIOport[Port]->BSRR = (1<<16 + PinNum);*/

		}
		else if(PinVal==PIN_HIGH)
		{
			GPIOport[Port]->ODR |= (1<<PinNum);
			/*GPIOport[Port]->BSRR = (1<<PinNum);*/

		}
		else
		{
			Local_u8ErrorState=NOK;

		}
	}
	else
	{
		Local_u8ErrorState=NOK;

	}



	return Local_u8ErrorState;

}

