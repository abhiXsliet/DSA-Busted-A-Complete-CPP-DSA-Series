// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        string str = "";

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            if(stack.empty() || stack.top() != ch) {
                stack.push(ch);
            } else {
                stack.pop();
            }
        }
        while(!stack.empty()) {
            str.push_back(stack.top());
            stack.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};