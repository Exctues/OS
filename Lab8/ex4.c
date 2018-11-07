#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>



void main()
{
    const unsigned int MB = 1024 * 1024;
    const unsigned int size = 100 * MB;

    struct rusage *prusage = malloc(sizeof(struct rusage));
    for (int i = 0; i < 10; i++)
    {
        char *p = malloc(sizeof(char) * size);
        memset(p, 0, sizeof(char) * size);
        getrusage(RUSAGE_SELF, prusage);
        printf("Memory usage: %d\n", prusage->ru_maxrss);
        fflush(stdin);

        sleep(1);
    }
}