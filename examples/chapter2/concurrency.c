#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

/* Global variables */
volatile int counter = 0;
int loops;

/* Worker function we will pass to a thread */
void *worker(void *param)
{
    sleep(3); // Simulate wait time
    for (int i = 0; i < loops; i++)
    {
        counter++;
    }    
    return NULL;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: ./concurrency <value>\n");
        exit(1);
    }
    time_t start, end;
    time(&start);
    printf("Initial value: %i\n", counter);
    loops = atoi(argv[1]);

    // Declare our thread variables here
    pthread_t thread_1, thread_2, thread_3;

    // Now we will create our threads
    pthread_create(&thread_1, NULL, worker, NULL);
    pthread_create(&thread_2, NULL, worker, NULL);
    pthread_create(&thread_3, NULL, worker, NULL);
    // Now join the threads
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    time(&end);
    printf("Final value: %i\n", counter);
    printf("Total time taken: %f\n", (double)(end - start));
}