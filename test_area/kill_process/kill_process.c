#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int ch_id = fork();     // create child process
    if (ch_id < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (ch_id == 0)
    {
        for (int i = 0; i < 5; i++)
        {
            sleep(1);
        }
        printf("Child process ran without issue.\n");
        exit(0);
    }
    else
    {
        printf("Type x to terminate child process.\n");
        char res[1];
        gets(res);
        if (strcasecmp(res, "x") == 0)
        {
            kill(ch_id, SIGKILL);
            printf("Killed the child process.\n");
        }
        else
        {
            printf("Child will run without issue.\n");
            waitpid(ch_id, 0, 0);
        }
    }
    return 0;
}