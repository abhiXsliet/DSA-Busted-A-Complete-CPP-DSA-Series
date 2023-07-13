// https://leetcode.com/problems/permutation-in-string/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) return false;

        vector<int> window(26, 0);
        vector<int> s2_hash(26, 0);

        for(int i = 0; i < s1.length(); i++) {
            window[s1[i] - 'a']++;
            s2_hash[s2[i] - 'a']++;
        }

        if(window == s2_hash) return true;

        for(int i = s1.length(); i < s2.length(); i++) {
            s2_hash[s2[i - s1.length()] - 'a']--;
            s2_hash[s2[i] - 'a']++;

            if(window == s2_hash) return true;
        }

        return false;
    }
};