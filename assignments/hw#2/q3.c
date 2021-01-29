#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char read_buffer[80]; //
    int fd[2];
    pipe(fd);
    int ch_pid = fork();
    if (ch_pid < 0)
    {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (ch_pid == 0) // child process code block
    {
        close(fd[0]); // close input side of pipe
        char ch_string[6] = "Hello";  // send "Hello" through the output side of pipe
        write(fd[1], ch_string, 7);
        exit(0);
    }
    else
    {
        close(fd[1]); // close ouput side of pipe
        read(fd[0], read_buffer, sizeof(read_buffer)); // read message from input side of pipe
        printf("Child message: %s\n", read_buffer);
        printf("Parent message: Bye\n");
    }
}