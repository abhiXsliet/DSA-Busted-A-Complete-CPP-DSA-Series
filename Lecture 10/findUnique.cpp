//https://www.codingninjas.com/codestudio/problems/find-unique_625159



#include<bits/stdc++.h>
using namespace std;

int findUnique(int *arr, int size)
{
    // int ans = 0;
    // for(int i=0; i<size; i++){
    //     ans = ans^arr[i];
    // }
    // return ans;

    //approach-second
    //time complexity increases here to NLogN
    sort(arr, arr+size);
    for(int i=0; i<size; i++){
        if(arr[i] != arr[i+1]){
            return arr[i];
        }
        i++;
    }
}