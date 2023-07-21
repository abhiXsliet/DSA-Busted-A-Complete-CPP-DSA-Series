#include <bits/stdc++.h>
using namespace std;

// What is a Linked List?
//  It is a type of linear data structure which is made by using collection of Nodes.
//  A nodes holds the data field and the address of the next node (or a pointer to the next node)

// Why LL is needed?
// LL is a dynamic DS which can grow and shrink at the run time therefore there is no wastage of memory.

// Types of Linked List :-
// (1). Singly LL -> A type of LL where each node contains a data field and a pointer that points to the next node in the list.
// (2). Doubly LL -> A type of LL where each node contains a data field and two pointers, one pointing to the previous node and one pointing to the next node in the list.
// (3). Circular LL -> A type of LL where the last node points back to the first node, forming a circular structure.
// (4). Circular Doubly LL -> A type of LL where each node contains a data field and two pointers, one pointing to the previous node and one pointing to the next node in the list, and the last node points back to the first node, creating a circular structure.


// Node declaration
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
        if(this -> next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "\nMemory is free for node with data : " << value << endl; 
    }
};

void insertAtHead (Node* &head, int d) {
    // create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail (Node* &tail, int d) {
    // create new node
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

    // create a node for d
    Node* NodeToInsert = new Node(d);
    NodeToInsert -> next = temp -> next;
    temp -> next = NodeToInsert;
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

Node* reverse(Node* &head, Node* &tail)
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

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " -> ";
        temp = temp -> next ;
    }
    cout << endl;
}

int main() {

    //created a new node
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;

    // head/tail pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtHead(head, 15);
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

    deleteAtPosition(1, head, tail);
    print(head);

    deleteAtPosition(5, head, tail);
    print(head);

    deleteAtPosition(6, head, tail);
    print(head);

    cout << "\nHead is pointing at => " << head -> data << endl;
    cout << "Tail is pointing at => " << tail -> data << endl;
    
    Node* newHead = reverse(head, tail);
    print(newHead);    

    cout << endl;
    return 0;
}