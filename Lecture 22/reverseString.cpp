// https://leetcode.com/problems/reverse-string/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i=0; i<n/2; i++){
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }

        // int start=0;
        // int end = s.size()-1;
        // while(start<end) {
        //     swap(s[start++], s[end--]);
        // }
    }
};