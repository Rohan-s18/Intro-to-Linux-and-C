//
// Created by Rohan Singh on 2/24/22.
//
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static pthread_mutex_t accountLock = PTHREAD_MUTEX_INITIALIZER;

struct account{
    char name[35];
    int balance;
}unsafeAccount,safeAccount;

int unsafeWithdraw(){
    unsafeAccount.balance -= 100;
    return 0;
}

int safeWithdraw(){
    int error;
    if((error = pthread_mutex_lock(&accountLock)))
        return 0;
    safeAccount.balance -= 100;
    return pthread_mutex_unlock(&accountLock);
}

int unsafeDeposit(){
    unsafeAccount.balance += 100;
    return 0;
}

int safeDeposit(){
    int error;
    if((error= pthread_mutex_lock(&accountLock)))
        return error;
    safeAccount.balance += 100;
    return pthread_mutex_unlock(&accountLock);
}

void *startUnsafeThread(){
    for(int i = 0; i < 10000000; i++){
        unsafeDeposit();
        unsafeWithdraw();
    }
    return NULL;
}

void *startSafeThread(){
    for(int i = 0; i < 10000; i++){
        safeWithdraw();
        safeDeposit();
    }
    return NULL;
}

int main(){
    pthread_t tid1,tid2,tid3,tid4;
    char temp[35];
    fprintf(stdout,"Please enter your name: ");
    scanf("%s",&temp);
    strcpy(safeAccount.name,temp);
    fprintf(stdout,"\n");
    fprintf(stdout,"Please enter your name: ");
    scanf("%s",&temp);
    strcpy(unsafeAccount.name,temp);
    fprintf(stdout,"\n");

    pthread_create(&tid1,NULL,startUnsafeThread,NULL);
    pthread_create(&tid2,NULL,startUnsafeThread,NULL);
    pthread_create(&tid3,NULL,startSafeThread,NULL);
    pthread_create(&tid4,NULL,startSafeThread,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);

    fprintf(stdout,"\n\nCOMPUTING\n\n\n");
    fprintf(stdout,"Details for the Unsafe Bank Account:\n");
    fprintf(stdout,"Name of Account Holder: %s\n",unsafeAccount.name);
    fprintf(stdout,"Account Balance for Unsafe Bank Account: %d\n",unsafeAccount.balance);
    fprintf(stdout,"\n");
    fprintf(stdout,"Details for the Safe Bank Account:\n");
    fprintf(stdout,"Name of Account Holder: %s\n",safeAccount.name);
    fprintf(stdout,"Account Balance for Safe Bank Account: %d\n",safeAccount.balance);
    fprintf(stdout,"\n");
    return 0;
}




