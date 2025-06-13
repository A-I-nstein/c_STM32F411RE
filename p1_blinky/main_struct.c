#include <stdint.h>

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_TypeDef;

typedef struct
{
    volatile uint32_t DUMMY[12];
    volatile uint32_t AHB1ENR;
} RCC_TypeDef;

#define RCC_BASE    0x40023800
#define GPIOA_BASE  0x40020000
#define RCC         ((RCC_TypeDef*) RCC_BASE)
#define GPIOA       ((GPIO_TypeDef*) GPIOA_BASE)
#define GPIOAEN     (1U<<0)
#define PIN5        (1U<<5)
#define LED_PIN     PIN5

int main (void) {
    RCC->AHB1ENR |= GPIOAEN;
    GPIOA->MODER |= (1U<<10);
    GPIOA->MODER &= ~(1U<<11);

    while (1)
    {
        GPIOA->ODR ^= LED_PIN;
        for (int i=0; i<10000000; i++) {}
    }
}