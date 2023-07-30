#include<iostream>
using namespace std;

//best case TC ==> o(1); (key element found at the middle)
//worst case TC ==> o(logn) (since 2^k = N)
// binary search applies to monotonic functions
void binarySearch(int *a, int n, int key) {

    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = start + (end - start)/2;

        if(key < a[mid]) {
            end = mid - 1;
        }else if(key > a[mid]) {
            start = mid + 1;
        }else {
            cout << "\nElement found at index : " << mid << endl;
            return;
        }
    }
    cout << "\nElement not found " << endl;
}

void print(int *a, int n) {

    for (int i = 1; i <= n; i++) {
        cout << a << " ";
    }
}

int main() {

    int n, key;
    cout << "\nEnter the size of the array => ";
    cin>>n;
    int a[n];

    cout << "\nEnter the elements of the array (monotonic sequence)=> ";
    for(int i=0;i<n;i++)
        cin>>a[i];
        
    cout << "\nEnter the key element to search => ";
    cin >> key;

    binarySearch(a, n, key);
    cout << endl;

    return 0;
}