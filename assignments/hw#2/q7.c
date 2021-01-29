#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
        close(STDOUT_FILENO);
        printf("Hello from child\n");
    }
    else
    {
        printf("Hello from parent\n");
    }
}