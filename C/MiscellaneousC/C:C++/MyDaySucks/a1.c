#include <stdio.h>
#include <stdlib.h>

int *count;

int lmao(){
	(*count)++;
	return 1;
}

int main(){
	count = malloc(sizeof(int));
	for(int i = 0; i < 100000; i++){
		lmao();
	}
	fprintf(stderr,"Count is currently: %d",*count);
	printf("\n");
	return 0;
}


