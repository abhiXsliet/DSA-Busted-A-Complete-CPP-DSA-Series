// https://www.codingninjas.com/studio/problems/interview-shuriken-42-detect-and-remove-loop_241049



/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
        return NULL;
    
    Node* slow = head; 
    Node* fast = head;
    while(slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;
        
        //loop detected
        if(slow == fast )
        {
            return slow ; //or fast
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* intersection = floydDetectLoop(head);
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;
    while(slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }
    return slow; //or intersection
}

Node *removeLoop(Node *head)
{
    if(head == NULL)
        return NULL;
    
    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;
    
    while(temp -> next != startOfLoop)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
    return head;
}