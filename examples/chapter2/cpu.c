#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./cpu <string>\n");
    }
    char *str = argv[1];
    while (1)
    {
        sleep(2);
        printf("%s\n", str);
    }
    return 0;
}