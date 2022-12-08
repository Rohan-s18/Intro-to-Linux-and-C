#include <stdio.h>
#include <stdlib.h>


extern int a, b;
int c;
extern float f;

int main(){
	
	int a, b;
	int c;
	float f;
	
	a = 10;
	b = 20;

	c = a + b;

	fprintf(stderr,"The sum of %d & %d is: %d\n",a,b,c);
	fprintf(stderr,"The Address of a is: %d\n",&a);
	fprintf(stderr,"The Address of b is: %d\n",&b);
	fprintf(stderr,"The Address of c is: %d\n",&c);	
	
	f = 70.0/3.0;

	fprintf(stderr,"70.0 divided by 3.0 is: %f\n",f);
	fprintf(stderr,"The Address of f is: %d\n",&f);

	return 0;
}
