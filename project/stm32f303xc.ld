MEMORY
{
  flash (rx) : ORIGIN = 0x08000000, LENGTH = 256K
  ram  (rwx) : ORIGIN = 0x20000000, LENGTH = 40K
}

__top_flash = ORIGIN(flash) + LENGTH(flash);
__top_ram = ORIGIN(ram) + LENGTH(ram);

ENTRY(irq_handler_reset)

SECTIONS
{
  .text : ALIGN(4)
  {
    FILL(0xff)
    KEEP(*(.vectors))
    *(.text*)
    *(.rodata)
    *(.rodata.*)
    . = ALIGN(4);
  } > flash

  . = ALIGN(4);
  _etext = .;

  .uninit_RESERVED : ALIGN(4)
  {
    KEEP(*(.bss.$RESERVED*))
  } > ram

  .data : ALIGN(4)
  {
    FILL(0xff)
    _data = .;
    *(.ramfunc .ramfunc.*);
    *(vtable)
    *(.data*)
    . = ALIGN(4);
    _edata = .;
  } > ram AT > flash

  .bss : ALIGN(4)
  {
    _bss = .;
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;
    PROVIDE(_end = .);
  } > ram

  PROVIDE(_msp = __top_ram);
}