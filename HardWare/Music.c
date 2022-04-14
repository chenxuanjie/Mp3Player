#include "stm32f10x.h"                  // Device header
#include "Music.h"
#include "Delay.h"

void Music_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
}

void Music_SendData(uint8_t Data)
{
	uint8_t i;
	GPIO_SetBits(GPIOA, GPIO_Pin_0);
	Delay_ms(1);
	GPIO_ResetBits(GPIOA, GPIO_Pin_0);
	Delay_ms(3);	//先拉低2ms以上
	for(i = 0; i < 8; i ++)		//循环发送
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		if((Data&0x01) == 1)
		{
			Delay_us(500);
			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			Delay_us(210);			
		}
		else
		{
			Delay_us(210);
			GPIO_ResetBits(GPIOA, GPIO_Pin_0);
			Delay_us(500);						
		}
		Data >>= 1;
	}
	GPIO_SetBits(GPIOA, GPIO_Pin_0);		
}

void Play_Music(uint8_t Data)
{
	Music_SendData(0x0a);
	Music_SendData(Data);
	Music_SendData(0x0b);
}
