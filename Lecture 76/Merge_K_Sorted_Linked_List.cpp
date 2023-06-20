// Q : Merge K-sorted list
// link: https://www.codingninjas.com/codestudio/problem-details/merge-k-sorted-lists_992772


//approach 1
// vector<int> ans; -> sc=O(N*K)
// join all LL
// Replace LL nodes data with vector data
//TC = N*KLog(K) + (N*K) + (N*K)




//approach 2
// minheap -> fist element of k-LL
//ans LL -> head/tail -> head used to return and tail for insertion
//while(minHeap is not empty logic)
//SC => O(K)
//TC => O(KLogK) + O(N*KLogK) => O(N*KLogK) => O(NLogK)

#include<queue>

class compare{
    public:
        bool operator()(Node<int>* a, Node<int>* b){
            return a-> data > b -> data;
        }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;

    int k = listArray.size();
    if(k==0)
        return NULL;

    //step-1
    for(int i=0; i<k; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }


    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    //step-2
    while(!minHeap.empty()){

        Node<int>* top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL)
        {
            minHeap.push(top -> next);
        }

        if(head == NULL)
        {
            head = top;
            tail = top;
        }
        else
        {
            tail -> next = top;
            tail = top;
        }
    }
    return head;
}
