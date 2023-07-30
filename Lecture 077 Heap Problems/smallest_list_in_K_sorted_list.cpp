// Q : Smallest List In K-sorted list
// link: https://www.codingninjas.com/codestudio/problems/smallest-range-from-k-sorted-list_1069356

//approach 1 -> calculate all possible ranges
    // Total no. of elements = n*k
    // TC => O(N^2*K^2) in finding all possible ranges
    // difference of each range
    // smallest && atleast 1-element in each list => store

//approach 2 -> without using any heap
    // create a array DS
    // Insert the first element from each list
    // initialise min/max
    // cond => smallest range && at least 1-element 
    // find difference -> smallest -> store
    // increase min. element value from the list

    // TC => O(n*K^2)
    // SC => O(K)
    // prefer copy/slide for better understanding

//approach 3 -> Using a minHeap to optimize the min/max tc from o(k) to o(logk)
        //since heap can find min/max in O(1) but insertion of elements take O(logk)
//Time complexity => O(n*klog(k))
//space complexity => O(k)



#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        int row;
        int col;

        node(int d, int r, int c){
            data = d;
            row = r;
            col = c;
        }
};

class compare{
    public:
        bool operator()(node*a, node* b){
            return a->data > b-> data;
        }
};

int kSorted(vector<vector<int>> &a, int k, int n) {

    int mini = INT_MAX;
    int maxi = INT_MIN;
    
    priority_queue<node*, vector<node*>, compare>pq;

    //step - 1: creating a minheap for the starting element of each list and tracking the max/min values
    for(int i=0; i<k; i++){
        int element = a[i][0];

        maxi = max(maxi, element);
        mini = min(mini, element);

        pq.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;


    while(!pq.empty()){
        
        //fetch mini
        node* temp = pq.top();
        pq.pop();

        //update mini
        mini = temp -> data;

        //update range and max
            //range updation
        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }

            //max updation
        if(temp->col+1 < n){//next element exists
            maxi = max(maxi, a[temp->row][temp->col+1]);
            pq.push(new node(a[temp->row][temp->col+1], temp->row, temp->col+1));
        }
        else{//next element doesn't exists
            break;
        }
    }
    //returning the range of difference values
    return (end - start + 1);
}