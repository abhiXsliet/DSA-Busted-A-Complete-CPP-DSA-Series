//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr+n);
        sort(dep, dep+n);
        
        int i = 0;
        int j = 0;
    	int cnt = 0;
    	int miniPlatform = 0;
    	
    	while(i<n) {
    	    if(arr[i] <= dep[j]) {
    	        cnt++;
    	        i++;
    	        miniPlatform = max(miniPlatform, cnt);
    	    }
    	    else if(arr[i] > dep[j]){
    	        cnt--;
    	        j++;
    	    }
    	}
    	return miniPlatform;

        // // BY Using For Loop
        // sort(arr, arr+n);
        // sort(dep, dep+n);
        // int j = 0;
    	// int miniPlatform = 0;
    	// for(int i=0; i<n; i++) {
    	//     if(arr[i] <= dep[j]) {
    	//        miniPlatform++;
    	//     }
    	//     else {
    	//         j++;
    	//     }
    	// }
    	// return miniPlatform;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends