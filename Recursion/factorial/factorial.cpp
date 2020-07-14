#include <iostream>

using namespace std;

int factorial(int n){

    if (n > 1)
    {
        return factorial(n-1) * n;
    }
    else{
        return 1;
    }
    

}
int main(){

    int value = 5;
    int f = factorial(value);

    cout << "factorial of " << value << ": " << f << endl;
}