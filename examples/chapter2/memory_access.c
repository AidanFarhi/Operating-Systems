#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int)); // Allocate memory the size of an int
    if (p == NULL) // Make sure memory was properly allocated
    {
        return 1;
    }
    printf("(%d) address pointed to by p: %p\n", getpid(), p);
    *p = 0;
    while (1)
    {
        sleep(1); // Wait for one second
        *p = *p + 1; // Increment value at address of p
        printf("(%d) p: %i\n", getpid(), *p);
    }
    return 0;
}

