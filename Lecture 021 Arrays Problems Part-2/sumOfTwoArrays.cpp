// https://www.codingninjas.com/studio/problems/sum-of-two-arrays_893186



#include<bits/stdc++.h>
using namespace std;

vector<int> reverseAns(vector<int>&a) {
	int s = 0;
	int e = a.size()-1;
	while(s <= e) {
		swap(a[s], a[e]);
		s++;
		e--;
	}
	return a;
}
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	
    vector<int> ans;
	int carry = 0, sum = 0;
	int i = n - 1;
	int j = m - 1;

    // TC = O(max(n, m))
    // SC = O(max(n, m))

	//case-1 : when both array have same length
	while(i >= 0 && j >= 0) {
		sum = a[i] + b[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--; i--;
	}

	//case-2 : when array b[] length is remaining
	while(j >= 0) {
		sum = b[j] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		j--;
	}

	//case-3 : when array a[] is length remaining
	while(i >= 0) {
		sum = a[i] + carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		i--;
	}

	//case-4 : when carry is remaining
	while(carry != 0) {
		sum =  carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
	}
	return reverseAns(ans);


    /*	
    vector<int> ans;
	int carry = 0, sum = 0;
	int i = n - 1;
	int j = m - 1;
 
    //Optimized
    // TC = O(max(n, m))
    // SC = O(max(n, m))
	while(i >= 0 || j >= 0 || carry != 0) {
		if(i >= 0) {
			sum += a[i];
			i--;
		}
		if(j >= 0) {
			sum += b[j];
			j--;
		}
		sum += carry;
		carry = sum / 10;
		sum = sum % 10;
		ans.push_back(sum);
		sum = 0;
	}
	return reverseAns(ans);
 */
}