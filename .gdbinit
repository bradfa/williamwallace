# For J-Link GDB debugging
target remote localhost:2331
monitor endian little
monitor reset
monitor flash device MKL25Z128xxx4
load blinky
file blinky
monitor sleep 1000
