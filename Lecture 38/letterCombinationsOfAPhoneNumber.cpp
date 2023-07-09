// https://leetcode.com/problems/letter-combinations-of-a-phone-number/



#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(string digits, string output, int index, string mapping[], vector<string>& ans){
        
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        //finding index number and their corresponding mapping
        int number = digits[index] - '0';
        string value = mapping[number];

        //ek step solving
        for(int i = 0; i<value.length(); i++){
            output.push_back(value[i]);

            //recursive call
            solve(digits, output, index+1, mapping, ans);

            output.pop_back();

        }


    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        
        if(digits.length() == 0){
            return ans;
        }
        int index = 0;

        string mapping[10] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, output, index, mapping, ans);

        return ans;
    }
};

