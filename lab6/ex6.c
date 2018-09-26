#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

#define MAIN (pid1 != 0 && pid2 != 0)
#define PID1 (pid1 == 0)
#define PID2 (pid2 == 0)
int pipe_arr[2];
int state = -1;
void main()
{
    pipe(pipe_arr);

    int pid1 = fork();
    int pid2;
    if (pid1 != 0)
        pid2 = fork();

    if (MAIN){
        write(pipe_arr[1], &pid2, sizeof(int)); // main send child2's pid to child1.
        waitpid(pid1,&state,0);
        printf("Everything is done.\n");
    }
    if(PID2){
        while(1){
            sleep(1);
            printf("Child2 is still alive\n");
        }
    }

    if (PID1)
    {
        sleep(1);
        read(pipe_arr[0], &pid2, sizeof(int));
        sleep(3);
        kill(pid2,SIGSTOP);
        printf("Child2 stopped by Child1\n");
        sleep(2);
        kill(pid2,SIGCONT);
        printf("Child2 resumed by Child1\n");
        sleep(3);
        kill(pid2,SIGKILL);
        printf("Child1 killed child2\n");
        exit(0);
    }    
}