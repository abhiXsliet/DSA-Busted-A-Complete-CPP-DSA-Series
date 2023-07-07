#include<iostream>
using namespace std;



//Default argument :-> value dena hai to deh de nhi to equal wala value use kr lunga
// If a value is provided in the func() signature, it will be used; otherwise, the default value will be utilized.
// Always works from the right most argument/parameter to left the most

void print(int arr[], int n = 0, int start = 1) {

    for(int i = start; i<n; i++){
        cout << arr[i] << endl;
    }
}

int main(){

    int arr[5] = {1, 4, 7, 8, 9};
    int size = 5;

    print(arr, size);
    cout << endl ;
    print(arr, size, 2);

    return 0;
}
