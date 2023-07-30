#include<iostream>
#include<map>
using namespace std;


class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;

        //memory free
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << endl;
        cout << "Memory is freeing from data => " << value << endl;
    }
};

void insertAtHead(Node* &head, int d) {
    Node* newNode = new Node(d);

    newNode -> next = head;
    head = newNode;

}

void insertAtTail(Node* &tail, int d) {
    Node* newNode = new Node(d);

    tail -> next = newNode;
    tail = newNode;

}

void insertAtPosition(Node* &tail, Node* &head, int pos, int d) {

    //insertion at start
    if(pos == 1) {
        insertAtHead(head, d);
        return ;
    }

    int cnt = 1;
    Node* temp = head;

    while(cnt < (pos -1)) {
        temp = temp -> next;
        cnt++;
    }

    //inserting at last position
    if(temp ->  next == NULL) {
        insertAtTail(tail, d);
        return ;
    }

    //creating a node for position;
    Node* nodeToInsert = new Node(d);
    
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert; // you can't write this statement above previous line

}

void deleteAtPosition(int position, Node* &head, Node* &tail) {

    //deleting first or starting node
    if(position == 1) 
    {
        Node* temp = head;
        head = head -> next;
        //memory free start node
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head ;
        Node* prev = NULL;
        int count = 1;

        while(count < position)
        {
            prev = curr;
            curr = curr -> next;
            count++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
        //updating tail
        if(prev -> next == NULL)
        {
            tail = prev;
        }
    }
}

// TC = O(n)
// SC = O(n)
bool detectLoop(Node* head)
{
    if(head == NULL)
    {
        return false;
    }

    map<Node*, bool>visited;
    Node* temp = head;
    
    while(temp != NULL)
    {
        //cycle is present
        if(visited[temp] == true)
        {
            cout << "\nOn element => " << temp-> data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

// SC = O(1)
// TC = O(n)
Node* floydDetectLoop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast -> next ;
        if(fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

// to get the starting node of loop
Node* getStartingNode(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection)
    {
        intersection = intersection -> next;
        slow = slow -> next;
    }
    return slow;
}

// to remove the loop 
void removeLoop(Node* head)
{
    if(head == NULL)
    {
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node* newNode = new Node(10);

    Node* head = newNode;
    Node* tail = newNode;
    print(head);
    insertAtHead(head, 20); print(head);
    insertAtHead(head, 29); print(head);
    insertAtTail(tail, 40); print(head);
    insertAtTail(tail, 50); print(head);

    insertAtPosition(tail, head, 3, 55); print(head);
    insertAtPosition(tail, head, 5, 99); print(head);
    insertAtPosition(tail, head, 1, 199); print(head);

    tail -> next = head -> next;

    cout << "\nprinting using floydDetectLoop function" << endl;
    if(floydDetectLoop(head)) //or change floydDetectLoop with detectLoop 
    {
        cout << "Loop is present " << endl;
    }else{
        cout << "No Loop" << endl;
    }

    cout << "\nprinting using getStartingNode function" << endl;
    if(getStartingNode(head)) //or change floydDetectLoop with detectLoop 
    {
        cout << "Loop is present " << endl;
    }else{
        cout << "No Loop" << endl;
    }

    Node* loop = getStartingNode(head);
    cout << "\nLoop starts at => " << loop -> data << endl;

    removeLoop(head);
    print(head);

    cout << endl ;
    cout << "Head is pointing at => " << head->data << endl;
    cout << "Tail is pointing at => " << tail->data << endl;
    cout << endl;


    return 0;
}


//HW : Do all 5-ways of loop removing and all 3-ways of cycle detection