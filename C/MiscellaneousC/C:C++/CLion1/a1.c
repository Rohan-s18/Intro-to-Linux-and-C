//
// Created by Rohan Singh on 2/18/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

int *safeCount;
int *unsafeCount;
static pthread_mutex_t countlock = PTHREAD_MUTEX_INITIALIZER;

int incr1(){
    (*unsafeCount)++;
    return 1;
}

int incr2(){
    int error;
    if ((error = pthread_mutex_lock(&countlock)))
        return error;
    (*safeCount)++;
    return pthread_mutex_unlock(&countlock);
}

void *mythread_start1(){
    for(int i = 0; i < 1000000; i++)
        incr2();
    return NULL;
}

void *mythread_start2(){
    for(int i = 0; i < 1000000; i++)
        incr1();
    return NULL;
}

int main() {
    for (int i = 0; i < 100; i++) {
        pthread_t tid1, tid2, tid3, tid4;
        safeCount = malloc(sizeof(int));
        unsafeCount = malloc(sizeof(int));
        pthread_create(&tid1, NULL, mythread_start1, NULL);
        pthread_create(&tid2, NULL, mythread_start1, NULL);
        pthread_create(&tid3, NULL, mythread_start2, NULL);
        pthread_create(&tid4, NULL, mythread_start2, NULL);
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        pthread_join(tid3, NULL);
        pthread_join(tid4, NULL);
        fprintf(stderr, "The value of  safe count is : %d\n", *safeCount);
        fprintf(stderr, "The  value of unsafe count is %d\n", *unsafeCount);
    }
    return 1;
}

