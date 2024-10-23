
#include "GPIO.h"

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIO_ConfigStruct)
{
	uint32_t position;
	uint32_t fakePosition = 0;
	uint32_t lastPosition = 0;

	for(position = 0; position <16; position++)
	{
		fakePosition = (0x1 << position);
		lastPosition = (uint32_t)(GPIO_ConfigStruct->pinNumber) & fakePosition;

		if(fakePosition == lastPosition)
		{
			/* Mode Confugiration */
			uint32_t tempValue = GPIOx->MODER;

			tempValue &= ~(0x3U << (position*2));					//temizleme islemi
			tempValue |= (GPIO_ConfigStruct->Mode << (position*2));

			GPIOx->MODER = tempValue;


			if(GPIO_ConfigStruct->Mode == GPIO_MODE_OUTPUT || GPIO_ConfigStruct->Mode == GPIO_MODE_AF)
			{
				/* Otype Confugiration */
				tempValue = GPIOx->OTYPER;

				tempValue &= ~(0x1U << (position));
				tempValue |= (GPIO_ConfigStruct->Otype << (position));

				GPIOx->OTYPER = tempValue;

				/* Ospeed Configuration*/
				tempValue = GPIOx->OSPEEDR;

				tempValue &= ~(0x3U << (position * 2));
				tempValue |= (GPIO_ConfigStruct->Speed << (position * 2));

				GPIOx->OSPEEDR = tempValue;

			}
			/* Push Pull Configuration*/
			tempValue = GPIOx->PUPDR;

			tempValue &= ~(0x3U << (position * 2));
			tempValue |= (GPIO_ConfigStruct->PuPd << (position * 2));


			GPIOx->PUPDR = tempValue;
			if (GPIO_ConfigStruct->Mode == GPIO_MODE_AF)
			{
				uint32_t tempValue;
				tempValue = GPIOx->AFR[position >> 3U];
				tempValue &= ~(0xFU << ((position & 0x7U) * 4));
				tempValue |= (GPIO_ConfigStruct->Alternate << ((position & 0x7U) * 4));
				GPIOx->AFR[position >> 3U] = tempValue;
			}
		}

	}
};

void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState)
{
	if(pinState == GPIO_Pin_Set)
	{
		GPIOx->BSRR = pinNumber; // 0011 0000 0000 0000
	}
	else
	{
		GPIOx->BSRR = (pinNumber <<16U);
	}

};

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	GPIO_PinState_t bitStatus = GPIO_Pin_Reset;

	if((GPIOx->IDR & pinNumber) != GPIO_Pin_Reset)
	{
		bitStatus = GPIO_Pin_Set; // 0011 0000 0000 0000
	}
	return bitStatus;
};

void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	uint32_t tempValue = (0x1U << 16U) | pinNumber; // 1 1000 0000 1101 0001

	GPIOx->LCKR = tempValue;
	GPIOx->LCKR = pinNumber;
	GPIOx->LCKR = tempValue;
	tempValue = GPIOx->LCKR;


}

void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber)
{
	uint32_t tempODRRegister = GPIOx->ODR;

	GPIOx->BSRR = ( (tempODRRegister & pinNumber) <<16U ) |  (~tempODRRegister & pinNumber);  // veyanin solu yananlari sonduruyor, sagi sonenleri yakiyor
};


void GPIO_WritePin_LedCont() // art arda 4 ledi sırasıyla yakma algoritması
{
	uint16_t pinNumber = GPIO_PIN_12;
	uint16_t tempPin = GPIO_PIN_12;
	for(;;)
	{
		if(GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_Pin_Set)
		{
			GPIO_WritePin(GPIOD, pinNumber, GPIO_Pin_Set);
			if(pinNumber == GPIO_PIN_15){tempPin =  GPIO_PIN_12;}else{tempPin = pinNumber<<1U;}
		}
		else
		{
			GPIO_WritePin(GPIOD, pinNumber, GPIO_Pin_Reset);
			pinNumber = tempPin;

		}
	};

};
