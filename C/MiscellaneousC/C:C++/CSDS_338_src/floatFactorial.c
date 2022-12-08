#include <stdio.h>

float fact(float x){
	if(x == 0){
		return 1;
	}
	return x*fact(x-1);
}

int main(){
	for(float num = 0; num <= 100; num++){
		float x = fact(num);
		printf("The factorial of %f is:", num);
		printf("%f",x);
		printf("\n");
	}
	getchar();
	return 0;
}
