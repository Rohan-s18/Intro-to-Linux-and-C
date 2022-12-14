#include <stdio.h>

long fact(long x){
	if(x == 0){
		return 1;
	}
	return x*fact(x-1);
}

int main(){
	for(long num = 0; num <= 100; num++){
		long x = fact(num);
		printf("The factorial of %ld is:", num);
		printf("%ld",x);
		printf("\n");
	}
	getchar();
	return 0;
}
