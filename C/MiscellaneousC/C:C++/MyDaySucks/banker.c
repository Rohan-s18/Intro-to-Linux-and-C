//
// Created by Rohan Singh on 2/18/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

int *safeBankAccount;
int *unsafeBankAccount;
static pthread_mutex_t countlock = PTHREAD_MUTEX_INITIALIZER;

int deposit1(){
    (*unsafeBankAccount) += 500;
    return 0;
}

int deposit2(){
    int error;
    if((error = pthread_mutex_lock(&countlock)))
        return error;
    (*safeBankAccount) += 500;
    return pthread_mutex_unlock(&countlock);
}

int withdraw1(){
    (*unsafeBankAccount) -= 500;
    return 0;
}

int withdraw2(){
    int error;
    if((error = pthread_mutex_lock(&countlock)))
        return error;
    (*safeBankAccount) -= 500;
    return pthread_mutex_unlock(&countlock);
}

void *startThread1(){
    for(int i = 0; i < 10000000; i++){
        deposit1();
        withdraw1();
    }
    return NULL;
}

void *startThread2(){
    for(int i = 0; i < 10000000; i++){
        deposit2();
        withdraw2();
    }
    return NULL;
}

int main(){
    pthread_t tid1,tid2,tid3,tid4;
    safeBankAccount = malloc(sizeof(int));
    unsafeBankAccount = malloc(sizeof(int));
    pthread_create(&tid1,NULL,startThread1,NULL);
    pthread_create(&tid2,NULL,startThread2,NULL);
    pthread_create(&tid3,NULL,startThread1,NULL);
    pthread_create(&tid4,NULL,startThread2,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
    fprintf(stderr,"The balance in the safe account: %d\n",*safeBankAccount);
    fprintf(stderr,"The balance in the unsafe account: %d\n",*unsafeBankAccount);
    return 0;
}


