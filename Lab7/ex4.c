#include <stdlib.h>
#include <string.h>

void *realloc(void *ptr, int size)
{
    void *nptr = malloc(size);
    if (nptr == NULL || size == 0)
    {
        free(ptr);
        return nptr;
    }
    memcpy(nptr, ptr, size);

    free(ptr);
    return nptr;
}

void main()
{
}