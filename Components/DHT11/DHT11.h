/*
 * DHT.h
 *
 *  Created on: Jun 28, 2020
 *      Author: Controllerstech.com
 */
#include "stdint.h"
#ifndef DHT11_H_
#define DHT11_H_

typedef struct
{
	int8_t temperature;
	int8_t humidity;
}dht_data_s_t;





void dht_check_sensor();
dht_data_s_t dht_get_data();
#endif /* DHT11_H */

void dht_init();