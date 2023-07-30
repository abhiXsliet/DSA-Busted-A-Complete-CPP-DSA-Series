#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int d) {
            this -> data = d;
            this -> next = NULL;
        }

        ~Node() {
                delete next;
        }
};

class Queue {
    Node* front;
    Node* rear;

    public:
        Queue() {
            front = rear = NULL;
        }

        void enque(int x) {
            Node* newNode = new Node(x);
            if(front == NULL) { // first element to enque
                front = rear = newNode;
                cout << "\nEnque node : " << rear -> data << endl;
                return ;
            }            
            rear -> next = newNode;
            rear = newNode;
            cout << "Enque node : " << rear -> data << endl;
        }

        void deque() {
            if(front == NULL) {
                cout << "\nNothing to deque" << endl;
                return;
            }
            // delete front which is temp node
            Node* temp = front;
            front = front -> next;
            cout << "Dequed node is : " << temp -> data << endl;
            temp -> next = NULL;
            if(front == NULL) { // if front becomes null then rear becomes NULL too.
                rear = NULL;
            }
            delete temp;
        }

        void isEmpty() {
            if(front == NULL) {
                cout << "Queue is empty " << endl;
            } else {
                cout << "Queue is not empty & front is pointing to : " << front -> data << endl;
            }
        }
};

int main() {

    Queue Q;
    Q.enque(10);
    Q.enque(20);
    Q.enque(30);
    Q.enque(40);
    Q.enque(50);
    Q.enque(60);
    cout << endl;
    Q.deque();
    Q.deque();
    Q.deque();
    Q.deque();
    cout << endl;
    Q.isEmpty();

    cout << endl;
    return 0;
}