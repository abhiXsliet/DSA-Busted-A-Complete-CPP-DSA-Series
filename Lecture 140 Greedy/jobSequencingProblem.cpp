// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool cmp(Job a, Job b) {
        return a.profit > b.profit;
    }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, cmp);
        
        int maxiDeadline = INT_MIN;
        for(int i=0; i<n; i++) {
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }
        
        vector<int> schedule(maxiDeadline+1, -1);
        
        int cnt = 0;
        int maxProfit = 0;
        
        for(int i=0; i<n; i++) {
            int currProfit = arr[i].profit;
            int currJobId = arr[i].id;
            int currDeadline = arr[i].dead;
            
            for(int k = currDeadline; k>0; k--) {
                if(schedule[k] == -1) {
                    cnt++;
                    maxProfit += currProfit;
                    schedule[k] = currJobId;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(cnt);
        ans.push_back(maxProfit);
        
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends