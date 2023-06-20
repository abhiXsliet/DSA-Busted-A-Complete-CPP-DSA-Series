//https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_1112602

#include <bits/stdc++.h>    
using namespace std;

int findDuplicate(vector<int> &arr, int n){
    
    // sort(arr.begin(), arr.end());
    // for(int i=0; i<n; i++){
    //     if(arr[i] == arr[i+1])
    //         return arr[i];
    // }

    for(int i = 0;i<n;i++){
    int ch = abs(arr[i]);
    if(arr[ch]>0){
        arr[ch] = arr[ch]*-1;
    }
    else{
        return abs(arr[i]); 
    }
    }
    return -1;

}
