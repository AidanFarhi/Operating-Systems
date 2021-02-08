#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./memory-user <memory size in mbs> <time to run in seconds>\n");
        return 1;
    }
    int size = atoi(argv[1]);
    int time = atoi(argv[2]);
    int *array = malloc(size * 1000);
    for (int i = 0; i < time; i++) {
        sleep(1);
    }
    free(array);
}