//https://www.codingninjas.com/codestudio/problems/find-duplicate_625160



#include<bits/stdc++.h>
using namespace std;

int duplicateNumber(int *arr, int size)
{
    // // Time Complexity => O(N*log(N))
    // // Space Complexity => O(1)
    // sort(arr, arr+size);
    // for(int i=0; i<size; i++)
    //     if(arr[i] == arr[i+1])
    //         return arr[i];


    // // Time Complexity => O(N)
    // int i, total, sum = 0;
    // sum = ((size-2)*(size-1))/2;
    // for(int i=0; i<size; i++) {
    //     total += arr[i];
    // }
    // return total - sum;


    // Time Complexity => O(N)
    // Space Complexity => O(1)
    for (int i = 0; i < size; i++) {
        int index = arr[i] % size;
        arr[index] += size;
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] / size > 1) {
            return i;
        }
    }
    return -1;  // No duplicate found
}   

