// https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1



//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends

// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    //step 1 -> pop first k elements from q and put it into stack
    stack<int>s;
    for(int i=0; i<k; i++)
    {
        int el = q.front();
        q.pop();
        
        s.push(el);
    }
    
    //step 2 -> fetch from stack and push in queue
    while(!s.empty())
    {
        int el = s.top();
        s.pop();
        q.push(el);        
    }
    
    //step 3 -> fetch n-k elements from the queue and push back
    int size = q.size() - k;
    while(size--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}