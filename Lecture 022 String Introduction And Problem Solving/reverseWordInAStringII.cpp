// https://leetcode.com/problems/reverse-words-in-a-string-ii/



#include<bits/stdc++.h>
using namespace std;

int main() {
    string str = "the sky is blue";
    
    reverse(str.begin(), str.end());

    cout << str << endl;
    int k = 0;
    for(int i=0; i<str.length(); i++) {
        if(str[i] == ' ') {
            reverse(str.begin()+k, str.begin()+i);
            k = i+1;
        }
    }

    reverse(str.begin()+k, str.end());

    cout << str << endl;

    return 0;
}