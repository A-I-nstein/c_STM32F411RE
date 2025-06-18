#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f4xx.h"

#include <stdbool.h>

void led_init(void);
void led_on(void);
void led_off(void);

void button_init(void);
bool get_btn_state(void);

#endif