#include<stdio.h>

//This code demonstrates the use of a pointer to an array of functions, doing so makes it easier to design logical use of functions.

int add();
int subtract();
int multiply();
int divide();
int modulo();

int (*operations[5])();
int (*(*operationptr)[5])();

int main(){
	printf("Choose your operation:\n-For Addition Press 1\n-For Subtraction Press 2\n-For Multiplication Press 3\n-For Division Press 4\n-For Modulo Press 5\n");
	int selection;
	scanf("%d\n",&selection);
	selection--;	

	printf("Enter 2 integers:\n");

	//Assigning functions to the array of functions
	operations[0] = add;
	operations[1] = subtract;
	operations[2] = multiply;
	operations[3] = divide;
	operations[4] = modulo;
	
	//Assigning the pointer to the array of functions
	operationptr = &operations;
	
	//Calling the selected function from the operationptr
	int result = (*(*operationptr+selection))();
	
	printf("The result of the operation is: %d\n",result);
	
	return 0;

}


int add(){
	int a;
	int b;
	scanf("%d %d",&a,&b);
	return a + b;
}

int subtract(){
        int a;
        int b;
        scanf("%d %d",&a,&b);
        return a - b;
}

int multiply(){
        int a;
        int b;
        scanf("%d %d",&a,&b);
        return a * b;
}

int divide(){
        int a;
        int b;
        scanf("%d %d",&a,&b);
        return a / b;
}

int modulo(){
        int a;
        int b;
        scanf("%d %d",&a,&b);
        return a % b;
}






