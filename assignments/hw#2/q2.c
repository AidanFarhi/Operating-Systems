#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    FILE *file = fopen("hello.txt", "w");
    int ch_proc_pid = fork();
    if (ch_proc_pid < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (ch_proc_pid == 0) // child process code block
    {
        fprintf(file, "Hello from child.\n");
    }
    else  // parent process code block
    {
        fprintf(file, "Hello from parent.\n");
    }
}