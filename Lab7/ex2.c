#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        *(a + i) = i;
        // a[i] = i;
        printf("%d\n", &a[i]);
    }
    printf("---------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", *(a + i));
    }
    printf("\n");

    free(a);
}