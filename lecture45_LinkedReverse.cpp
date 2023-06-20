#include<bits/stdc++.h>
using namespace std;

//code for reversing of linked list
Node* reverseLL(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = NULL;

        prev = curr;
        curr = forward;
    }
    return prev;
}


//