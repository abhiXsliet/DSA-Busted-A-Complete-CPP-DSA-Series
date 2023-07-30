// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/0


//{ Driver Code Starts

//Initial template for C++
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//User function template for C++
class Solution 
{
    private:
    bool knows(vector<vector<int> >& M, int a, int b, int n)
    {
        if(M[a][b] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //step-1 : create a stack and push all the elements into it
        stack<int> s;
        for(int i=0; i<n; i++)
        {
            s.push(i);
        }
        
        //step-2 : take 2-elements from stack and check
        while(s.size() > 1)
        {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n))
            {
                s.push(b);
            }else{
                s.push(a);
            }
        }
        int potCeleb = s.top();  
        
        //step-3 : check row and col condition for the potential celebrity
        
        //row Check
        int zeroCount = 0;
        for(int i=0; i<n; i++)
        {
            if(M[potCeleb][i] == 0)
                zeroCount++;
        }
        
        if(zeroCount != n)
            return -1;
        
        //col check       
        int oneCount = 0;
        for(int i=0; i<n; i++)
        {
            if(M[i][potCeleb] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
            
        return potCeleb;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
// } Driver Code Ends
