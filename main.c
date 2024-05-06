#include "progressbar.c"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

const int MS = 1000;

int main()
{
    pthread_mutex_init(&mutex, NULL); // init the mutex.

    pthread_t progressThread;
    int i;
    int max_value = 100;
    int length = 50;

    struct ProgressBarArgs* args = (struct ProgressBarArgs*)malloc(sizeof(struct ProgressBarArgs));

    args->progress = i;
    args->total = max_value;
    args->length = length;
    args->time = 0;

    pthread_create(&progressThread, NULL, multiThreadedProgressbar, (void*)args); // Replace `progressbar(i, max_value, length, 0);`
    for (i = 0; i <= max_value; i++) {
        args->progress = i;
        args->total = max_value;
        args->length = length;
        args->time = 0;

        usleep(5 * MS);
    }
    pthread_join(progressThread, NULL);
    pthread_mutex_destroy(&mutex);
    printf("\n");
    free(args);

    return 0;
}
