//https://www.codingninjas.com/codestudio/problems/find-duplicate-in-array_1112602



#include <bits/stdc++.h>    
using namespace std;

int findDuplicate(vector<int> &arr, int n){
    // // TC -> O(Nlog(N))
    // sort(arr.begin(), arr.end());
    // for(int i=0; i<n; i++){
    //     if(arr[i] == arr[i+1])
    //         return arr[i];
    // }


    // // TC -> O(N)
    // for(int i = 0;i<n;i++){
    //     int ch = abs(arr[i]);
    //     if(arr[ch]>0){
    //         arr[ch] = arr[ch]*-1;
    //     }
    //     else{
    //         return abs(arr[i]); 
    //     }
    // }
    // return -1;


    // TC -> O(N)
    for(int i=0; i<n; i++) {
        int index = arr[i] % n;
        arr[index] += n;
    }
    for(int i=0; i<n; i++) {
        if(arr[i]/n > 1)
            return i;
    }
    return -1; 
}
