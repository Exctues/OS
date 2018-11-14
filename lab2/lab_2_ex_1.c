#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(){
    int i;
    float f;
    double d;
    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("%d, size of int = %d\n",i, sizeof(int));
    printf("%f, size of float = %d\n",f, sizeof(float));
    printf("%f, size of double = %d\n",d, sizeof(double));

    return 0;
}