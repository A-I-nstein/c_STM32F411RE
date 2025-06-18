#include "gpio.h"

#define GPIOAEN     (1U<<0)
#define LED_BS5     (1U<<5)
#define LED_BR5     (1U<<21)

#define GPIOCEN     (1U<<2)
#define BTN_PIN     (1U<<13)

void led_init(void)
{
    // enable clock access to GPIOA
    RCC->AHB1ENR |= GPIOAEN;

    // set PA5 mode to output
    GPIOA->MODER |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);
}

void led_on(void)
{
    // set PA5 high
    GPIOA->BSRR |= LED_BS5;
}

void led_off(void)
{
    // set PA5 low
    GPIOA->BSRR |= LED_BR5;
}

void button_init(void)
{
    // enable clock access to GPIOC
    RCC->AHB1ENR |= GPIOCEN;

    // set PC13 as an input pin
    GPIOA->MODER &= ~(1U<<26);
    GPIOA->MODER &= ~(1U<<27);
}

bool get_btn_state(void)
{
    // BTN is active low
    // check if BTN is pressed
    if (GPIOC->IDR & BTN_PIN) 
    {
        return false;
    }
    else 
    {
        return true;
    }
}