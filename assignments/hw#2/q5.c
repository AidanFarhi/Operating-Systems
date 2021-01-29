#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int ch_pid = fork();
    if (ch_pid < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (ch_pid == 0)
    {
        printf("This should print first\n");
    }
    else
    {
        wait(NULL);
        printf("This should print last\n");
    }
}