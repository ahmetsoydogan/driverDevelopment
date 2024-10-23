#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "stm32f407xx.h"

/* ENABLIZING */

#define RCC_GPIOA_CLK_ENABLE()		do{	uint32_t tempValue = 0; 								\
										SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN); 			\
										tempValue = SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN); \
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_GPIOB_CLK_ENABLE()		do{	uint32_t tempValue = 0; 								\
										SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN); 			\
										tempValue = SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN); \
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_GPIOC_CLK_ENABLE()		do{	uint32_t tempValue = 0; 								\
										SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN); 			\
										tempValue = SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN); \
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_GPIOD_CLK_ENABLE()		do{	uint32_t tempValue = 0; 								\
										SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN); 			\
										tempValue = SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN); \
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_SYSCFG_CLK_ENABLE()		do{	uint32_t tempValue = 0;									\
										SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SYSCFGEN);				\
										tempValue = SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SYSCFGEN);\
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_SPI1_CLK_ENABLE()		do{	uint32_t tempValue = 0;									\
										SET_BIT(RCC->APB2ENR,RCC_APB2ENR_SPI1EN);				\
										tempValue = SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);	\
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_SPI2_CLK_ENABLE()		do{	uint32_t tempValue = 0;									\
										SET_BIT(RCC->APB1ENR,RCC_APB1ENR_SPI2EN);				\
										tempValue = SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);	\
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_USART2_CLK_ENABLE()		do{	uint32_t tempValue = 0;									\
										SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART2EN);				\
										tempValue = SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART2EN);\
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_USART3_CLK_ENABLE()		do{	uint32_t tempValue = 0;									\
										SET_BIT(RCC->APB1ENR,RCC_APB1ENR_USART3EN);				\
										tempValue = SET_BIT(RCC->APB1ENR, RCC_APB1ENR_USART3EN);\
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_UART4_CLK_ENABLE()		do{	uint32_t tempValue = 0;									\
										SET_BIT(RCC->APB1ENR,RCC_APB1ENR_UART4EN);				\
										tempValue = SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART4EN);	\
										UNUSED(tempValue); 										\
										}while(0)

#define RCC_UART5_CLK_ENABLE()		do{	uint32_t tempValue = 0;									\
										SET_BIT(RCC->APB1ENR,RCC_APB1ENR_UART5EN);				\
										tempValue = SET_BIT(RCC->APB1ENR, RCC_APB1ENR_UART5EN);	\
										UNUSED(tempValue); 										\
										}while(0)

uint32_t RCC_GetSystemClock(void);
uint32_t RCC_GetHClock(void);
uint32_t RCC_GetPClock1(void);
uint32_t RCC_GetPClock2(void);


/* DISABLIZING */

#define RCC_GPIOA_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN)
#define RCC_GPIOB_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN)
#define RCC_GPIOC_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN)
#define RCC_GPIOD_CLK_DISABLE()		CLEAR_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN)

#endif /* INC_RCC_H_ */
