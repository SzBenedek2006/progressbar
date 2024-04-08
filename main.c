#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "progressbar.c"

int main() {

    pthread_t progressThread;
    int i;
    int max_value = 100;
    int length = 50;


    struct ProgressBarArgs *args = (struct ProgressBarArgs *)malloc(sizeof(struct ProgressBarArgs));





    args->progress = i;
    args->total = max_value;
    args->length = length;
    args->time = 0;

    pthread_create(&progressThread, NULL, multiThreadedProgressbar, (void *)args); // Replace `progressbar(i, max_value, length, 0);`
    for (i = 0; i <= max_value; i++) {
        args->progress = i;
        args->total = max_value;
        args->length = length;
        args->time = 0;


        usleep(100000);
    }
    pthread_join(progressThread, NULL);
    printf("\n");
    free(args);
    return 0;
}

/*

--------------------------------------------------------------------------------------------

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> // Needed for malloc and free



// Function prototype for progressbar
void progressbar(int i, int max_value, int length, int option);





// Function executed by the thread
void* thread_function(void* arg) {
    // Cast the void pointer argument back to the correct type
    struct ProgressBarArgs *args = (struct ProgressBarArgs *)arg;

    // Call the progressbar function with the arguments passed
    progressbar(args->i, args->max_value, args->length, args->option);

    // Clean up
    free(arg);

    return NULL;
}








int main() {
    pthread_t thread;

    // Create arguments for the progressbar function
    struct ProgressBarArgs *args = (struct ProgressBarArgs *)malloc(sizeof(struct ProgressBarArgs));


    // Create thread and pass arguments
    pthread_create(&thread, NULL, thread_function, (void *)args);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    return 0;
}

// Define the progressbar function
void progressbar(int i, int max_value, int length, int option) {
    // Implementation of progressbar function
    // This is just a placeholder, replace it with your actual progressbar implementation
    printf("Progress: [%-*.*s] %d%%\n", length, (i * length) / max_value, "===========", (i * 100) / max_value);
}


*/
