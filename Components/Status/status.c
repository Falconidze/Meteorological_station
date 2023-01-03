#include <stdint.h>
#include "status.h"

static uint16_t status;

void status_init()
{
	status = 0x0000;
}

void status_set(uint16_t data)
{
	status = data;	
}

uint16_t status_get(void)
{
	return status;
}