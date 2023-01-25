#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int x=7;
	float y=14.3;
	void* ptr;
	ptr=&x;
	printf("The value pointed by the pointer is: %d\n",*(int*)ptr);
	printf("The value pointed by the pointer is: %f\n",*(float*)ptr);
	ptr=&y;
	printf("The value pointed by the pointer is: %d\n",*(int*)ptr);
	printf("The value pointed by the pointer is: %f\n",*(float*)ptr);
	return 0;
}
