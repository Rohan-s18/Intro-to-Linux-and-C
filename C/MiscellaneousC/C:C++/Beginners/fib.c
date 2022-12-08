
#include <stdio.h>

int getNum(){
	int temp = 0;
	printf("Please enter a number: ");
	scanf("%d", &temp);
	return temp;
}

int fib(int i){
	if(i <= 2){
	return 1;
	}
	return fib(i-1)+fib(i-2);
}

int main(){
	int num = 0;
	num = getNum();
	int x = fib(num);
	printf("\n");
	printf("The fibonacci number is: %d",x);
	getchar();
	return 0;
}

