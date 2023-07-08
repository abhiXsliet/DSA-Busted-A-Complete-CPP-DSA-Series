//https://www.codingninjas.com/codestudio/problems/sort0_1_2-0-1-2_631055



#include <bits/stdc++.h>
using namespace std;

void sort012(int *arr, int n)
{
    int cntZero = 0, cntOne = 0, cntTwo = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] == 0)
            cntZero++;
        else if(arr[i] == 1)
            cntOne++;
        else
            cntTwo++;
    }
    for(int i=0; i<cntZero; i++) 
        arr[i] = 0;
    for(int i=cntZero; i<cntZero+cntOne; i++) 
        arr[i] = 1;
    for(int i=cntZero+cntOne; i<n; i++)
        arr[i] = 2;



    // int left = 0;
    // int mid = 0; 
    // int right = n - 1;
    // while(mid <= right) {
    //     if(arr[mid] == 0) {
    //         swap(arr[mid], arr[left]);
    //         mid++;
    //         left++;
    //     } else if( arr[mid] == 1 ) mid++;
    //     else {
    //         swap(arr[mid], arr[right]);
    //         right--;
    //     }
    // }
}