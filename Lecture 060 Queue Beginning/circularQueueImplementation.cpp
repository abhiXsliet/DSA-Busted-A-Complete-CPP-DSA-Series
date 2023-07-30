#include<iostream>
using namespace std;

class Circular_Queue{
    private:
        int *arr;
        int size;
        int rear;
        int front;

    public:
        Circular_Queue() {
            size = 100001;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool enqueue(int data) {
            if(front == 0 && rear == size-1 || rear == (front-1) % (size-1)) {
                cout << "Queue is full" << endl;
                return false;
            }
            else if(front == -1) { // first element to push
                front = rear = 0;
            } 
            else if(rear == size-1 && front != 0) { // rear on the last element
                rear = 0;
            } 
            else { // normal case
                rear++;
            }

            arr[rear] = data;
            return true;
        }

        int dequeue() {
            if(front == -1) { // empty queue
                cout << "Nothing available, Queue is empty" << endl;
                return -1;
            } 
            int ans = arr[front];
            arr[front] = -1;
            if(front == rear) { // only single element present
                front = rear = -1;
            }
            else if(front == size-1) { // on the last element
                front = 0;
            } 
            else { // normal case
                front++;
            }
            return ans;
        }

        bool isEmpty() {
            if(front == -1) return true;
            else false;
        }

        int peek() {
            return arr[front];
        }
};

int main() {
    Circular_Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);

    cout << "Front of Queue : " << q.peek() << endl;
    cout << "Element dequeued : " << q.dequeue() << endl;
    cout << "Element dequeued : " << q.dequeue() << endl;
    cout << "Element dequeued : " << q.dequeue() << endl;
    cout << "Element dequeued : " << q.dequeue() << endl;
    cout << "Front of Queue: " << q.peek() << endl;

    cout << "Element dequeued : " << q.dequeue() << endl;
    cout << "Element dequeued : " << q.dequeue() << endl;
    cout << "Element dequeued : " << q.dequeue() << endl;
    cout << "Front of Queue: " << q.peek() << endl;
    
    if(q.isEmpty()) cout << "Queue is empty" << endl;
    else cout << "Queue is not empty" << endl;

    return 0;
}


/* 
Input Restricted Queue : Input is possible through one side (i.e., rear) only but the output can be taken from both the sides.
        push_back(rear), pop_front() || pop_back()

Output Restricted Queue : Input can be done through both the sides but the ouput can be taken from only one of the side.
        push_front(data) || push_back(data) , pop_front()

Doubly Ended Queue : Input and output can be possible on both the sides.
    push_front(data) || push_back(data), pop_front() || pop_back()

    - Dequeue can be used to implement both stack and queue
    - can be considered as circular queue with some additional functionality.
 */