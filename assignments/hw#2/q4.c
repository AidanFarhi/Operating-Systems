#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
        char *args[] = {"/bin/ls", NULL};
        execvp(args[0], args);
    }
    else
    {
        printf("End of program\n");
    }
}