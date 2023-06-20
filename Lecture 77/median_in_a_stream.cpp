// Q: Median In a stream
// link: https://www.codingninjas.com/codestudio/problems/median-in-a-stream_975268

//Approach-1 
//Use Insertion sort -> O(n^2)
// median -> odd = middle[arr(n/2)]             -> O(1)
// median -> even = [arr(n-1/2) + arr(n/2)]/2   -> O(1)
// Insertion for a new Element -> O(n)


//Approach-2
//TC = NLogN where N is the no. of element present in the input
//prefer copy/slide for approach understanding

#include<bits/stdc++.h>
using namespace std;


int signum(int a, int b){
	if(a==b)
		return 0;
	else if(a > b)
		return 1;
	else 
		return -1;
}

void callMedian(int element, priority_queue<int> &maxi, 
			priority_queue<int, vector<int>, greater<int>> &mini, int &median){

	switch(signum(maxi.size(), mini.size())){
		case 0 : if(element > median){
					mini.push(element);
					median = mini.top();
				}
				else
				{
					maxi.push(element);
					median = maxi.top();
				}
				break;

		case 1 : if(element > median){
					mini.push(element);
					median = (maxi.top() + mini.top())/2;
				}
				else 
				{
					mini.push(maxi.top());
					maxi.pop();
					maxi.push(element);
					median = (maxi.top() + mini.top())/2;
				}
				break;

		case -1 : if(element > median){
					maxi.push(mini.top());
					mini.pop();
					mini.push(element);
					median = (maxi.top() + mini.top())/2;
				}
				else 
				{
					maxi.push(element);
					median = (maxi.top() + mini.top())/2;
				}
				break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	vector<int> ans;
	int median = 0;

	for(int i=0; i<n; i++){
		int element = arr[i];
		callMedian(element, maxHeap, minHeap, median);

		ans.push_back(median);
	}
	return ans;
}
