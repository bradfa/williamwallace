CC = arm-none-eabi-gcc
CFLAGS = -ggdb -mthumb -mcpu=cortex-m0plus
LDFLAGS = -T MKL25Z128_flash.ld -nostartfiles -Xlinker -Map=blinky.map

all: blinky

blinky: blinky.o

blinky.o: blinky.c

.PHONY: clean
clean:
	rm -f blinky blinky.o blinky.map
