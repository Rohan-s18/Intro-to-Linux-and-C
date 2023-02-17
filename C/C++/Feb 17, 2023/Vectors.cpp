// Author: Rohan Singh
// Code for Lin Alg library in C++

using namespace std;

#include <iostream>

class Vector{
    private:
    
    int* arr;
    int dim;

    public:
    
    Vector(int n){
        arr = new int[n];
        dim = n;
    }

    int* get_vector(){
        return arr;
    }

    void set_vector(int* arr);

    int dot_product(Vector vec){
        if(vec.get_dimensions() != dim)
            return -1;
        int prod = 0;
        for(int i = 0; i < dim; i++)
            prod += ((vec.get_vector()[i])*(arr[i]));
        return prod;
        
    }

    int get_dimensions();

    ~Vector(){
        delete[] arr;
    }


};


void Vector::set_vector(int* array){
    Vector::arr = array;
}

int Vector::get_dimensions(){
    return Vector::dim;
}


int main(){
    return 0;
}
