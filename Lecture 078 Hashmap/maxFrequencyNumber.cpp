// Q : Maximum Frequency Number
// https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319

//Time complexity => O(n)

#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0; i<arr.size(); i++){
        count[arr[i]]++; 
        maxFreq = max(maxFreq, count[arr[i]]);
    }
    
    for(int i=0; i<arr.size(); i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns; 
}


