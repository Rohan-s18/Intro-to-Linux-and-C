#include <stdio.h>

int fact(int c){
	if(c == 0){
		return 1;
	}
	return c*fact(c-1);
}

int main(){
	int num = 0; 
	printf("Please enter an integer: ");
	scanf("%d", &num);
	printf("\n");
	int x = fact(num);
	printf("The factorial is: %d",x);
	printf("\n");
	getchar();
	return 0;
}


