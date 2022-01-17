ENTRY(main)

HEAP_SIZE = 1024;

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 128K
  RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 48K

}

SECTIONS
{
	.text :
	{
		KEEP(*(.isr_vector))
 		*(.text)
 		*(.text.*)
		*(.rodata)
		*(.rodata.*)
		*(.rodata.str1.4)
		KEEP (*(.init))
        KEEP (*(.fini))
		_sidata = .;
	} >FLASH

	.ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    .ARM :
    {
        __exidx_start = .;
        *(.ARM.exidx*)
        __exidx_end = .;
    } > FLASH

    __end_code = .;
    
	/* Initialized data will initially be loaded in FLASH at the end of the .text section. */
    .data : AT (__end_code) 
    {
		_sdata = .;
		*(.data)		/* Initialized data */
		_edata = .;
	} >RAM

	.bss : {
		_sbss = .;
		*(.bss)         /* Zero-filled run time allocate data memory */
		_ebss = .;
	} >RAM
    
    .heap : AT(_ebss)
    {
        . = ALIGN(8);
        __end__ = .;
        PROVIDE(end = .);
        __HeapBase = .;
        . += HEAP_SIZE;
        __HeapLimit = .;
    } > RAM
    
    _estack = ORIGIN(RAM) + LENGTH(RAM);
 }  