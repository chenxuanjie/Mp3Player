#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Music.h"

int main(void)
{
	Music_Init();
	Delay_ms(500);
	Play_Music(1);
	Delay_ms(2500);
	Play_Music(2);
	while(1)
	{
		
	}
}
