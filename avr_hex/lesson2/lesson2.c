#include <mega8.h>
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