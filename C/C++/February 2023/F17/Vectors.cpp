// Author: Rohan Singh
// Code for Vectors in C++

//using namespace std;

#include <iostream>

class Vector{
    private:
    
    int* arr;
    int dim;

    public:
    
    Vector(int n){
        this->arr = (int*)malloc(n*sizeof(int));
        this->dim = n;
    }

    Vector(int n, int array[]){
        this->set_vector(array);
        this->dim = n;
    }

    int* get_vector(){
        return this->arr;
    }

    void set_vector(int* arr);

    int dot_product(Vector vec){
        if(vec.get_dimensions() != this->dim)
            return -1;
        int prod = 0;
        for(int i = 0; i < this->dim; i++)
            prod += ((vec.get_vector()[i])*(this->arr[i]));
        return prod;
        
    }

    int get_dimensions();

    ~Vector(){
        delete[] arr;
    }

    void print_vector();

    void subtract_vector(Vector v2){
        if(v2.get_dimensions() != this->dim)
            return;
        for(int i = 0; i < this->dim; i++)
            this->arr[i]-=v2.get_vector()[i];
    }


};


void Vector::set_vector(int* array){
    Vector::arr = array;
}

int Vector::get_dimensions(){
    return Vector::dim;
}

void Vector::print_vector(){
    std::cout<<"[";
    for(int i = 0; i < Vector::dim; i++){
        std::cout << Vector::arr[i];
        std::cout << " ";
    }
        
    std::cout<<"]";
}


int main(){

    int nums[10] = {1,2,3,4,5,6,7,8,9,10};

    Vector* v1 = new Vector(10);
    Vector* v2 = new Vector(10, nums);

    v1->set_vector(nums);

    int prod = v1->dot_product(*v2);

    std::cout<<"The Dot Product of these vectors: \n";
    v1->print_vector();
    v2->print_vector();
    std::cout<<prod;
    std::cout<<"\n";


    return 0;
}
