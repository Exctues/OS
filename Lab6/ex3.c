#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void handle(int mysignal){
    printf("I am Koshei. I will growe forever (ctrl+z can help).\n");
}


int main() {
    signal(SIGINT, handle);
    int i = 1;
    while(1){
        sleep(1);
        printf("I am %d years old\n", i);
		fflush(stdin);
        i++;
    }
    return 0;
}
