// https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250



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
Node* getMiddle(Node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
    }
    return slow;
}
Node *findMiddle(Node *head) {
    return getMiddle(head);
}