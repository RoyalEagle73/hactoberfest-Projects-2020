#include<avr/io.h>
#include<avr/interrupt.h>
#include<avr/delay.h>

int main(void){
  DDRB|=(1<<PORTB5);    //declare pin 13 as output
  while(1){
    PORTB^=(1<<PORTB5); //toggle pin 13
    _delay_ms(1000);    //delay of 1 second
  }
}
