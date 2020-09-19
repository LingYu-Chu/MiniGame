/* Default linker script, for normal executables */
OUTPUT_FORMAT("elf32-nds32", "elf32-nds32", "elf32-nds32")
OUTPUT_ARCH(nds32)
ENTRY(_start)

/* _ILM_BASE = 0x01000000; */ /* ILM base address */
/* _DLM_BASE = 0x04000000; */ /* DLM base address */
/* _ILM_SIZE = 0x10000;    */ /* 64Kb*/
/* _DLM_SIZE = 0x10000;    */ /* 64Kb*/
/* _ILM_SIZE = 0x2000; 	   */ /* 8Kb */
/* _DLM_SIZE = 0x2000;     */ /* 8Kb */
/* _DLM_STACK = _DLM_BASE + _DLM_SIZE; *//* stack address */


MEMORY
{
  /* first! be the default VMA/LMA base put at */
  RAM (awx) : ORIGIN = 0x00100000, LENGTH = 8K
  ROM (arx) : ORIGIN = 0x00000000, LENGTH = 64K
}

SECTIONS
{
  /* Read-only sections, merged into text segment: */
  PROVIDE (__executable_start = ORIGIN(ROM)); . = ORIGIN(RAM);
  .nds32_init ORIGIN(ROM) : { *(.nds32_init) } > ROM AT> ROM
  .init ORIGIN(RAM) :
  {
    KEEP (*(.init))
  } > RAM AT> ROM =0
  .plt            : { *(.plt) } > RAM AT> ROM
  .text           :
  {
    *(.text .stub .text.* .gnu.linkonce.t.*)
    KEEP (*(.text.*personality*))
    /* .gnu.warning sections are handled specially by elf32.em.  */
    *(.gnu.warning)
  } > ROM
  .fini           :
  {
    KEEP (*(.fini))
  } > ROM
  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  .rodata         : { *(.rodata .rodata.* .gnu.linkonce.r.*) } > ROM
  .rodata1        : { *(.rodata1) } > ROM
  .sdata2         : { *(.sdata2 .sdata2.* .gnu.linkonce.s2.*) } > ROM
  .sbss2          : { *(.sbss2 .sbss2.* .gnu.linkonce.sb2.*) } > ROM
  .eh_frame_hdr : { *(.eh_frame_hdr) } > ROM
  .eh_frame       : ONLY_IF_RO { KEEP (*(.eh_frame)) } > ROM
  .gcc_except_table   : ONLY_IF_RO { KEEP (*(.gcc_except_table)) *(.gcc_except_table.*) } > ROM
  /* Adjust the address for the data segment.  We want to adjust up to
     the same address within the page on the next page up.  */
  /*. = ALIGN (0x20) - ((0x20 - .) & (0x20 - 1)); . = DATA_SEGMENT_ALIGN (0x20, 0x20);*/
 /* . = ALIGN (0x1000) - ((0x1000 - .) & (0x1000 - 1)); . = DATA_SEGMENT_ALIGN (0x1000, 0x1000); */
  /* Exception handling  */
  .eh_frame       : ONLY_IF_RW { KEEP (*(.eh_frame)) } > RAM AT> ROM
  .gcc_except_table   : ONLY_IF_RW { KEEP (*(.gcc_except_table)) *(.gcc_except_table.*) } > RAM AT> ROM
  /* Thread Local Storage sections  */
  .tdata	  : { *(.tdata .tdata.* .gnu.linkonce.td.*) } > RAM AT> ROM
  .tbss		  : { *(.tbss .tbss.* .gnu.linkonce.tb.*) *(.tcommon) } > RAM AT> ROM
  /* Ensure the __preinit_array_start label is properly aligned.  We
     could instead move the label definition inside the section, but
     the linker would then create the section even if it turns out to
     be empty, which isn't pretty.  */
  . = ALIGN(32 / 8);
  PROVIDE (__preinit_array_start = .);
  .preinit_array     : { KEEP (*(.preinit_array)) } > RAM AT> ROM
  PROVIDE (__preinit_array_end = .);
  PROVIDE (__init_array_start = .);
  .init_array     : { KEEP (*(.init_array)) } > RAM AT> ROM
  PROVIDE (__init_array_end = .);
  PROVIDE (__fini_array_start = .);
  .fini_array     : { KEEP (*(.fini_array)) } > RAM AT> ROM
  PROVIDE (__fini_array_end = .);
  .ctors          :
  {
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin*.o(.ctors))
    /* We don't want to include the .ctor section from
       from the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend*.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
  } > RAM AT> ROM
  .dtors          :
  {
    KEEP (*crtbegin*.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend*.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  } > RAM AT> ROM
  .jcr            : { KEEP (*(.jcr)) } > RAM AT> ROM
  .data.rel.ro : { *(.data.rel.ro.local) *(.data.rel.ro*) } > RAM AT> ROM
  .dynamic        : { *(.dynamic) } > RAM AT> ROM
 /* . = DATA_SEGMENT_RELRO_END (0, .); */
  PROVIDE (_data = .);
  __data_lmastart = LOADADDR (.rodata) + SIZEOF (.rodata);
  .data           :
  {
    __data_start = .;
    *(.data .data.* .gnu.linkonce.d.*)
    KEEP (*(.gnu.linkonce.d.*personality*))
    SORT(CONSTRUCTORS)
  } > RAM AT> ROM
  .data1          : { *(.data1) } > RAM AT> ROM =0
  . = ALIGN(4);
  .got            : { *(.got.plt) *(.got) } > RAM AT> ROM =0
  /* We want the small data sections together, so single-instruction offsets
     can access them all, and initialized data all before uninitialized, so
     we can shorten the on-disk segment size.  */
  .sdata_d          :
  {
    *(.sdata_d .sdata_d.*)
  } > RAM AT> ROM =0
  .sdata_w          :
  {
    *(.sdata_w .sdata_w.*)
  } > RAM AT> ROM =0
  .sdata_h          :
  {
    *(.sdata_h .sdata_h.*)
  } > RAM AT> ROM =0
  .sdata_b          :
  {
    *(.sdata_b .sdata_b.*)
  } > RAM AT> ROM =0
  .sdata_f          :
  {
    *(.sdata_f .sdata_f.*)
  } > RAM AT> ROM =0
  _edata = .;
  PROVIDE (edata = .);
  PROVIDE (_bstart = .);
  __bss_start = .;
  .sbss_f           :
  {
    PROVIDE (__sbss_start = .);
    PROVIDE (___sbss_start = .);
    *(.sbss_f .sbss_f.*)
    *(.scommon_f .scommon_f.*)
  } > RAM =0
  .sbss_b           :
  {
    *(.sbss_b .sbss_b.*)
    *(.scommon_b .scommon_b.*)
    . = ALIGN(2);
  } > RAM =0
  .sbss_h           :
  {
    *(.sbss_h .sbss_h.*)
    *(.scommon_h .scommon_h.*)
    . = ALIGN(4);
  } > RAM =0
  .sbss_w           :
  {
    *(.sbss_w .sbss_w.*)
    *(.scommon_w .scommon_w.*)
    *(.dynsbss)
    *(.scommon)
    PROVIDE (__sbss_end = .);
    PROVIDE (___sbss_end = .);
  } > RAM =0
  .bss            :
  {
   *(.dynbss)
   *(.bss .bss.* .gnu.linkonce.b.*)
   *(COMMON)
   /* Align here to ensure that the .bss section occupies space up to
      _end.  Align after .bss to ensure correct alignment even if the
      .bss section disappears because there are no input sections.  */
   . = ALIGN(32 / 8);
  } > RAM =0
  . = ALIGN(32 / 8);
  PROVIDE (_bend = .);
  _end = .;
  _lmaend = LOADADDR(.bss) + SIZEOF(.bss);
  PROVIDE (end = .);
 /* . = DATA_SEGMENT_END (.); */
  /* Stabs debugging sections.  */
  .stab          0 : { *(.stab) }
  .stabstr       0 : { *(.stabstr) }
  .stab.excl     0 : { *(.stab.excl) }
  .stab.exclstr  0 : { *(.stab.exclstr) }
  .stab.index    0 : { *(.stab.index) }
  .stab.indexstr 0 : { *(.stab.indexstr) }
  .comment       0 : { *(.comment) }
  /* DWARF debug sections.
     Symbols in the DWARF debugging sections are relative to the beginning
     of the section so we begin them at 0.  */
  /* DWARF 1 */
  .debug          0 : { *(.debug) }
  .line           0 : { *(.line) }
  /* GNU DWARF 1 extensions */
  .debug_srcinfo  0 : { *(.debug_srcinfo) }
  .debug_sfnames  0 : { *(.debug_sfnames) }
  /* DWARF 1.1 and DWARF 2 */
  .debug_aranges  0 : { *(.debug_aranges) }
  .debug_pubnames 0 : { *(.debug_pubnames) }
  /* DWARF 2 */
  .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
  .debug_abbrev   0 : { *(.debug_abbrev) }
  .debug_line     0 : { *(.debug_line) }
  .debug_frame    0 : { *(.debug_frame) }
  .debug_str      0 : { *(.debug_str) }
  .debug_loc      0 : { *(.debug_loc) }
  .debug_macinfo  0 : { *(.debug_macinfo) }
  /* SGI/MIPS DWARF 2 extensions */
  .debug_weaknames 0 : { *(.debug_weaknames) }
  .debug_funcnames 0 : { *(.debug_funcnames) }
  .debug_typenames 0 : { *(.debug_typenames) }
  .debug_varnames  0 : { *(.debug_varnames) }
  /* PROVIDE (_stack = 0x13000000); */
  PROVIDE (_stack = ORIGIN(RAM) + LENGTH(RAM));
  /*PROVIDE (_stack = (_DLM_STACK)); */
  /*PROVIDE (_stack = 0x02000000); */
  /DISCARD/ : { *(.note.GNU-stack) } > RAM AT> ROM
}
