#include<iostream>
using namespace std;

//refer code studio link and solve given questions
//https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbS1CdW9EWk1USm1NRkhBaWZKWVExTDdHT0NCUXxBQ3Jtc0tsUXpINjNFVGhRTE5zYm81TXNaWjdZMkdDX0tQa3NGdVh0RXA4QS1tWDBQZGs1WDEwQ3NacjIwTVlDd1ZLUHZXSjRmQXE5aGNuUnFMSUlHN3I5QTNxV2VfaEJSNnc1Zlh1UFBSUlFYNWNhVlhaZVVWUQ&q=https%3A%2F%2Fbit.ly%2F3nPzcUK&v=q8gdBn9RPeI


class Node
{
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
        cout << "Memory getting free from the Node with data => " << val << endl;
    }
};

void insertInCLL(Node* &tail, int element, int d)
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
        //non-empty list & assuming element is present in list
        Node* curr = tail;
        while(curr -> data != element)
        {
            curr = curr -> next;
        }

        //element found & curr is represent element wala node
        Node* newNode = new Node(d);
        newNode -> next = curr -> next;
        curr -> next = newNode;
    }
}

void deleteInCLL(Node* &tail, int element)
{
    //empty list
    if(tail == NULL)
    {
        cout << "Empty list, No element found!" << endl;
        return;
    }
    else
    {
        //non-empty & assuming the element is present in the linked list
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != element)
        {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next ;
        
        //1 Node LL
        if(curr == prev)
        {
            tail = NULL;
        }

        //>=2 Node LL
        else if(tail == curr)
        {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
}

void print(Node *tail)
{
    Node* temp = tail;
    do{
        cout << tail -> data << " -> ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

int main()
{
    Node* tail = NULL;
    insertInCLL(tail, 2, 44);
    print(tail);

    insertInCLL(tail, 44, 55);
    print(tail);

    insertInCLL(tail, 55, 66);
    print(tail);

    insertInCLL(tail, 55, 77);
    print(tail);

    insertInCLL(tail, 77, 99);
    print(tail);
    
    insertInCLL(tail, 44, 299);
    print(tail);

    deleteInCLL(tail, 44);
    print(tail);

    deleteInCLL(tail, 77);
    print(tail);

    
    cout << "Tail => " << tail-> data << endl;
    return 0;
}