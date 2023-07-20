#include<iostream>
using namespace std;

//Time Complexity of all operation is O(1)
class Queue{
    private:
        int size;
        int *arr;
        int front;
        int rear;
    public:
        Queue() {
            size = 100001;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        bool isEmpty() {
            if(rear == front) return true;
            else return false;
        }

        void enqueue(int n) {
            if(rear == size) {
                cout << "Queue Overflow" << endl;
            } else {
                arr[rear] = n;
                rear++;
            }
        }

        int dequeue() {
            if(rear == front) {
                cout << "Queue underflow" << endl;
                return -1;
            } else {
                int ans = arr[front];
                arr[front] = -1;
                front++;

                //to avoid space wastage 
                if(front == rear) {
                    front = 0;
                    rear = 0;
                }
                return ans;
            }
        }

        int peek() {
            if(front == rear) return -1;
            else return arr[front];
        }
};


int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.peek() << endl;
    cout << q.peek() << endl;

    if(q.isEmpty()) cout << "Queue is empty" << endl;
    else cout << "Queue is not empty" << endl;


    return 0;
}