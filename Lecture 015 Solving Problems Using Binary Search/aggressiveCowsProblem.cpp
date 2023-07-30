// https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &stalls, int k, int mid) {

    int n = stalls.size();
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=0; i<n; i++) {

        if( stalls[i]-lastPos >= mid ) {
            cowCount++;
            lastPos = stalls[i];
            if(cowCount == k) {
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    sort(stalls.begin(), stalls.end());

    int s = 0;
    int sum = -1;
    int n = stalls.size();
    for(int i=0; i<n; i++) {
        maxi = max(maxi, stalls[i]);
        mini = min(mini, stalls[i]);
    }
    int e = maxi - mini;

    int ans = -1;
    while(s<=e) {
        int mid = s + (e-s)/2;

        if(isPossible(stalls, k, mid)) {
            s = mid + 1;
            ans = mid;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}