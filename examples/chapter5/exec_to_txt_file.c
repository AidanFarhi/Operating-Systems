#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

/* 
To run program:
% make exec_to_txt_file
% ./exec_to_txt_file
% cat exec_to_txt_file.output
*/
int main(int argc, char *argv[])
{
    int ch_proc_id = fork();
    if (ch_proc_id < 0)
    {
        fprintf(stderr, "Child process failed.\n");
        exit(1);
    }
    else if (ch_proc_id == 0)  // this code block is the child process branch
    {
        // Redirect results to an output file
        close(STDOUT_FILENO);
        open("./exec_to_txt_file.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        // Now execute "wc" program
        char *myargs[3];
        myargs[0] = strdup("wc");                  // program "wc"
        myargs[1] = strdup("exec_to_txt_file.c");  // arg: file to count
        myargs[2] = NULL;                          // mark end of array
        execvp(myargs[0], myargs);                 // executes "wc" program
    }
    else
    {
        wait(NULL);  // wait for child to finish
    }
    return 0;
}