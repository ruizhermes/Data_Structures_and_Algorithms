#include <iostream>

using namespace std;


void selectionSort(int Arr[], int size);
void swap(int *, int *);
void printArray(int *arr, int size);

int main(){

    int Arr[] = {1,10, 9, 3, 5, 2, 1, 2, 3};
    int size = 9;

    printArray(Arr, size);
    selectionSort(Arr, size);
    printArray(Arr, size);
    
    return 0;
}


void selectionSort(int Arr[], int size){

    int i,j,k;

    for(i=0; i < size-1; i++){
        for(j=k=i; j<size; j++){
            if(Arr[j] < Arr[k]){
                k = j;
            }
        }
        swap(&Arr[i], &Arr[k]);
    }
}


void swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

void printArray(int *arr, int size){

    for(int j = 0; j < size; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}