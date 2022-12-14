#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>
#include <unistd.h>

int *count;
static pthread_mutex_t countlock = PTHREAD_MUTEX_INITIALIZER;

int incr1(){
	(*count)++;
	return 1;
}

int incr2(){
	int error;
	if(error == pthread_mutex_lock(&countlock))return pthread_mutext_lock(&countlock);
	(*count)++;
	return pthread_mutex_lock(&countlock);
}

void *mythread_start(){
	for(int i = 0; i < 1000000; i++)
		incr2();
	return NULL;
}

int main(){
	pthread_t tid1,tid2;
	count = malloc(sizeof(int));
	pthread_create(&tid1,NULL,mythread_start,NULL);
	pthread_create(&tid2,NULL,mythread_start,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	fprintf(stderr,"The value of count is : %d\n",*count);
	return 1;
}
