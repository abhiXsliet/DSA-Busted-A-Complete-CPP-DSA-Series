// https://www.codingninjas.com/studio/problems/reverse-the-singly-linked-list_799897


#include <bits/stdc++.h> 
using namespace std;
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    } 
    else
    {
        LinkedListNode<int>* prev = NULL;
        LinkedListNode<int>* curr = head;
        LinkedListNode<int>* forward = NULL;
        while(curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
}