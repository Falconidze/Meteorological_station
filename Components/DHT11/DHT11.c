

/************** MAKE CHANGES HERE ********************/
#include "stm32f4xx_hal.h"
#include "gpio.h"
#include "../Timer/timer.h"
#include "DHT11.h"

#define TYPE_DHT11    // define according to your sensor
//#define TYPE_DHT22








/*******************************************     NO CHANGES AFTER THIS LINE      ****************************************************/

uint8_t Rh_byte1, Rh_byte2, Temp_byte1, Temp_byte2;
uint16_t SUM; uint8_t Presence = 0;


dht_data_s_t dht_data_s;



dht_data_s_t dht_get_data()
{
	return dht_data_s;
}

void Set_Pin_Output (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}

void Set_Pin_Input (GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);
}


void DHT_Start (void)
{
	Set_Pin_Output (DHT11_GPIO_Port, DHT11_Pin);  // set the pin as output
	HAL_GPIO_WritePin (DHT11_GPIO_Port, DHT11_Pin, 0);   // pull the pin low

#if defined(TYPE_DHT11)
	timer_delay_us (18000);   // wait for 18ms
#endif

#if defined(TYPE_DHT22)
	timer_delay_us (1200);  // >1ms timer_delay_us
#endif

    HAL_GPIO_WritePin (DHT11_GPIO_Port, DHT11_Pin, 1);   // pull the pin high
    timer_delay_us (20);   // wait for 30us
	Set_Pin_Input(DHT11_GPIO_Port, DHT11_Pin);    // set as input
}

uint8_t DHT_Check_Response (void)
{
	uint8_t Response = 0;
	timer_delay_us (40);
	if (!(HAL_GPIO_ReadPin (DHT11_GPIO_Port, DHT11_Pin)))
	{
		timer_delay_us (80);
		if ((HAL_GPIO_ReadPin (DHT11_GPIO_Port, DHT11_Pin))) Response = 1;
		else Response = -1;
	}
	while ((HAL_GPIO_ReadPin (DHT11_GPIO_Port, DHT11_Pin)));   // wait for the pin to go low

	return Response;
}

uint8_t DHT_Read (void)
{
	uint8_t i,j;
	for (j=0;j<8;j++)
	{
		while (!(HAL_GPIO_ReadPin (DHT11_GPIO_Port, DHT11_Pin)));   // wait for the pin to go high
		timer_delay_us (40);   // wait for 40 us
		if (!(HAL_GPIO_ReadPin (DHT11_GPIO_Port, DHT11_Pin)))   // if the pin is low
		{
			i&= ~(1<<(7-j));   // write 0
		}
		else i|= (1<<(7-j));  // if the pin is high, write 1
		while ((HAL_GPIO_ReadPin (DHT11_GPIO_Port, DHT11_Pin)));  // wait for the pin to go low
	}
	return i;
}



void dht_check_sensor()
{
   DHT_Start ();
	Presence = DHT_Check_Response ();
	Rh_byte1 = DHT_Read ();
	Rh_byte2 = DHT_Read ();
	Temp_byte1 = DHT_Read ();
	Temp_byte2 = DHT_Read ();
	SUM = DHT_Read();

	if (SUM == (Rh_byte1+Rh_byte2+Temp_byte1+Temp_byte2))
	{
		#if defined(TYPE_DHT11)
			dht_data_s.temperature = Temp_byte1;
			dht_data_s.humidity = Rh_byte1;
		#endif

		#if defined(TYPE_DHT22)
			DHT_Data->Temperature = ((Temp_byte1<<8)|Temp_byte2);
			DHT_Data->Humidity = ((Rh_byte1<<8)|Rh_byte2);
		#endif
	}
}

void dht_init()
{
	timer_dht_init();
}
