#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << endl;
        cout << "Memory free for node with data : " << val;
        cout << endl;
    }
};

void insertAtStart(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    // inserting at starting
    if (pos == 1)
    {
        insertAtStart(head, tail, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // inserting at position
    // creating a node
    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteAtPosition(Node *&head, Node* &tail, int pos)
{
    // deletion at starting
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deletion at last
        int cnt = 1;
        Node *prev = NULL;
        Node *curr = head;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        tail = prev;
        curr -> prev = NULL;
        prev -> next = curr->next;
        curr -> next = NULL;

        // Update tail
        while(tail -> next != NULL) {
            tail = tail -> next;
        }
        delete curr;
    }
}

Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    cout << "\nReverse of Linked List" << endl;
    return prev;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp -> data << " <-> ";
        temp = temp -> next;
    }
    cout << endl;
}

// gives length of Linked List
int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    cout << "Length of Linked List : " << getLength(head) << endl;
    cout << endl;

    insertAtStart(head, tail, 30);
    print(head);

    insertAtTail(head, tail, 55);
    print(head);

    insertAtTail(head, tail, 111);
    print(head);

    insertAtPosition(head, tail, 3, 99);
    print(head);

    insertAtPosition(head, tail, 4, 400);
    print(head);

    insertAtPosition(head, tail, 1, 10);
    print(head);

    deleteAtPosition(head, tail, 1);
    print(head);    

    deleteAtPosition(head, tail, 3);
    print(head);

    deleteAtPosition(head, tail, 4);
    print(head);

    cout << "\nHead is pointing at : " << head->data << endl;
    cout << "Tail is pointing at : " << tail->data << endl;
    cout << "Length of Linked List : " << getLength(head) << endl;

    Node *newNode = reverse(head);
    print(newNode);

    cout << endl;
    return 0;
}
