#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./run_print_hello ./<program name>\n");
        exit(1);
    }
    char prgmname[100];         // buffer for program name
    strcpy(prgmname, argv[1]);  // copy in program name from command line
    int ch_id = fork();         // create child process to run program
    if (ch_id < 0)             
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (ch_id == 0)        // child process code block
    {
        execlp(prgmname, prgmname, 0);
        printf("Could not run: %s\n", prgmname);
    }
    else
    {
        printf("Now we will execute ./print_hello\n");
        wait(NULL);
        printf("Program done running.\n");
        return 0;
    }
}