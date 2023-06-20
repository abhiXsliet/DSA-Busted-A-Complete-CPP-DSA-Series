#include <bits/stdc++.h>
using namespace std;

// What is a Linked List?
//  It is a type of linear data structure which is made by using collection of Nodes.
//  A nodes holds the data field and the address of the next node (or a pointer to the next node)

// why LL is needed?
//  LL is a dynamic DS which can grow and shrink at the run time therefore there is no wastage of memory.

// Types of Linked List :-
//(1). Singly LL
//(2). Doubly LL
//(3). Circular LL
//(4). Circular Doubly LL
/*
//node declaration
class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

};

int main() {

    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    return 0;
}

 */

// singly LL :- If you have a pointer to go to the next node and can store the data field in the node then this type of LL is known as singly LL.

// Insertion :-

/*
class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead (Node* &head, int d) {

    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}

void insertAtTail (Node* &tail, int d) {

    //new node created
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp ; 

}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {

    //insert at start
    if(position == 1){
        insertAtHead(head, d);
        return ;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp -> next;
        cnt++;
    }

    //insert at last
    if(temp -> next == NULL) {
        insertAtTail(tail, d);
        return ;
    }

    //creating a node for d
    Node* NodeToInsert = new Node(d);

    NodeToInsert -> next = temp -> next;

    temp -> next = NodeToInsert;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next ;
    }
    cout << endl;
}

 */

/*

int main() {

    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
    //cout << node1 -> next << endl;

    //head pointed to node1
    Node* head = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
    print(head);


    return 0;
}

 */

/*
int main() {

    //create a new node
    Node* node1 = new Node(10);

    //head/tail pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtTail(tail, 50);
    print(head);


    return 0;
}

 */

/*
int main() {

    //create a new node
    Node* node1 = new Node(10);

    //head/tail pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtTail(tail, 50);
    print(head);

    insertAtPosition(tail, head, 3, 99);
    print(head);

    insertAtPosition(tail, head, 1, 100);
    print(head);

    cout << "\nHead is pointing at => " << head->data << endl;
    cout << "Tail is pointing at => " << tail->data << endl << endl;

    return 0;
}

 */




/* 
//do it yourself
// Insertion by taking the input by user in the LL;
//code is not returning the position of tail

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

node *takeInput(node())
{

    int data;
    cout << "\n**Press -1 to stop taking data**";
    cout << "\nEnter the data to insert in Linked List => ";
    cin >> data;

    node *head = NULL;
    node *tail = NULL;

    while (data != -1)
    {

        node *newNode = new node(data);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode; // tail = tail -> next;
        }
        cin >> data;    

    }
    return head;    

}

void print(node *head)
{

    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{

    node *head = takeInput();
    print(head);

    cout << "\n\nHead is pointing to => " << head->data << endl;
    cout << "Tail is pointing to => "  << endl << endl;

    return 0;
}

 */




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
    if(temp -> next == NULL) {
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

Node* reverse(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    cout << "\nPrinting reversed LinkedList \n";
    return prev;
}


Node* getMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* merge(Node* &left, Node* &right)
{
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2-sorted linked list
    while(left != NULL && right != NULL)
    {
        if(left -> data < right -> data)
        {
            temp -> next = left;
            temp = left;
           left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
}

Node *mergeSort(Node* &head)
{
    //base case
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    //spliting the linked list into 2-halves
    Node* mid = getMid(head);
    
    mid -> next = NULL;
    Node* left = head;
    Node* right = mid -> next;
       
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merging both left and right halves
    Node* result = merge(left, right);
    
    return result;
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

    insertAtHead(head, 20);
    print(head);

    insertAtHead(head, 29);
    print(head);

    insertAtTail(tail, 40);
    print(head);

    insertAtTail(tail, 50);
    print(head);

    insertAtPosition(tail, head, 3, 55);
    print(head);

    insertAtPosition(tail, head, 5, 99);
    print(head);
    
    insertAtPosition(tail, head, 8, 100);
    print(head);

    insertAtPosition(tail, head, 1, 199);
    print(head);

    insertAtPosition(tail, head, 1, 400);
    print(head);

    cout << "calling mergeSort" << endl;
    Node* newHead = mergeSort(head);
    print(newHead);

    cout << endl ;
    cout << "Head is pointing at => " << head->data << endl;
    cout << "Tail is pointing at => " << tail->data << endl;
    cout << endl;


    return 0;
}


