//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

    
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 

        string temp = "";
        string ans = "";
        
        for(int i=S.length()-1; i>=0; i--) {
            if(S[i] == '.') {
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans.push_back('.');
                temp = "";
            }
            else{
                temp.push_back(S[i]);
            }
        }
        
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends