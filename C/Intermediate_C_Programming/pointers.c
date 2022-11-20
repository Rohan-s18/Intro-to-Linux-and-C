#include<stdio.h>


// Author: Rohan Singh
// Novemeber 19, 2002
// This code demonstrates how pointers work in C just as a refresher in case you forgot. Herre we will look at how they are assigned. Here we will just declare a few pointers and swap the values of 2 variables using pointers and no extra variable.

int main(){
	
	//This is how pointer is declared 
	int n = 1000;
	int* p = &n;
	
	printf("The address of the variable is: %p\n", p); 	//Here 'p' is the pointer
	printf("The value of the variable is: %d\n", *p);	//Here using '*p* (indirection operator) gives us the value
	
	//Now we will swap the values of 2 variables without using an extra variable 
	int a=10;
	int b=20;
	int* p1=&a;
	int* p2=&b;

	printf("Before swap: a=%d and b=%d\n",a,b);  
	
	*p1=*p1+*p2;
	*p2=*p1-*p2;
	*p1=*p1-*p2;
	
	printf("After swap: a=%d and b=%d\n",a,b);
	
	return 0;	

}
