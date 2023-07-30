// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
 


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		  string str = "";
		  unordered_map<char, int> mpp;
		  queue<char>q;
		  for(int i = 0; i < A.size(); i++) {
		      q.push(A[i]);
		      mpp[A[i] - 'a']++;
		      
		      while(!q.empty()) {
		          if(mpp[q.front() - 'a'] > 1) {
		              q.pop();
		          } else {
		              str.push_back(q.front());
		              break;
		          }
		      }
		      if(q.empty()) str.push_back('#');
		  }
		    return str;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends