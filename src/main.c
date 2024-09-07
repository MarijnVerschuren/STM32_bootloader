#include "types.h"
#include "periph.h"


static volatile uint32_t* RCC_AHB1ENR =	(uint32_t*)(RCC + 0x30);
static volatile uint32_t* GPIOC_MODER =	(uint32_t*)(GPIOC);
static volatile uint32_t* GPIOC_BSRR =	(uint32_t*)(GPIOC + 0x18);
static volatile uint32_t* GPIOA_MODER =	(uint32_t*)(GPIOA);
static volatile uint32_t* GPIOA_BSRR =	(uint32_t*)(GPIOA + 0x18);

#define PIN 13

// application
void main_app(void) {
	(*RCC_AHB1ENR) |= (0x1 << 2) | 0x1;
	(*GPIOC_MODER) |= 0x1 << (2*PIN);
	// double x = 0.0;
	// double y = 0.0;
	while (1) {
		// y = sin(x);
		// x += y;
		(*GPIOC_BSRR) = 0x1 << PIN;
		//for (uint32_t i = 0; i < 0xFFFF; i++) { (void)i; }
		(*GPIOC_BSRR) = 0x10000 << PIN;
	}
}
