#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// a thread that simulates 3 seconds of work
void *mythread(void *arg) 
{
    int *address = (int*) arg;
    *address += 3;
    sleep(3);
    printf("Thread finished.\n");
    return 0;
}

int main(void)
{
    int global_num = 0;
    pthread_t t1, t2, t3, t4, t5;
    printf("Main starts here and creates 5 threads that simulate 3 seconds of work adding 3 to a given num.\n");
    printf("If we did this work without threads, it would take 15 seconds, and result would be 15.\n");
    pthread_create(&t1, NULL, mythread, &global_num);
    pthread_create(&t2, NULL, mythread, &global_num);
    pthread_create(&t3, NULL, mythread, &global_num);
    pthread_create(&t4, NULL, mythread, &global_num);
    pthread_create(&t5, NULL, mythread, &global_num);
    // join waits for the threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    pthread_join(t5, NULL);
    printf("Main ends here.\n");
    printf("Value of global_num: %i\n", global_num);
    return 0;
}