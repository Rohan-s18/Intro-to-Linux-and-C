#include<stdio.h>

//This code demonstrates the use of a pointer to a function in the C Programming language

int addition();

int main(){
	int sum;
	
	//Pointer to the addition function
	int (*ptr)();
	ptr = &addition;

	//Calling the function through the pointer
	sum = (*ptr)();
	printf("The sum is: %d\n", sum);

	return 0;	

}

int addition(){
	int a;
	int b;
	printf("Please enter 2 integers, no funny business please ;)\n");
	scanf("%d %d",&a,&b);
	return a + b;

}





