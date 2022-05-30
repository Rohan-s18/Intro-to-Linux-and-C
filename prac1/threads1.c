//
// Created by Rohan Singh on 3/12/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void startThread1(){
    for(int i = 0; i < 1000; i++)fprintf(stderr,"A\n");
}

void startThread2(){
    for(int i = 0; i < 1000; i++)fprintf(stderr,"B\n");
}

int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,startThread1,NULL);
    pthread_create(&t2,NULL,startThread2,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}

