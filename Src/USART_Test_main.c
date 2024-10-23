
#include "stm32f407xx.h"

USART_HandleTypedef_t USART_Handle;
static void UART_Config(void);
static void GPIO_Config(void);
uint8_t rxCompleteFlag;




void USART2_IRQHandler()
{
	USART_InterruptHandler(&USART_Handle);

    if (USART_Handle.RxStatus == USART_BUS_FREE)
    {
        rxCompleteFlag = 1;
    }
}

int main(void)
{
	char rData[10] = { 0 };
	GPIO_Config();
	UART_Config();

	//USART_TransmitData_IT(&USART_Handle,(uint8_t*)dataSend, sizeof(dataSend));
	USART_ReceiveData_IT(&USART_Handle,(uint8_t*)rData, 10);
	//USART_ReceiveData(&USART_Handle, (uint8_t*)dataSend, 10);

    while (!rxCompleteFlag) {
        // Bekle veya diğer işlemleri yap
    }

	USART_TransmitData_IT(&USART_Handle,(uint8_t*)rData, strlen(rData));
	//USART_TransmitData(&USART_Handle, (uint8_t*)rData, strlen(rData));

	while(1)
	{

	}
}

static void UART_Config(void)
{
	RCC_USART2_CLK_ENABLE();

	USART_Handle.Instance = USART2;
	USART_Handle.Init.BaudRate = 115200;
	USART_Handle.Init.HardwareFlowControl = USART_HW_NONE;
	USART_Handle.Init.Mode = USART_MODE_Tx_Rx;
	USART_Handle.Init.OverSampling = USART_OVERSAMPLE_BY16;
	USART_Handle.Init.Parity = USART_PARITY_NONE;
	USART_Handle.Init.StopBits = USART_STOPBITS_1;
	USART_Handle.Init.WordLength = USART_WORDLENGTH_8Bits;

	USART_Init(&USART_Handle);
	USART_PeriphCmd(&USART_Handle, ENABLE);

	NVIC_EnableInterrupt(USART2_IRQNumber);
}

static void GPIO_Config(void)
{
	RCC_GPIOA_CLK_ENABLE();
	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	GPIO_InitStruct.pinNumber = GPIO_PIN_2 | GPIO_PIN_3;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Otype = GPIO_OTYPE_PP;
	GPIO_InitStruct.Mode = GPIO_MODE_AF;
	GPIO_InitStruct.Alternate = GPIO_AF7;

	GPIO_Init(GPIOA, &GPIO_InitStruct);
};
