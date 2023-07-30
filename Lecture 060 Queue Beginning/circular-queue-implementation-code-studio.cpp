// https://www.codingninjas.com/studio/problems/circular-queue_1170058



#include <bits/stdc++.h>
using namespace std; 

class CircularQueue{
    int* arr;
    int rear;
    int front;
    int size;
    public:
    CircularQueue(int n){
        // Write your code here. 
        size = n;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        //check full condition
        if((front==0 && rear==size-1) || (rear == (front-1) % (size-1)))
            return false;
        else if(front == -1 ) // to insert first element
            front = rear = 0;
        else if( front != 0 && rear == size -1 ) // to maintain the cyclic condition
            rear = 0;
        else // normal flow
            rear++;

        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        //check empty condition
        if(front == -1)
            return -1;
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)// condition for single element
            front = rear = -1;
        else if(front == size-1) // to maintain the cyclic flow
            front = 0;
        else //normal flow
            front++;
        return ans;         
    }
};