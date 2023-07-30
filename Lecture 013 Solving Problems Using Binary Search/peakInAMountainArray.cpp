// https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int n = arr.size()-1;
        int s = 0;
        int e = n-1;
        int ans = -1;

        while(s<e) {
            int mid = s + (e - s)/2;

            if(arr[mid] < arr[mid+1]){
                s = mid + 1;
            }
            else {
                e = mid;
            }
        }
        return s;
    }
};