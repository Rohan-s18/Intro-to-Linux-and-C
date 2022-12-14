#include <stdio.h>

int main(){
	char string[] = "Hello World!";
	int arr[100];
	for(int i = 0; i < 100; i++){
		arr[i] = i;
	}
	printf("%s \n", string);
	for(int j = 0; j < 100; j++){
		printf("%d ",arr[j]);
	}
	printf("\n");
	return 1;
}









