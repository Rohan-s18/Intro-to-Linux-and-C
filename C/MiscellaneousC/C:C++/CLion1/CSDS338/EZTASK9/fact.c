//
// Created by Rohan Singh on 4/8/22.
//

#include <stdlib.h>
#include <stdio.h>

double fib(double x);

int main(){
    double a = 50;
    double z = fib(a);
    fprintf(stderr,"The value of the %fth number in the fibonacci sequence is %f\n",a,z);


}

double fib (double x){
    if(x==1)return 1;
    if(x==2)return 1;
    return fib(x-1) + fib(x-2);
}
