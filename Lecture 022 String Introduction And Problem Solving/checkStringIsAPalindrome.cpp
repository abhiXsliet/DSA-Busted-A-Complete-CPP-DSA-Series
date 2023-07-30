// https://www.codingninjas.com/studio/problems/check-if-the-string-is-a-palindrome_1062633



#include <bits/stdc++.h> 
using namespace std;

bool valid(char ch){
    if((ch >= 'a' && ch <= 'z')||
        (ch >= 'A' && ch <= 'Z')||
        (ch >= '0' && ch <= '9')){
        return 1;
    }
    return 0;
}

char toLowercase(char ch){
    if((ch >= 'a' && ch <= 'z')||(ch >= '0' && ch <= '9')){
        return ch;
    }else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(string a){
    int st=0; int end = a.size()-1;
    
    while(st<end){
        if(a[st] != a[end]){
            return 0;
        }
        else{
            st++; end--;
        }
    }
    return 1;
}
    
bool checkPalindrome(string s)
{
    //faltu ke char hatado
    string temp = "";
    for(int i=0; i<s.size(); i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    //sbko lowercase kardo
    for(int i=0; i<temp.size(); i++){
        temp[i] = toLowercase(temp[i]);
    }

    //check palindrome
    return isPalindrome(temp);
}

