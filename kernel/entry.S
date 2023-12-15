.section .text
.globl _start

_start:
    la sp, stack_top
    li a0, 1024*8
    add sp, sp, a0

    call start

loop:
    j loop

.section .bss
.align 8
stack_top:
    .space 8192
