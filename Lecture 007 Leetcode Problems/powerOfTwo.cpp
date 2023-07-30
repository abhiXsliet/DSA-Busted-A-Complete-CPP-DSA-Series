// https://leetcode.com/problems/power-of-two/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        //Brute force approach
        
        // for(int i = 0; i<=30; i++){
        //     int ans = pow(2,i);
        //     if(ans == n){
        //         return true;
        //     }
        // }
        // return false;
        
        
        int ans = 1;
        for (int i = 0; i<=30; i++){
            if(ans == n){
                return true;
            }
            
            if(ans < INT_MAX/2)
            ans = ans *2;
        }
        return false;
    }
   
};

