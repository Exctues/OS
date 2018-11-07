#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    printf("Parent's pid = %d\n", getpid());
    int pid = fork();
    if (pid == 0)
    {
        printf("Child's pid = %d\n", getpid());
        while (1)
        {
            sleep(1);
            printf("I'm alive.\n");
            fflush(stdout);
        }
    }
    else
    {
        sleep(10);
        kill(pid, SIGKILL);
        printf("Child should be dead...\n");
    }

    return 0;
}