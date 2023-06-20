//https://www.codingninjas.com/codestudio/problems/painter-s-partition-problem_1089557?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid) {

    int n = boards.size();
    int painterCount = 1;
    int timeSum = 0;

    for(int i=0; i<n; i++) {
        
        if(timeSum + boards[i] <= mid) {
            timeSum += boards[i];
        }
        else {
            painterCount++;
            if( (painterCount>k) || (boards[i] > mid) ) 
                return false;
            
            timeSum = boards[i];
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    int n = boards.size();
    for(int i=0; i<n; i++) {
        sum += boards[i];
    }
    int e = sum;

    int ans = -1;
    while( s<=e ) {
        int mid = s + ( e-s )/2;

        if(isPossible(boards, k, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else 
        {
            s = mid + 1;
        }
    }
    return ans;
}