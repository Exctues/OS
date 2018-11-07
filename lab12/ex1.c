#include <stdio.h>

void main(){
    FILE *pfile = freopen("/dev/random","r",stdin);
    char str[256];
    fgets(str, 21, pfile);
    printf("%s", str);
}