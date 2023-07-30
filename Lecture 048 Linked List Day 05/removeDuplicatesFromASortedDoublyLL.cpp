// https://www.codingninjas.com/studio/problems/unique-sorted-list_2420283



/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    //empty list
    if(head == NULL || head -> next == NULL)
        return head;
    
    //non-empty list
    Node* curr = head;
    while((curr != NULL) && (curr -> next != NULL))
    {
        if(curr -> data == curr -> next -> data)
        {
            Node* next_next = curr -> next -> next;
            Node* nodeToDelete = curr-> next;
            curr -> next = next_next;
            delete(nodeToDelete);
        }else{
            curr = curr -> next;
        }
    }
    return head;
}