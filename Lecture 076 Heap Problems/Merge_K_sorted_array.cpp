// Q : Merge K-sorted Arrays
// link: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379




#include <bits/stdc++.h> 

//Approach 1
// create a vector
// push all elements [N*K]
// sort vector
// TC => N*KLog(N*K)

//Approach 2
class node{
    public:
        int data;
        int i; 
        int j;

        node(int d, int row, int col){
            this -> data = d;
            i = row;
            j = col;
        }
};

class compare{
    public:
        bool operator()(node*a, node*b){
            return a -> data > b -> data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minHeap;

    //step-1 : Insert all first element of k-arrays into minHeap
    //TC => O(klogk)
    for(int i=0; i<k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    //step-2 : insert next element of same array into ans
    vector<int> ans;

    while(minHeap.size() > 0){
        node* temp = minHeap.top();

        ans.push_back(temp -> data);
        minHeap.pop();

        int i = temp -> i;
        int j = temp -> j;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next); 
        }
    }
    return ans;
}


//Time complexity of this approach => O(N*KLog(K))
//Space complexity of this approach=> O(N*K)