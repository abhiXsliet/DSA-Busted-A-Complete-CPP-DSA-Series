//https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    static bool cmp(pair<int, pair<int, int>>a, pair<int, pair<int,int>>b) {
        return b.second.second > a.second.second;
    }
    
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector<pair<int, pair<int, int>> > v;
        for(int i=0; i<N; i++) {
            v.push_back({i, {S[i], F[i]}});
        }
        
        sort(v.begin(), v.end(), cmp);
        
        int ansEnd = v[0].second.second;
        vector<int>result;
        result.push_back(v[0].first + 1);
        
        for(int i=1; i<N; i++) {
            if(v[i].second.first > ansEnd) {
                ansEnd = v[i].second.second;
                result.push_back(v[i].first + 1);
            }
        }
        sort(result.begin(), result.end());
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends10
