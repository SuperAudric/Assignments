#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

void error(char* msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
int notBeers = 0;

void* drink_lots(void* a)
{
    int i;
    pthread_mutex_lock(&myMutex);
    for (i = 0; i < 1000000; i++) {
        notBeers++;
    }
    pthread_mutex_unlock(&myMutex);
    return NULL;
}


int main()
{
    pthread_t threads[20];
    int t;
    void* result;
    for (t = 0; t < 3; t++) {
        if (pthread_create(&threads[t], NULL, drink_lots, NULL) == -1)
            error("Cannot create thread");
    }
    for (t = 0; t < 20; t++) {
        if (pthread_join(threads[t], &result) == -1)
            error("Cannot Join Thread");
    }
    printf("There are now %i bottles of NotBeer on the wall\n", notBeers);
    return 0;
}