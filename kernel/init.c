#include <stdint.h>
#define NCPU 8
/* Ny entrypoint */
void start() 
{
    *(uint8_t *)0x10000000L = '\n';
}
