#define UART0_BASE 0x10000000L

void start() 
{
    *(unsigned char *)UART0_BASE = ':';
}
