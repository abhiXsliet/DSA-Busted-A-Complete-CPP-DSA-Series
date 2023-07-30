// https://www.codingninjas.com/studio/problems/circularly-linked_1070232



#include <bits/stdc++.h> 
using namespace std;
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    if(head == NULL)
    {
        return true;
    }

    Node* slow = head;
    Node* fast = head -> next;
    while(slow != fast)
    {
        if(fast == NULL|| fast -> next == NULL) 
            return false;
        fast = fast -> next -> next ;
        slow = slow -> next;
    }
    if(slow -> next == head)
        return true;
    else 
        return false;
}
