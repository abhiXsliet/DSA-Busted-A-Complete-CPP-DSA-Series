// Q: K-th Largest Sum Subarray
// link : https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar




#include<bits/stdc++.h>


//approach 1
//tc => O(n^2 logn)
//sc => O(n^2)
int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;
	
	for(int i=0; i<arr.size(); i++){
		int sum = 0;
		for(int j=i; j<arr.size(); j++){
			sum += arr[j];
			sumStore.push_back(sum);
		}
	}

	//sort stored values of vector
	sort(sumStore.begin(), sumStore.end());

	return sumStore[sumStore.size() - k];
}




//approach 2;
//sc reduced to o(k)
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int> >minHeap;

	int n = arr.size();

	for(int i=0; i<n; i++){
		int sum = 0;
		for(int j=i; j<n; j++){
			sum += arr[j];

			if(minHeap.size() < k){
				minHeap.push(sum);
			}
			else
			{
				if(sum > minHeap.top()){
					minHeap.pop();
					minHeap.push(sum);
				}
			}
		}
	}

	return minHeap.top();
}