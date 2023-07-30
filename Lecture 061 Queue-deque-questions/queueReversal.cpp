// https://practice.geeksforgeeks.org/problems/queue-reversal/1



//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        stack<int>s;
        while(!q.empty()){
            int element = q.front();
            q.pop();
            s.push(element);
        }
        
        while(!s.empty()){
            int element = s.top();
            s.pop();
            q.push(element);
        }
        return q;
    }
    
/* 
    //Recursive Approach
    void solve(queue<int>& q)
    {
        //base case
        if(q.empty()) return;
        
        int num = q.front();
        q.pop();
        
        //recursive call
        solve(q);
        
        q.push(num);
        
    }
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
    }
 */

};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends