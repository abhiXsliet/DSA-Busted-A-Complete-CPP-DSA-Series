//1. reverse a linked list in group of k
//2. return true or false if the linked is circular or not?

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }

    //Destructor
    ~Node()
    {
        int val = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << endl;
        cout << "Memory getting free from the Node with data => " ;
    }
};

Node* insertInCLL(Node* &tail, int element, int d)
{
    //empty list
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else
    {
        //non-empty list and assuming element is present
        Node* curr = tail;
        while(curr -> data != element)
        {
            curr = curr -> next;
        }

        //element found and curr is representing element's Node
        Node* newNode = new Node(d);
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
}

bool isCircular(Node* tail)
{
    if(tail == NULL)
    {
        return true;
    }

    Node* temp = tail -> next;

    while(tail != NULL && temp != tail)
    {
        temp = temp -> next;
    }

    if(temp -> next == NULL)
    {
        return false;
    }
    if(temp -> next == tail)
    {
        return true;
    }
}

void print(Node* tail)
{
    Node* temp = tail;
    do{
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }while(temp != tail);
    cout << endl;
}

int main()
{
    Node* tail = NULL;
    insertInCLL(tail, 1, 20);
    print(tail);

    insertInCLL(tail, 20, 33);
    print(tail);

    insertInCLL(tail, 20, 88);
    print(tail);

    insertInCLL(tail, 88, 90);
    print(tail);

    if(isCircular(tail))
    {
        cout << "LL is circular in nature" ;
    }else{
        cout << "LL is not circular in nature";
    }

    return 0;

}