#include "ioport.h"

int main(void)
{
    // Reads a 32 bit value from the 32 bit port
    int32_t value = Read_32();

    // Prints the value
    printf("%d\n", value);

    return 0;
}