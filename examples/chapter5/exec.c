#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("The first line of the parent process (pid:%d)\n", (int) getpid());
    int ch_proc_pid = fork();
    if (ch_proc_pid < 0) // fork process failed
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (ch_proc_pid == 0) // this is the child process branch
    {
        printf("Child process (pid: %d) is now goin to run execvp()...\n", (int) getpid());
        sleep(2);
        // We are now goin to execute another program "wc" which will count 
        // the lines, words, and bytes in a file
        char *myargs[3];
        myargs[0] = strdup("wc");      // Name of program: "wc"
        myargs[1] = strdup("fork.c");  // Name of file that "wc" will act on
        myargs[2] = NULL;              // Marks end of array
        printf("Result of \"wc\":\n");
        execvp(myargs[0], myargs);     // This runs the program via execvp()
        printf("This will should not print.\n");
    }
    else  // parent process goes down this branch
    {
        int wait_proc_pid = wait(NULL);
        printf("This is the end of the program. My pid: %d My child's pid: %d Wait process pid: %d\n",
                (int) getpid(), ch_proc_pid, wait_proc_pid);
    }
    return 0;
}