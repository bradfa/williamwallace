William Wallace
===============

A very simple red blinken' light on the [FRDM-KL25Z][0] dev kit from Freescale.

Build with [gcc-arm-embedded][1] and load with [J-Link][2], an [Olimex
adapter][3], [J-Link's GDB server][4] and GDB.

To do this, you'll need to modify the FRDM board to remove the OpenSDA circuit
and add the SWD header.  Removing U6, the OpenSDA micro, is best done with a
hot-air rework station.  Adding J6, the SWD header, can use any through hole 5x2
0.05" header.

<img src="./removesda.jpg" />

Launch the GDB server using SWD interface:

```
andrew@boomboom:~/git/williamwallace$ JLinkGDBServer -if SWD
SEGGER J-Link GDB Server V4.80 Command Line Version

JLinkARM.dll V4.80 (DLL compiled Dec 20 2013 19:40:51)

-----GDB Server start settings-----
GDBInit file:                  none
GDB Server Listening port:     2331
SWO raw output listening port: 2332
Terminal I/O port:             2333
Accept remote connection:      yes
Generate logfile:              off
Verify download:               off
Init regs on start:            on
Silent mode:                   off
Single run mode:               off
------J-Link related settings------
J-Link script:                 none
Target interface:              SWD
Host interface:                USB
Target endian:                 little
Target interface speed:        1000kHz

Connecting to J-Link...
J-Link is connected.
Firmware: J-Link V9 compiled Dec 11 2013 19:48:51
Hardware: V9.00
S/N: 59103643
Feature(s): GDB
Checking target voltage...
Listening on TCP/IP port 2331
Connecting to target...Connected to target
Waiting for GDB connection...
```

Connect to the GDB server with gdb:

```
andrew@boomboom:~/git/williamwallace$ arm-none-eabi-gdb localhost:2331
GNU gdb (GNU Tools for ARM Embedded Processors) 7.6.0.20131129-cvs
Copyright (C) 2013 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "--host=x86_64-unknown-linux-gnu --target=arm-none-eabi".
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>...
localhost:2331: No such file or directory.
0x00000000 in ?? ()
Target endianess set to "little endian"
Resetting target
Selecting device: MKL25Z128xxx4
Loading section .text, size 0xa0 lma 0x800
Loading section .romp, size 0x18 lma 0x8a0
Start address 0x800, load size 184
Transfer rate: 1472 bits in <1 sec, 92 bytes/write.
Sleep 1000ms
(gdb)
```

[0]: http://www.element14.com/community/docs/DOC-54879
[1]: https://launchpad.net/gcc-arm-embedded
[2]: http://www.segger.com/debug-probes.html
[3]: https://www.olimex.com/Products/ARM/JTAG/ARM-JTAG-20-10/
[4]: http://www.segger.com/jlink-gdb-server.html
