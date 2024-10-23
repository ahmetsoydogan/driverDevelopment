/*
 * stm32f407xx.h
 *
 *  Created on: Oct 1, 2024
 *      Author: ahmet
 */

#ifndef INC_STM32F407XX_H_
#define INC_STM32F407XX_H_

#include <stdint.h>
#include <string.h>
#include <stddef.h>


/*Microprocessor Defines*/
#define NVIC_ISER0				((uint32_t*)(0xE000E100))


#define __IO volatile

#define SET_BIT(REG,BIT)		((REG) |=  (BIT))
#define CLEAR_BIT(REG,BIT)		((REG) &= ~(BIT))
#define READ_BIT(REG,BIT)		((REG) &   (BIT))
#define UNUSED(x)				(void)(x)


typedef enum
{
	DISABLE = 0x0U,
	ENABLE = !DISABLE

}FunctionalState_t;

/* IRQ Numbers of MCU == Vector Table */

typedef enum
{
	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	SPI1_IRQNumber = 35,
	USART2_IRQNumber = 38


}IRQNumber_TypeDef_t;



/*
 *  Memory Base Address
 */

#define FLASH_BASE_ADDR		(0X08000000UL) /*Flash Base Address (up to 1MB)	*/
#define SRAM1_BASE_ADDR		(0x20000000UL) /*SRAM1 Base Address 112 KB		*/
#define SRAM2_BASE_ADDR		(0x2001C000UL) /*SRAM2 Base Address 16 KB		*/

/*
 *  Peripheral Base Address
 */

#define PERIPH_BASE_ADDR	(0x40000000UL) /*Base Addresses For All Peripherals*/
#define APB1_BASE_ADDR		PERIPH_BASE_ADDR /*APB1 Bus Domain Base Address */
#define APB2_BASE_ADDR		(PERIPH_BASE_ADDR + 0x10000UL) /*APB2 Bus Domain Base Address */
#define AHB1_BASE_ADDR		(PERIPH_BASE_ADDR + 0x20000UL) /*AHB1 Bus Domain Base Address */
#define AHB2_BASE_ADDR		(PERIPH_BASE_ADDR + 0x10000000UL) /*AHB2 Bus Domain Base Address */

/*
 *  APB1 Peripherals Base Addresses
 */

#define TIM2_BASE_ADDR		(APB1_BASE_ADDR + 0x0000UL)
#define TIM3_BASE_ADDR		(APB1_BASE_ADDR + 0x0400UL)
#define TIM4_BASE_ADDR		(APB1_BASE_ADDR + 0x0800UL)

#define SPI2_BASE_ADDR		(APB1_BASE_ADDR + 0x3800UL)
#define SPI3_BASE_ADDR		(APB1_BASE_ADDR + 0x3C00UL)

#define USART2_BASE_ADDR	(APB1_BASE_ADDR + 0x4400UL)
#define USART3_BASE_ADDR	(APB1_BASE_ADDR + 0x4800UL)
#define UART4_BASE_ADDR		(APB1_BASE_ADDR + 0x4C00UL)
#define UART5_BASE_ADDR		(APB1_BASE_ADDR + 0x5000UL)

#define I2C1_BASE_ADDR		(APB1_BASE_ADDR + 0x5400UL)
#define I2C2_BASE_ADDR		(APB1_BASE_ADDR + 0x5800UL)
#define I2C3_BASE_ADDR		(APB1_BASE_ADDR + 0x5C00UL)

/*
 *  APB2 Peripherals Base Addresses
 */

#define TIM1_BASE_ADDR		(APB2_BASE_ADDR + 0x0000UL)
#define TIM8_BASE_ADDR		(APB2_BASE_ADDR + 0x0400UL)

#define USART1_BASE_ADDR	(APB2_BASE_ADDR + 0x0000UL)
#define USART6_BASE_ADDR	(APB2_BASE_ADDR + 0x1400UL)

#define SPI1_BASE_ADDR		(APB2_BASE_ADDR + 0x3000UL)
#define SPI4_BASE_ADDR		(APB2_BASE_ADDR + 0x3400UL)

#define SYSCFG_BASE_ADDR	(APB2_BASE_ADDR + 0x3800UL)
#define EXTI_BASE_ADDR		(APB2_BASE_ADDR + 0x3C00UL)

/*
 *  AHB1 Peripherals Base Addresses
 */
#define GPIOA_BASE_ADDR		(AHB1_BASE_ADDR + 0x0000UL)
#define GPIOB_BASE_ADDR		(AHB1_BASE_ADDR + 0x0400UL)
#define GPIOC_BASE_ADDR		(AHB1_BASE_ADDR + 0x0800UL)
#define GPIOD_BASE_ADDR		(AHB1_BASE_ADDR + 0x0C00UL)
#define GPIOE_BASE_ADDR		(AHB1_BASE_ADDR + 0x1000UL)

#define RCC_BASE_ADDR		(AHB1_BASE_ADDR + 0x3800UL)

/*
 *  Peripheral structure definitons
 */

typedef struct
{
	__IO uint32_t MODER;
	__IO uint32_t OTYPER;
	__IO uint32_t OSPEEDR;
	__IO uint32_t PUPDR;
	__IO uint32_t IDR;
	__IO uint32_t ODR;
	__IO uint32_t BSRR;
	__IO uint32_t LCKR;
	__IO uint32_t AFR[2];

}GPIO_TypeDef_t;

typedef struct
{
	__IO uint32_t CR;
	__IO uint32_t PLLCFGR;
	__IO uint32_t CFGR;
	__IO uint32_t CIR;
	__IO uint32_t AHB1RSTR;
	__IO uint32_t AHB2RSTR;
	__IO uint32_t AHB3RSTR;
	__IO uint32_t RESERVED0;
	__IO uint32_t APB1RSTR;
	__IO uint32_t APB2RSTR;
	__IO uint32_t RESERVED1[2];
	__IO uint32_t AHB1ENR;
	__IO uint32_t AHB2ENR;
	__IO uint32_t AHB3ENR;
	__IO uint32_t RESERVED2;
	__IO uint32_t APB1ENR;
	__IO uint32_t APB2ENR;
	__IO uint32_t RESERVED3[2];
	__IO uint32_t AHB1LPENR;
	__IO uint32_t AHB2LPENR;
	__IO uint32_t AHB3LPENR;
	__IO uint32_t RESERVED4;
	__IO uint32_t APB1LPENR;
	__IO uint32_t APB2LPENR;
	__IO uint32_t RESERVED5[2];
	__IO uint32_t BDCR;
	__IO uint32_t CSR;
	__IO uint32_t RESERVED6[2];
	__IO uint32_t SSCGR;
	__IO uint32_t PLLI2SCFGR;

}RCC_TypeDef_t;

typedef struct
{
	__IO uint32_t MEMRMP;
	__IO uint32_t PMC;
	__IO uint32_t EXTI_CR[4];
	__IO uint32_t CMPCR;

}SYSCFG_TypeDef_t;

typedef struct
{
	__IO uint32_t IMR;
	__IO uint32_t EMR;
	__IO uint32_t RTSR;
	__IO uint32_t FTSR;
	__IO uint32_t SWIER;
	__IO uint32_t PR;

}EXTI_TypeDef_t;

typedef struct
{
	__IO uint32_t CR1;
	__IO uint32_t CR2;
	__IO uint32_t SR;
	__IO uint32_t DR;
	__IO uint32_t CRCPR;
	__IO uint32_t RXCRCR;
	__IO uint32_t TXCRCR;
	__IO uint32_t I2SCFGR;
	__IO uint32_t I2SPR;

}SPI_TypeDef_t;


typedef struct
{
	__IO uint32_t SR;
	__IO uint32_t DR;
	__IO uint32_t BRR;
	__IO uint32_t CR1;
	__IO uint32_t CR2;
	__IO uint32_t CR3;
	__IO uint32_t GTPR;

}USART_TypeDef_t;

#define GPIOA						((GPIO_TypeDef_t	*)(GPIOA_BASE_ADDR)	)
#define GPIOB						((GPIO_TypeDef_t 	*)(GPIOB_BASE_ADDR)	)
#define GPIOC						((GPIO_TypeDef_t 	*)(GPIOC_BASE_ADDR)	)
#define GPIOD						((GPIO_TypeDef_t 	*)(GPIOD_BASE_ADDR)	)
#define GPIOE						((GPIO_TypeDef_t 	*)(GPIOE_BASE_ADDR)	)

#define RCC							((RCC_TypeDef_t 	*)(RCC_BASE_ADDR)	)

#define SYSCFG						((SYSCFG_TypeDef_t 	*)(SYSCFG_BASE_ADDR))

#define EXTI						((EXTI_TypeDef_t 	*)(EXTI_BASE_ADDR)	)

#define SPI1						((SPI_TypeDef_t		*)(SPI1_BASE_ADDR)	)
#define SPI2						((SPI_TypeDef_t		*)(SPI2_BASE_ADDR)	)

#define USART1						((USART_TypeDef_t	*)(USART1_BASE_ADDR))
#define USART6						((USART_TypeDef_t	*)(USART6_BASE_ADDR))

#define USART2						((USART_TypeDef_t	*)(USART2_BASE_ADDR))
#define USART3						((USART_TypeDef_t	*)(USART3_BASE_ADDR))
#define UART4						((USART_TypeDef_t	*)(UART4_BASE_ADDR)	)
#define UART5						((USART_TypeDef_t	*)(UART5_BASE_ADDR)	)


#define RCC_AHB1ENR_GPIOAEN_Pos		(0U)
#define RCC_AHB1ENR_GPIOAEN_Msk		(0x1 << RCC_AHB1ENR_GPIOAEN_Pos)
#define RCC_AHB1ENR_GPIOAEN			RCC_AHB1ENR_GPIOAEN_Msk

#define RCC_AHB1ENR_GPIOBEN_Pos		(1U)
#define RCC_AHB1ENR_GPIOBEN_Msk		(0x1 << RCC_AHB1ENR_GPIOBEN_Pos)
#define RCC_AHB1ENR_GPIOBEN			RCC_AHB1ENR_GPIOBEN_Msk

#define RCC_AHB1ENR_GPIOCEN_Pos		(2U)
#define RCC_AHB1ENR_GPIOCEN_Msk		(0x1 << RCC_AHB1ENR_GPIOCEN_Pos)
#define RCC_AHB1ENR_GPIOCEN			RCC_AHB1ENR_GPIOCEN_Msk

#define RCC_AHB1ENR_GPIODEN_Pos		(3U)
#define RCC_AHB1ENR_GPIODEN_Msk		(0x1 << RCC_AHB1ENR_GPIODEN_Pos)
#define RCC_AHB1ENR_GPIODEN			RCC_AHB1ENR_GPIODEN_Msk



#define RCC_APB2ENR_SYSCFGEN_Pos	(14U)
#define RCC_APB2ENR_SYSCFGEN_Msk	(0x1U << RCC_APB2ENR_SYSCFGEN_Pos)
#define RCC_APB2ENR_SYSCFGEN		RCC_APB2ENR_SYSCFGEN_Msk


#define RCC_APB2ENR_SPI1EN_Pos		(12U)
#define RCC_APB2ENR_SPI1EN_Msk		(0x1U << RCC_APB2ENR_SPI1EN_Pos)
#define RCC_APB2ENR_SPI1EN			RCC_APB2ENR_SPI1EN_Msk

#define RCC_APB1ENR_SPI2EN_Pos		(14U)
#define RCC_APB1ENR_SPI2EN_Msk		(0x1U << RCC_APB1ENR_SPI2EN_Pos)
#define RCC_APB1ENR_SPI2EN			RCC_APB1ENR_SPI2EN_Msk



#define RCC_APB2ENR_USART1EN_Pos	(4U)
#define RCC_APB2ENR_USART1EN_Msk	(0x1U << RCC_APB2ENR_USART1EN_Pos)
#define RCC_APB2ENR_USART1EN		RCC_APB2ENR_USART1EN_Msk

#define RCC_APB2ENR_USART6EN_Pos	(5U)
#define RCC_APB2ENR_USART6EN_Msk	(0x1U << RCC_APB2ENR_USART6EN_Pos)
#define RCC_APB2ENR_USART6EN		RCC_APB2ENR_USART6EN_Msk


#define RCC_APB1ENR_USART2EN_Pos	(17U)
#define RCC_APB1ENR_USART2EN_Msk	(0x1U << RCC_APB1ENR_USART2EN_Pos)
#define RCC_APB1ENR_USART2EN		RCC_APB1ENR_USART2EN_Msk

#define RCC_APB1ENR_USART3EN_Pos	(18U)
#define RCC_APB1ENR_USART3EN_Msk	(0x1U << RCC_APB1ENR_USART3EN_Pos)
#define RCC_APB1ENR_USART3EN		RCC_APB1ENR_USART3EN_Msk

#define RCC_APB1ENR_UART4EN_Pos		(19U)
#define RCC_APB1ENR_UART4EN_Msk		(0x1U << RCC_APB1ENR_UART4EN_Pos)
#define RCC_APB1ENR_UART4EN			RCC_APB1ENR_UART4EN_Msk

#define RCC_APB1ENR_UART5EN_Pos		(20U)
#define RCC_APB1ENR_UART5EN_Msk		(0x1U << RCC_APB1ENR_UART5EN_Pos)
#define RCC_APB1ENR_UART5EN			RCC_APB1ENR_UART5EN_Msk



#define SPI_SR_TxE					(1U)
#define SPI_SR_BSY					(7U)
#define SPI_SR_RxNE					(0U)

#define SPI_CR1_SPE					(6U)
#define SPI_CR1_DFF					(11U)

#define SPI_CR2_TXEIE				(7U)
#define SPI_CR2_RXNEIE				(6U)

#define SPI_TxE_FLAG				(0x1U << SPI_SR_TxE)
#define SPI_BSY_FLAG				(0x1U << SPI_SR_BSY)
#define SPI_RxNE_FLAG				(0x1U << SPI_SR_RxNE)



#define USART_SR_TxE				(7U)
#define USART_SR_RxNE				(5U)
#define USART_SR_TC					(6U)

#define USART_CR1_UE				(13U)
#define USART_CR1_TxEIE				(7U)
#define USART_CR1_RXNEIE			(5U)

#define USART_CR2_STOP				(12U)


#include "RCC.h"
#include "GPIO.h"
#include "EXTI.h"
#include "SPI.h"
#include "USART.h"
#endif /* INC_STM32F407XX_H_ */

