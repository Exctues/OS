#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void handle(int sig){
    if(sig == SIGUSR1){
        printf("This is SIGUSR1 \n");
    }
    else if(sig == SIGSTOP){
        printf("This is SIGSTOP \n");
    }
    else if(sig == SIGKILL){
        printf("It will never be printed because it is not possible to catch SIGKILL.");
    }
}


int main() {
    printf("%d\n", getpid());
    signal(SIGUSR1, handle);
    signal(SIGSTOP, handle);
    signal(SIGKILL, handle);
    int i = 1;
    while(1){
        sleep(1);
        printf("%d\n", i);
		fflush(stdin);
        i++;
    }
    return 0;
}
