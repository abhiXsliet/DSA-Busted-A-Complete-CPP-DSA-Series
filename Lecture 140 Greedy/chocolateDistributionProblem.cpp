//https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        sort(a.begin(), a.end());

        int i = 0;
        int j = m - 1;
        int mini = INT_MAX;
        
        while(j < n) {
            int diff = a[j] - a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        return mini;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends