#include <stdio.h>

int func(int num);
int multiply(int a, int b);

int main(){
	printf("\n");
	printf("This class sucks, at least you can code in C, you sexy bastard!\n");
	int  x;
	printf("Please give me your number: ");
	printf("\n");
	scanf("%d",&x);
	int y = func(x);
	printf("\n");
	printf("Lmao your life sucks, here's a number: %d \n",y);
	return 0;
}

int func(int num){
	printf("\n");
	printf("Location of this variable in memory is: ");
	printf("%d\n",&num);
	int tempu = multiply(num,num);
	return tempu;
}

int multiply(int a, int b){
	if(b == 0){
		return 0;
	}
	return a + multiply(a,b-1);
}


