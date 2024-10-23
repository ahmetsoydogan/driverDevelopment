#ifndef INC_EXTI_H_
#define INC_EXTI_H_

#include "stm32f407xx.h"


#define EXTI_PortSource_GPIOA			((uint8_t)(0x0U))
#define EXTI_PortSource_GPIOB			((uint8_t)(0x1U))
#define EXTI_PortSource_GPIOC			((uint8_t)(0x2U))
#define EXTI_PortSource_GPIOD			((uint8_t)(0x3U))
#define EXTI_PortSource_GPIOE			((uint8_t)(0x4U))
#define EXTI_PortSource_GPIOF			((uint8_t)(0x5U))
#define EXTI_PortSource_GPIOG			((uint8_t)(0x6U))
#define EXTI_PortSource_GPIOH			((uint8_t)(0x7U))

#define EXTI_LineSource_0				((uint8_t)(0x0U))
#define EXTI_LineSource_1				((uint8_t)(0x1U))
#define EXTI_LineSource_2				((uint8_t)(0x2U))
#define EXTI_LineSource_3				((uint8_t)(0x3U))
#define EXTI_LineSource_4				((uint8_t)(0x4U))
#define EXTI_LineSource_5				((uint8_t)(0x5U))
#define EXTI_LineSource_6				((uint8_t)(0x6U))
#define EXTI_LineSource_7				((uint8_t)(0x7U))
#define EXTI_LineSource_8				((uint8_t)(0x8U))
#define EXTI_LineSource_9				((uint8_t)(0x9U))
#define EXTI_LineSource_10				((uint8_t)(0xAU))
#define EXTI_LineSource_11				((uint8_t)(0xBU))
#define EXTI_LineSource_12				((uint8_t)(0xCU))
#define EXTI_LineSource_13				((uint8_t)(0xDU))
#define EXTI_LineSource_14				((uint8_t)(0xEU))
#define EXTI_LineSource_15				((uint8_t)(0xFU))


#define EXTI_MODE_Interrupt				(0x00U)		//innterupt mask register
#define EXTI_MODE_Event					(0x04U)		//event mask register

#define EXTI_Trigger_Rising				(0x08U)		//trigger rising register
#define EXTI_Trigger_Falling			(0x0CU)		//trigger falling register
#define EXTI_Trigger_RF					(0x10U)		//trigger falling register



typedef struct
{
	uint8_t EXTI_LineNumber;   			// port
	uint8_t TriggerSelection;  			// yukselen mi dusen mi
	uint8_t EXTI_Mode;					//event mi interrupt mi
	FunctionalState_t EXTI_LineCmd;		//enable mi disable mi etmek istiyorsun

}EXTI_InitTypeDef_t;

void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct);
void EXTI_LineConfig(uint8_t PortSource, uint8_t EXTI_LineSource);
void NVIC_EnableInterrupt(IRQNumber_TypeDef_t IRQNumber);

#endif /* INC_EXTI_H_ */
