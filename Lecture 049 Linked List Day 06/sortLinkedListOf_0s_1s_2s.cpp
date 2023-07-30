// https://www.codingninjas.com/studio/problems/sort-linked-list-of-0s-1s-2s_1071937



/********************************
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

********************************/
Node* insertAtTail(Node* &tail, Node* curr)
{
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    //creating separate lists for 0's, 1's and 2's
    while(curr != NULL)
    {
        int val = curr -> data;
        
        if(val == 0)
        {
            insertAtTail(zeroTail, curr); 
        }
        else if(val == 1)
        {
            insertAtTail(oneTail, curr);
        }
        else if(val == 2)
        {
            insertAtTail(twoTail, curr);
        }
        curr = curr -> next;
    }
    
    //merging the lists together
    
    //if 1's list is not empty
    if(oneHead -> next != NULL)
    {
        zeroTail -> next = oneHead -> next;
    }else{
        //if 1's list is empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
    //head setup
    head = zeroHead -> next;
    
    //deleting dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
    
}
