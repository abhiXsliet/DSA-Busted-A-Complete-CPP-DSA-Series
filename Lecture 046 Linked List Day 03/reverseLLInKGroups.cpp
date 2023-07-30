// https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644



#include <bits/stdc++.h> 
using namespace std;
/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
Node* kReverse(Node* head, int k) {
    //base case
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    //step-1 : Reversing the first k nodes 
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int cnt = 0;
    while(curr != NULL && cnt < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    
    //step 2: Recursive call
    if(next != NULL)
    {
        head -> next = kReverse(next, k);
    }
    return prev;

};