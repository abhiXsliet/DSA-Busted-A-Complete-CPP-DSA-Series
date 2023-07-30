// https://www.codingninjas.com/studio/problems/reverse-a-doubly-linked-list_1116098



/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

*/

Node* reverseDLL(Node* head)
{   
    if(head == NULL || head -> next == NULL)
        return head;

    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;
    while(curr != NULL) {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }    
    
    return prev;
}

