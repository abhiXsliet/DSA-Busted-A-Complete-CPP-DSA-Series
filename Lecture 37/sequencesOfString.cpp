// https://www.codingninjas.com/studio/problems/subsequences-of-string_985087


// Set of all subsets is called POWER SET.
// POWER SET = 2^n where n = no. of elements in a set

#include <bits/stdc++.h> 
using namespace std;

void solve(string str, string output, int index, vector<string>& ans){
    //base case
    if(index >= str.length()){
        if(output.length() > 0){
            ans.push_back(output);
        }
        return;
    }
    
    //exclude
    solve(str, output, index+1, ans);
    
    //include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str){
	vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}


//Do these problems with the help of bits manipulation
