#include <stdio.h>
#include <unistd.h>

void progressbar(int progress, int total, int length) {
    int j;
    float progressPercent = (float) progress / total * 100;
    printf("Progress: [");
    for (j = 0; j < length; j++) { // a középső szám állítja a vonal hosszúgágát
        if (j < progressPercent * length / 100) {
            printf("■");
        } else {
            printf(" ");
        }
    }
    printf("] %.0f%%\033[A\n", progressPercent);
    fflush(stdout);
    // Sleep for 100 milliseconds
}

int main() {
    int i;
    int max_value = 100;
    int length = 50;
    for (i = 0; i <= max_value; i++) {
        progressbar(i, max_value, length);
        usleep(100000);
    }
    printf("\n");

    return 0;
}

