#include <iostream>


using namespace std;

void printArray(int *arr, int size){

    for(int j = 0; j < size; j++){
        cout << arr[j] << " ";
    }
    cout << endl;
}

int main(){

    int pSize = 5;
    int qSize = 10;
    int *p = new int[pSize];
    int *q = new int[qSize];

    for (int i = 0; i < 5; i++){
        p[i] = i*2;
    }

    cout << "address of p: " << p << endl;
    cout << "address op q: " << q << endl;

    cout << "array p: ";
    printArray(p, pSize);

    // Increasing array p size

    for (int i = 0; i < pSize; i++){
        q[i] = p[i];
    }

    // before making p point to q we need to free up memory to avoid
    // memory leakage
    delete []p;
    p = q; 

    // to check that both pointers point to the same address
    cout << "address of p: " << p << endl;
    cout << "address op q: " << q << endl;

    // q is not needed anymore hence we make it point to NULL;
    q = NULL;

    cout << "array p: ";
    printArray(p, qSize);

    return 0;
}