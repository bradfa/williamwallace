#include "MKL25Z4.h"

#define BLINK_DELAY     (1000000)

#define RED		(18)
#define RED_SHIFT	(1 << 18)
#define RED_OFF		(GPIOB_PSOR = RED_SHIFT)
#define RED_ON		(GPIOB_PCOR = RED_SHIFT)

void delay_time(int number)
{
	int cnt;
	for (cnt = 0; cnt < number; cnt++);
}

int main (void)
{
	/* Initialize the Red LED (PTB18) */

	/* Turn on clock to PortB module */
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;

	/* Set the PTB18 pin multiplexer to GPIO mode */
	PORTB_PCR18 = PORT_PCR_MUX(1);

	/* Set the initial output state to high */
	GPIOB_PSOR |= RED_SHIFT;

	/* Set the pins direction to output */
	GPIOB_PDDR |= RED_SHIFT;

	while (1) {
		RED_ON;
		delay_time(BLINK_DELAY);
		RED_OFF;
		delay_time(BLINK_DELAY);
	}
}

void _exit(int status)
{
	while (1);
}
