# For J-Link GDB debugging
target remote localhost:2331
monitor endian little
monitor reset
monitor flash device MKL25Z128xxx4
load blinky
file blinky
monitor sleep 1000
# r13 is stack pointer, hard code for now
# sp and pc values found from output map file, for now
monitor reg r13 = 0x20003000
monitor reg pc = 0x800
