
#include "stm32f407xx.h"

static void GPIO_LedConfig();
//static void LockControl();
static void GPIO_ButtonInterruptConfig();
static void SPI_Config();
static void SPI_GPIO_Config();

SPI_HandleTypedef_t SPI_Handle;
char sendData[] = "cristiano ronaldo, siuuuu\n";

void EXTI0_IRQHandler()
{
	if(EXTI->PR & 0x1U)
	{
		EXTI->PR |= (0x1U << 0U);
		SPI_TransmitData_IT(&SPI_Handle, (uint8_t*)sendData, strlen(sendData));
	}
}

void SPI1_IRQHandler()
{
	SPI_InterruptHandler(&SPI_Handle);
}


int main(void)
{
	GPIO_LedConfig();
	GPIO_ButtonInterruptConfig();
	SPI_GPIO_Config();   //once bu konfigur edilir, pa5 ve pa7 AF modda tanimlandi
	SPI_Config();

	/*
	GPIO_WritePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_15, GPIO_Pin_Set);
	GPIO_TogglePin(GPIOD, GPIO_PIN_14);*/

	//GPIO_LockPin(GPIOA, GPIO_PIN_0);
	//LockControl();

	for(;;)
	{

	}
}


static void GPIO_LedConfig()
{
	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

	RCC_GPIOD_CLK_ENABLE(); 	// Clock is active
	RCC_GPIOA_CLK_ENABLE(); 	// Clock is active
	//RCC_SYSCFG_CLK_ENABLE();	// Clock is active

	GPIO_InitStruct.pinNumber = GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_15 | GPIO_PIN_14;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOD, &GPIO_InitStruct); // readpin için başka uygulama

	memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct));

	GPIO_InitStruct.pinNumber = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.PuPd = GPIO_PUPD_PULLDOWN;

	GPIO_Init(GPIOA, &GPIO_InitStruct);


	//EXTI_LineConfig(EXTI_PortSource_GPIOC, EXTI_LineSource_7);

}

/*static void LockControl()
{
	GPIO_InitTypeDef_t GPIO_InitStruct = {0};

	GPIO_InitStruct.pinNumber = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

}*/

static void GPIO_ButtonInterruptConfig()
{
	RCC_SYSCFG_CLK_ENABLE();
	EXTI_InitTypeDef_t EXTI_InitStruct = {0};

	EXTI_LineConfig(EXTI_PortSource_GPIOA, EXTI_LineSource_0);

	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_LineNumber = EXTI_LineSource_0;
	EXTI_InitStruct.EXTI_Mode = EXTI_MODE_Interrupt;
	EXTI_InitStruct.TriggerSelection = EXTI_Trigger_Rising;

	EXTI_Init(&EXTI_InitStruct);

	NVIC_EnableInterrupt(EXTI0_IRQNumber);
	NVIC_EnableInterrupt(SPI1_IRQNumber);

};

static void SPI_Config()
{
	//SPI_HandleTypedef_t SPI_Handle = {0}; globalde tanimlanmasi gerek
	RCC_SPI1_CLK_ENABLE();

	SPI_Handle.Instance = SPI1;
	SPI_Handle.Init.BaudRate = SPI_BAUDRATE_DIV8;
	SPI_Handle.Init.BusConfig = SPI_BUS_FULLDUPLEX;
	SPI_Handle.Init.CPHA = SPI_CPHA_FIRST;
	SPI_Handle.Init.CPOL = SPI_CPOL_LOW;
	SPI_Handle.Init.DFF_Format = SPI_DFF_8BITS;
	SPI_Handle.Init.FrameFormat = SPI_FRAMEFORMAT_MSB;
	SPI_Handle.Init.Mode = SPI_MODE_MASTER;
	SPI_Handle.Init.SSM_Cmd = SPI_SSM_ENABLE;

	SPI_Init(&SPI_Handle);
	SPI_PeriphCmd(&SPI_Handle, ENABLE);


};

static void SPI_GPIO_Config()
{
	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	GPIO_InitStruct.pinNumber = GPIO_PIN_7 | GPIO_PIN_5;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.Mode = GPIO_MODE_AF;
	GPIO_InitStruct.Alternate = GPIO_AF5;

	GPIO_Init(GPIOA, &GPIO_InitStruct);
};
