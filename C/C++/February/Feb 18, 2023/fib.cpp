//  Author: Rohan Singh
//  Febrauary 18, 2023
//  C++ code to explain how dynamic programming works


#include <iostream>

//  Fibonccai class
class Fibonacci{

    public:

    int recur(int n){
        if(n==1 || n==2)
            return 1;
        return recur(n-1)  +recur(n-2);
    }

    int iter(int n){
        int f[n];
        f[0] = 1;
        f[1] = 1;
        for(int i = 2; i < n; i++){
            f[i] = f[i-1] + f[i-2];
        }
        return f[n-1];
    }

};

int main(){

    Fibonacci* fib = new Fibonacci();

    std::cout<<fib->iter(45);
    std::cout<<"\n";

    std::cout<<fib->recur(45);
    std::cout<<"\n";


    return 0;
}