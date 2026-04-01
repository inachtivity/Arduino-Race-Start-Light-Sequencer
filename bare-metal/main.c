#define __AVR_ATmega328P__

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define MAX 3000
#define MIN 200

int main(void)
{

    int randomNum, counter;

    // set pins 13 -> 9 as output
    DDRB = 0b111110;

    // set pin 2 as input
    DDRD &= ~(1 << DDD2) ;

    srand(TCNT0);
    while(1){

        if ( ( PIND & (1 << PIND2) ) ){
            counter = 0;
            randomNum = rand() % (MAX - MIN + 1) + MIN;

            // sets PORTB5 to high
            PORTB = PORTB | (1 << PORTB5);
            
            _delay_ms(1000);
            
            PORTB = PORTB | (1 << PORTB4);

            _delay_ms(1000);
            
            PORTB = PORTB | (1 << PORTB3);

            _delay_ms(1000);
            
            PORTB = PORTB | (1 << PORTB2);

            _delay_ms(1000);
            
            PORTB = PORTB | (1 << PORTB1);
            
            while (counter < randomNum) {
                _delay_ms(1);   
                counter++;
            }
            
            // unset PORTB -> turns off the leds
            PORTB = 0;

            _delay_ms(1000);
        } else {
            PORTB = 0;
        }

    }

}