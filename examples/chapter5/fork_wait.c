#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("First line of program (pid: %d)\n", (int) getpid());
    int child_process = fork();
    if (child_process < 0)  // Fork process failed
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (child_process == 0)  // Child process branch
    {
        sleep(2);
        printf("This is the code for the child process (pid: %d)\n", (int) getpid());
    }
    else  // The parent executes down this branch
    {
        // wait() will wait until the child process terminates, 
        // then it returns the pid of the process it waited on, or -1 if failed
        printf("The parent process will now wait on the child process to finish.\n");
        int pid_of_child = wait(NULL); 
        printf("This is the code from of the parent of %d (pid_of_child: %d) (pid: %d)\n",
                child_process, pid_of_child, getpid());
    }
    return 0;
}