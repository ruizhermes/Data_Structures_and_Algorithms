#include <iostream>


using namespace std;

int partitioning(int Arr[], int low, int high);
void swap(int *, int *);
void printArray(int *arr, int size);


void quickSort(int Arr[], int low, int high);

int main(){

    int Arr[] = {43,45, 22, 12, 1, 4, 34, 52, 9, 4, INT32_MAX};
    int size = 11;

    printArray(Arr, size-1);
    quickSort(Arr, 0, size-1);
    printArray(Arr, size-1);


    return 0;
}

void quickSort(int Arr[], int low, int high){

    int pivot_place;

    if (low < high){
        pivot_place = partitioning(Arr, low, high);
        quickSort(Arr, low, pivot_place);
        quickSort(Arr, pivot_place+1, high);
    }
}

int partitioning(int Arr[], int low, int high){

    int pivot = Arr[low];
    int i = low;
    int j = high;

    do
    {
        do{i++;}while(Arr[i] <= pivot);
        do{j--;}while(Arr[j] > pivot);

        if(i < j){
            swap(&Arr[i], &Arr[j]);
        }
    } while (i<j);

    swap(&Arr[low], &Arr[j]);
    return j;
    
}

void printArray(int *arr, int size){

    for(int j = 0; j < size; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}
