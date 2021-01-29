#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Global Variable */
int *x;

int main(void)
{
    x = malloc(sizeof(int));
    *x = 100;
    int ch_pr_pid = fork();
    if (ch_pr_pid < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (ch_pr_pid == 0)
    {
        printf("The value of x in the child process: %i\n", *x);
        printf("Adress of x in child: %p\n", x);
        *x = 200;
    }
    else
    {
        wait(NULL);
        printf("Adress of x in parent: %p\n", x);
        printf("At the end of the parent process, the value of x: %i\n", *x);
    }
    free(x);
}