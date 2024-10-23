
#ifndef INC_USART_H_
#define INC_USART_H_

#include "stm32f407xx.h"


#define USART_MODE_Tx				((uint32_t)(0x00000008))
#define USART_MODE_Rx				((uint32_t)(0x00000004))
#define USART_MODE_Tx_Rx			((uint32_t)(0x0000000C))

#define USART_WORDLENGTH_8Bits		((uint32_t)(0x00000000))
#define USART_WORDLENGTH_9Bits		((uint32_t)(0x00001000))

#define USART_PARITY_NONE 			((uint32_t)(0x00000000))
#define USART_PARITY_Even			((uint32_t)(0x00000400))
#define USART_PARITY_Odd			((uint32_t)(0x00000600))

#define USART_STOPBITS_1			((uint32_t)(0x00000000))
#define USART_STOPBITS_Half			((uint32_t)(0x00001000))
#define USART_STOPBITS_2			((uint32_t)(0x00002000))
#define USART_STOPBITS_1_Half		((uint32_t)(0x00003000))

#define USART_OVERSAMPLE_BY16		((uint32_t)(0x00000000))
#define USART_OVERSAMPLE_BY8		((uint32_t)(0x00008000))

#define USART_HW_NONE				((uint32_t)(0x00000000))
#define USART_HW_CTS				((uint32_t)(0x00000200))
#define USART_HW_RTS				((uint32_t)(0x00000100))
#define USART_HW_CTS_RTS			((uint32_t)(0x00000300))

typedef enum
{
	USART_BUS_FREE = 0x0U,
	USART_BUS_Tx   = 0x1U,
	USART_BUS_Rx   = 0x2U,

}USART_BusState_t;

#define __USART_DIV_VALUE_16(__CLOCK__ , __BAUDRATE__)				(25U * (uint32_t)(__CLOCK__) / (4U * (__BAUDRATE__)))
#define __USART_DIV_VALUE_8(__CLOCK__ , __BAUDRATE__)				(25U * (uint32_t)(__CLOCK__) / (2U * (__BAUDRATE__)))

typedef struct
{
	uint32_t BaudRate;
	uint32_t OverSampling;
	uint32_t WordLength;
	uint32_t Parity;
	uint32_t StopBits;
	uint32_t HardwareFlowControl;
	uint32_t Mode;

}USART_InitTypedef_t;



typedef struct __USART_HandleTypedef_t
{
	USART_TypeDef_t *Instance;
	USART_InitTypedef_t Init;

	uint8_t *pTxBuffer;
	int16_t TxBufferSize;
	uint8_t TxStatus;
	void (*TxISR_Function)(struct __USART_HandleTypedef_t *USART_Handle);

	uint8_t *pRxBuffer;
	int16_t RxBufferSize;
	uint8_t RxStatus;
	void (*RxISR_Function)(struct __USART_HandleTypedef_t *USART_Handle);

}USART_HandleTypedef_t;

void USART_Init(USART_HandleTypedef_t *USART_Handle);
void USART_PeriphCmd(USART_HandleTypedef_t *USART_Handle, FunctionalState_t stateOfUSART);
void USART_TransmitData(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
void USART_TransmitData_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pData, uint16_t dataSize);
void USART_ReceiveData(USART_HandleTypedef_t *USART_Handle, uint8_t *pBuffer, uint16_t dataSize);
void USART_ReceiveData_IT(USART_HandleTypedef_t *USART_Handle, uint8_t *pBuffer, uint16_t dataSize);
void USART_InterruptHandler(USART_HandleTypedef_t *USART_Handle);


#endif /* INC_USART_H_ */
