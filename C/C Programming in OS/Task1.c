#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double process_command(double a, double b, char command);
int main(int argc, char* args[]){
	if(argc != 3) return 1;
	FILE* fp_read;
	fp_read = fopen(args[1],"r");
	FILE* fp_write;
	fp_write = fopen(args[2],"w");
	if(!fp_read) return 1;
	if(!fp_write) return 1;
	char buff[2048];
	char command;
	double a, b;
	while((fgets(buff,2048,fp_read)) != NULL){
		sscanf(buff, "%c %lf %lf", &command, &a, &b);
		double result = process_command(a,b,command);
		fprintf(fp_write,"%f\n",result);
	}
	return 0;
}
double process_command(double a, double b, char command){
	if(command == 'a') return a+b;
	else if(command == 's') return a-b;
	else if(command == 'm') return a*b;
	else if(command == 'd') return a/b;
	return 0.0;
}
