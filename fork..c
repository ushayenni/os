#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid = fork();

    if (pid < 0)
    {
        printf("\n fork() failed...");
        return 1;
    }
    else if (pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
        exit(1);
    }
    else
    {
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}
