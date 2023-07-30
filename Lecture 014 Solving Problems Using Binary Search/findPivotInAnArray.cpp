#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[], int n) {
    int s = 0;
    int e = n - 1;

    while(s < e) {
        int mid = s + ( e - s )/2;

        if(arr[mid] >= arr[0])
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int main() {
    int n;
    cout << "\nEnter the size of the array => ";
    cin >> n;
    int arr[n];

    cout << "\nEnter the elements of the array (as monotonic & rotated) \nsimilar as {3 8 10 17 1} => ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "\nPivot index is : " << getPivot(arr, n) << endl;

    cout << endl;
    return 0;
}