// https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331



#include <bits/stdc++.h> 
using namespace std;
/****************************************************************
    Following is the class structure of the Node class:
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

Node *removeDuplicates(Node *head)
{
    unordered_map<int, bool> mpp;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        if(mpp[temp -> data] == 1) {
            prev -> next = temp -> next;
            temp -> next = NULL;
            delete temp;
            temp = prev -> next;
            
        } else {
            mpp[temp -> data] = 1;
            prev = temp;
            temp = temp -> next;
        }
    }
    return head;
}


//HW :- split the circular linked into the two half problem 