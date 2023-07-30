// https://leetcode.com/problems/valid-palindrome/



#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isValid(char ch){
        if( (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') )
            return 1;
        else 
            return 0;
    }

    char toLowerCase(char ch){
        if( (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') ) {
            return ch;
        }else{
            char temp = ch - 'A' + 'a' ;
            return temp;
        }
    }
    
public:
    bool isPalindrome(string s) {
        
        //Removing all characters other than Alpha-numeric
        int n = s.length();
        string temp =  "";
        for(int i=0; i<n; i++) {
            if(isValid(s[i])) {
                temp.push_back(s[i]);
            }
        }

        //Converting all characters into lowerCase
        int size = temp.length();
        for(int i=0; i<size; i++) {
            temp[i] = toLowerCase(temp[i]);
        }

        //checking palindrome
        for(int i=0; i<size; i++) {
            if(temp[i] != temp[size-i-1])
                return 0;
        }
        return 1;
    }
};