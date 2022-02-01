#include <avr/io.h>     
#include <util/delay.h>

void Write_32(uint32_t value)
{
    // sets pins connected to Bffr_Flpflp_Select signals as output (sets PB0 to PB3 as output)
    /*
     * PB2 : Bffr_Flpflp_Select_0
     * PB1 : Bffr_Flpflp_Select_1
     * PB0 : Bffr_Flpflp_Select_2
     */
    DDRB |= 0x0F;

    // selects the first 74LS374 (clears PORTB)
    /*
     * Bffr_Flpflp_Select_0 = 0
     * Bffr_Flpflp_Select_1 = 0
     * Bffr_Flpflp_Select_2 = 0
     */
    PORTB = 0x00;

    // sets write signal HIGH (sets PB3 = 1)
    PORTB |= 0x08;

    // sets pins connected to Data signals as output (sets PD0 to PD7 as output)
    /*
     * PD7 : Data_7
     * PD6 : Data_6
     * PD5 : Data_5
     * PD4 : Data_4
     * PD3 : Data_3
     * PD2 : Data_2
     * PD1 : Data_1
     * PD0 : Data_0
     */
    DDRD |= 0xFF;

    // write from Data_0 to Data_7
    PORTD = value & 0xFF;

    // waits for 1 second (waits until the next clock edge)
    _delay_ms(1000);

    // selects the second 74LS374 (sets PB1 = 1)
    /*
     * Bffr_Flpflp_Select_0 = 0
     * Bffr_Flpflp_Select_1 = 1
     * Bffr_Flpflp_Select_2 = 0
     */
    PORTB |= 0x02;

    // write from Data_8 to Data_15
    PORTD = (value >> 8) & 0xFF;

    // wait for 1 seconds
    _delay_ms(1000);

    // clears Bffr_Flpflp_Select_1 (sets PB1 = 0)
    PORTB &= 0xF8;

    // selects the third 74LS374 (sets PB2 = 1)
    /*
     * Bffr_Flpflp_Select_0 = 0
     * Bffr_Flpflp_Select_1 = 0
     * Bffr_Flpflp_Select_2 = 1
     */
    PORTB |= 0x04;

    // write from Data_16 to Data_23
    PORTD = (value >> 16) & 0xFF;

    // wait for 1 seconds
    _delay_ms(1000);

    // selects the fourth 74LS374 (sets PB1 = 1)
    /*
     * Bffr_Flpflp_Select_0 = 0
     * Bffr_Flpflp_Select_1 = 1
     * Bffr_Flpflp_Select_2 = 1
     */
    PORTB |= 0x02;

    // write from Data_24 to Data_31
    PORTD = (value >> 24) & 0xFF;

    // wait for 1.5 seconds
    _delay_ms(1500);
}