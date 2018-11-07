#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main()
{
    const unsigned int MB = 1024 * 1024;
    const unsigned int size = 300 * MB;
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        char *p = malloc(sizeof(char) * size);
        memset(p, 0, sizeof(char) * size);
    }
}