ENTRY(Reset_Handler)

/* Memory configuration for KL25Z128 */

MEMORY
{
    flash   :   ORIGIN = 0x00000000, LENGTH = 128k
    sram    :   ORIGIN = 0x1FFFF000, LENGTH = 16k
}

_end_stack = 0x20002FFC;

SECTIONS {
    . = ORIGIN(flash);

    vectors :
    {
        *(.vectors)
    } >flash

    .text :
    {
        *(.text)
        *(.rodata)
        *(.rodata*)
        _end_text = .;
    } >flash

    .data :
    {
        _start_data = .;
        *(.data)
        _end_data = .;
    } >sram AT >flash

    . = ALIGN(4);

    .bss :
    {
        _start_bss = .;
        *(.bss)
        _end_bss = .;
    } >sram

    . = ALIGN(4);

    _start_stack = .;
}

_end = .;
PROVIDE(end = .);
