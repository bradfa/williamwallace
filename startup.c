/* startup.c */

#include <stdint.h>

/* Addresses pulled in from the linker script */
extern uint32_t _end_stack;
extern uint32_t _end_text;
extern uint32_t _start_data;
extern uint32_t _end_data;
extern uint32_t _start_bss;
extern uint32_t _end_bss;

/* Application main() called in reset handler */
extern int main(void);

/* Cortex M interrupt handlers */
void Reset_Handler(void);
void NMI_Handler(void) __attribute__ ((weak, alias("Dummy_Handler")));

/* Stack top and vector handler table */
void *vector_table[] __attribute__ ((section(".vectors"))) = {
	&_end_stack,
	Reset_Handler,
	NMI_Handler,
	/* Other vectors go here, like faults */
};

void Reset_Handler(void) {
	uint8_t *src, *dst;

	/* Copy data section from Flash to RAM */
	src = (uint8_t *)&_end_text;
	dst = (uint8_t *)&_start_data;
	while (dst < (uint8_t *)&_end_data)
		*dst++ = *src++;

	/* Clear the bss section */
	dst = (uint8_t *)&_start_bss;
	while (dst < (uint8_t *)&_end_bss)
		*dst++ = 0;

	main();
}

void Dummy_Handler(void)
{
	while(1);
}
