#include <mega8.h>
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x80
	.EQU __sm_mask=0x70
	.EQU __sm_powerdown=0x20
	.EQU __sm_powersave=0x30
	.EQU __sm_standby=0x60
	.EQU __sm_ext_standby=0x70
	.EQU __sm_adc_noise_red=0x10
	.SET power_ctrl_reg=mcucr
	#endif
#include <delay.h>

void main(void)
{

PORTB=0x02;
DDRB=0x01;

while (1)
{

if(PINB.1==0)
{
PORTB.0=1;
delay_ms(100);
PORTB.0=0;
delay_ms(100);
}

};
}
