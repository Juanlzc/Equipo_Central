#include "delay.h"
#include "freertos/FreeRTOS.h"
#include "xtensa/hal.h"
//#include "xtensa/hal.h"

void delay_us(unsigned int time_us)//lleva de argumento el tiempo en us de delay requerido
{	
	uint32_t cuenta_anterior=0;
	uint32_t cuenta_actual;
	uint32_t delta_cuentas=0;
	cuenta_actual= xthal_get_ccount(); //cuenta actual
	cuenta_anterior=cuenta_actual;
	while(delta_cuentas<=us_to_counts(time_us)){
			cuenta_actual=xthal_get_ccount();
			if(cuenta_actual>cuenta_anterior){ //si no hubo overflow en ccount
				delta_cuentas= cuenta_actual-cuenta_anterior;
		
			}else{
			delta_cuentas= (0xffffffff-cuenta_anterior)+cuenta_actual;
			
			}
			cuenta_anterior=cuenta_actual;
		}
}
