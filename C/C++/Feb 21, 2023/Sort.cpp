//  Author: Rohan Singh
//  Date: Feb 21, 2023
//  C++ Code for Sorting algorithms in Sorted Order

#include <iostream>


//  Class with all of the sorting methods
class Sort{

    // All helper methods are private
    private:

    void swap(int arr[], int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void quick_sort_recur(int arr[], int start, int end){
        if(start>=end)
            return;
        int pivot = (start+end)/2;
        pivot = partition(arr,start,pivot,end);
        quick_sort_recur(arr,start,pivot);
        quick_sort_recur(arr,pivot+1,end);
    }

    int partition(int arr[], int start, int pivot, int end){
        int i = start-1;
        int j = end+1;
        int elm = arr[pivot];
        while(true){
            do{
                i++;
            }
            while(arr[i] < elm);
            do{
                j--;
            }
            while(arr[j] > elm);
            if(i >= j)
                return j;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    void mergeSortHelper(int arr[], int temp[], int start, int end) {
		if(start >= end)
			return;
		int middle = (start+end)/2;
		mergeSortHelper(arr,temp,start,middle);
		mergeSortHelper(arr,temp,middle+1,end);
		merge(arr,temp,start,middle,middle+1,end);
	}

    void merge(int arr[], int temp[], int leftStart, int leftEnd, int rightStart, int rightEnd) {
		int i = leftStart;
		int k = leftStart;
		int j = rightStart;

		while(i <= leftEnd && j <= rightEnd) {
			if(arr[i] <= arr[j]) {
				temp[k] = arr[i];
				i++;
			} else {
				temp[k] = arr[j];
				j++;
			}
			k++;
		}

		while(i <= leftEnd) {
			temp[k] = arr[i];
			i++;
			k++;
		}
		while(j <= rightEnd) {
			temp[k] = arr[j];
			j++;
			k++;
		}

		for(int index = leftStart; index <= rightEnd; index++) {
			arr[index] = temp[index];
		}

	}





    // Sorting methods (Sorting in ascending order)
    public:

    void insertion_sort(int arr[], int n){
        int j, toInsert;
        for(int i = 2; i < n; i++){
            toInsert = arr[i];
            for(j = i; j > 0 && arr[j-1] > toInsert; j--){
                arr[j] = arr[j-1];
            }
            arr[j] = toInsert;
        }
    }

    void selection_sort(int arr[], int n){
        int smallest, smallest_index;
        for(int i = 0; i < n; i++){
            smallest = arr[i];
            smallest_index = i;
            for(int j = i; j < n; j++){
                if(arr[j] < smallest){
                    smallest = arr[j];
                    smallest_index = j;
                }
            }
            swap(arr,smallest_index,i);
        }
    }

    void bubble_sort(int arr[], int n){
        for(int i = n-1; i > 0; i--){
            for(int j = 0; j < i; j++){
                if(arr[j] > arr[j+1])
                    swap(arr,j,j+1);
            }
        }
    }

    void merge_sort(int arr[], int n){
        int temp[n];
		mergeSortHelper(arr,temp,0,n-1);
    }

    void quick_sort(int arr[], int n){
        quick_sort_recur(arr,0,n);
    }

    void shell_sort(int arr[], int n){
        int incr = 1;
		while(2*incr <= n) {
			incr = incr*2;
		}
		incr = incr-1;
		while(incr >= 1) {
			for(int i = incr; i < n; i++) {
				int toInsert = arr[i];
				int j = 0; 
				for(j = i; j > incr - 1 && toInsert < arr[j-incr]; j = j -incr) {
					arr[j] = arr[j-incr];
				}
				arr[j] = toInsert;
			}
			incr = incr/2;
		}
    }

    void print_array(int arr[], int n){
        std::cout<<"[";
        for(int i = 0; i < n; i++){
            std::cout<<arr[i];
            std::cout<<" ";
        }
        std::cout<<"]\n";
    }

    void create_arr(int my_arr[]){
        int arr[] = {3,4,-5,10,3,12,-6,8,10,13};
        for(int i = 0; i < 10; i++)my_arr[i]=arr[i];
    }



};

int main(){

    int my_arr[10];
    Sort* mySort = new Sort();


    std::cout<<"Insertion Sort:\n";
    mySort->create_arr(my_arr);
    mySort->print_array(my_arr,10);
    mySort->insertion_sort(my_arr,10);
    mySort->print_array(my_arr,10);

    
    std::cout<<"\nSelection Sort:\n";
    mySort->create_arr(my_arr);
    mySort->print_array(my_arr,10);
    mySort->selection_sort(my_arr,10);
    mySort->print_array(my_arr,10);


    std::cout<<"\nBubble Sort:\n";
    mySort->create_arr(my_arr);
    mySort->print_array(my_arr,10);
    mySort->bubble_sort(my_arr,10);
    mySort->print_array(my_arr,10);


    std::cout<<"\nQuick Sort:\n";
    mySort->create_arr(my_arr);
    mySort->print_array(my_arr,10);
    mySort->quick_sort(my_arr,10);
    mySort->print_array(my_arr,10);


    std::cout<<"\nMerge Sort:\n";
    mySort->create_arr(my_arr);
    mySort->print_array(my_arr,10);
    mySort->merge_sort(my_arr,10);
    mySort->print_array(my_arr,10);


    std::cout<<"\nShell Sort:\n";
    mySort->create_arr(my_arr);
    mySort->print_array(my_arr,10);
    mySort->shell_sort(my_arr,10);
    mySort->print_array(my_arr,10);

    return 0;
}





