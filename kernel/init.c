/* Ny entrypoint */
void start() 
{
    *(unsigned char *)0x10000000L = ':';
    *(unsigned char *)0x10000000L = '\n';
}
