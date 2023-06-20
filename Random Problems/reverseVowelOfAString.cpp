#include<bits/stdc++.h>
using namespace std;


bool isVowel(char c)
{
    //No-case sensitive
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
         ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ;
}


string reverseVowels(string s) {
    int start = 0;
    int end = s.size() - 1;

    //for traversing
    while(start <= end)
    {
        //finding leftmost vowel 
        while(start <= end && !isVowel(s[start])) start++;

        //finding rightmost vowel
        while(end >= 0 && !isVowel(s[end])) end--;

        if(start <= end)
        {
            swap(s[start++], s[end--]);
        }
    }
    return s;
}

int main()
{
    string n;
    cout << endl;
    cout << "Enter the Word = > ";
    cin>>n;

    cout << reverseVowels(n) << endl;

    cout << endl << endl;
    return 0;
}
