//https://www.codingninjas.com/codestudio/problems/triplets-with-given-sum_893028



#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {

/* 
    // TLE 
    // TC -> O(N^2 * log(N))
    // SC -> O(no. of triplets) = O(N3)
    set<vector<int>> store;
    for(int i=0; i<n; i++) {
        set<int> st;
        for(int j=i+1; j<n; j++) {
            int ele = K - (arr[i] + arr[j]);

            if(st.find(ele) != st.end()) {
                vector<int> temp = {arr[i], arr[j], ele};
                sort(temp.begin(), temp.end());
                store.insert(temp);
            }

            st.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(store.begin(), store.end());
    if(ans.empty()) {
        return {};
    }
    return ans;

 */


    // Time Complexity => O(N^2)
    // Space Complexity => O(1) -> for algorithms
    // O(no. of triplets) => O(N3) -> for returning the answer
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) {
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int j = i + 1;
        int end = n - 1;

        while(j < end) {
            int sum = arr[i] + arr[j] + arr[end];

            if(sum < K) {
                j++;
            } else if(sum > K) {
                end--;
            } else {
                vector<int> temp = {arr[i], arr[j], arr[end]};
                ans.push_back(temp);
                j++;
                end--;
                while(j < end && arr[j] == arr[j - 1]) j++;
                while(j < end && arr[end] == arr[end + 1]) end++;
            }
        }
    }

    if(ans.empty()) {
        return {};
    }

    return ans;
}