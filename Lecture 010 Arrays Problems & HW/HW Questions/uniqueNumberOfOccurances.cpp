//https://leetcode.com/problems/unique-number-of-occurrences/description/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity => O(m + n) where n = size of arr vector and m = no. of unique elements in arr
    // Space Complexity => O(m)
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for(int i=0; i<arr.size(); i++) {
            freq[arr[i]]++;
        }

        unordered_set<int> counts;
        for(auto &pair: freq) {
            if(counts.find(pair.second) != counts.end()) {
                return false;
            }
            counts.insert(pair.second);
        }
        return true;
    }
};
