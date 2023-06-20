//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool cmp(pair<int,int>a, pair<int, int>b) {
        return b.second > a.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            pair<int,int>p = make_pair(start[i], end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int cnt = 1;
        int ansEnd = v[0].second;
        for(int i=1; i<n; i++) {
            if(v[i].first > ansEnd){
                cnt++;
                ansEnd = v[i].second;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends