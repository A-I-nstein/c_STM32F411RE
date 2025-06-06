#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL)
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET		(0x00000000UL)
#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)
#define RCC_OFFSET			(0x00003800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)
#define AHB1EN_R_OFFSET		(0x00000030UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
#define MODE_R_OFFSET		(0x00000000UL)
#define GPIOA_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
#define OD_R_OFFSET			(0x00000014UL)
#define GPIOA_OD_R			(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

// #define RCC_AHB1EN_R		(*(volatile unsigned int *)(0x40023830UL))
// #define GPIOA_MODE_R		(*(volatile unsigned int *)(0x40020000UL))
// #define GPIOA_OD_R			(*(volatile unsigned int *)(0x40020014UL))

#define GPIOAEN				(1U<<0)
#define PIN5				(1U<<5)
#define LED_PIN				PIN5

int main (void) {
	RCC_AHB1EN_R |= GPIOAEN;
	GPIOA_MODE_R |= (1U << 10);
	GPIOA_MODE_R &= ~(1U << 11);

	while(1) {
		GPIOA_OD_R ^= LED_PIN;
		for(int i = 0; i < 100000; i++) {}
	}
}
