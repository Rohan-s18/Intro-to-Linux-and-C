#include <stdio.h>

int fact(int x){
	if(x == 0){
		return 1;
	}
	return x*fact(x-1);
}

int main(){
	for(int num = 0; num <= 100; num++){
		int x = fact(num);
		printf("The factorial of %d is:", num);
		printf("%d",x);
		printf("\n");
	}
	getchar();
	return 0;
}



