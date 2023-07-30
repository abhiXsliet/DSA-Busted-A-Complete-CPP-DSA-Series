// https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397



#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr) 
{

    // //TC => O(N*Log(N))
    // sort(arr.begin(), arr.end());
    // for(int i=0; i<arr.size(); i++){
    //     if(arr[i] == arr[i+1])  
    //         return arr[i];
    // }


    
    // // TC -> O(N)
    // int total = accumulate(arr.begin(), arr.end(), 0);
    // int n = arr.size();
    // int sum = n*(n-1)/2;
    // return total-sum;



    //TC => O(N)
    int ans = 0;
    //XORing all elements of the array;
    for(int i=0; i<arr.size(); i++){
        ans = ans^arr[i];
    }  
    //XORing all elements from 1 to n-1;
    for(int i=1; i<arr.size(); i++){
        ans = ans^i;  
    }
    return ans;
}
