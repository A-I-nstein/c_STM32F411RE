#include "gpio.h"

bool btn_state;

int main (void)
{
    led_init();
    button_init();

    while(1)
    {
        btn_state = get_btn_state();

        if (btn_state)
        {
            led_on();
        }
        else {
            led_off();
        }
    }
}