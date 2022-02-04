#include "ioport.h"

int main(void)
{
    uint32_t value = Read_32();
    // Write a 32 bit value to the 32 bit port
    Write_32(value);
    return 0;
}