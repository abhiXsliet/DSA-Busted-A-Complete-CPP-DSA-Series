// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string s)
    {
        int arr[26] = {0};
        for(int i=0; i<s.length(); i++) {
            char ch = s[i];
            //lowercase
            int number = 0;
            number = ch - 'a';
            arr[number]++;
        }
    
        //find maximum occuring char
        int maxi = -1, ans = 0;
        for(int i=0; i<26; i++) {
            if(maxi < arr[i]) {
                ans = i;
                maxi = arr[i];
            }
        }
        return 'a' + ans;
        }

};

//{ Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
// } Driver Code Ends