//Q1. reverse a queue
//Q2. first negative integer in every K size window -> HW : find the optimal approach for the problem
//Q3. reverse a queue of k-times
//Q4. (Do it again)first non-repeating characters in a stream link => https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
//Q5. Circular Tour (vvi) link => https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1
//Q6. (HW)=> Interleave the first halves of the queue with the second half link => https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/
//Q7. (HW)=> implement queue using stack 
//Q8. (HW)=> implement stack using queue
//Q9. Implement N Queue into a single array



//Q1 logic
//I-> pop all the elements from the queue and push it into the stack TC=O(n), SC=O(n)
//II-> By using the recursion create a solve fn. call it and return it in main TC=O(n), SC=O(1)

//Q2 logic
//create a dequeue and a vector of ans
//1-> process first K-sized window
//  i-> push_back K-sized window's element into the dequeue
//  ii-> store element into the ans for K-sized window 
//2-> process the remaining K-sized window
//  i-> removing logic
//  ii-> addition logic
//  ii-> store the ans for remaining K-sized window's element

//Q3 logic
//1 -> fetch k-elements from the Queue and put it back into the stack
//2 -> fetch all the elements from stack and put into Queue
//3 -> fetch first n-k elements from queue and put it into queue

//Q4 logic
//1 -> we create an unordered map<char, int> count; and a queue<int> q; also a vector named ans 
//2 -> 

/* 
//Implementing N-Queues in a single array 
// HW => Dry run
#include<iostream>
using namespace std;

class Kqueue{

    int n;
    int k;
    int* arr;
    int* front;
    int* rear;
    int* next;
    int freeSpot;
    public:
        Kqueue(int n, int k){
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];

            //initialising front and rear with -1
            for(int i=1; i<k; i++){ //if i=0 then you have to decrease the no. of queue by 1;
                front[i] = -1;
                rear[i] = -1;
            }

            //initialising next
            next = new int[n];
            for(int i=0; i<n; i++){
                next[i] = i+1;
            }
            next[n-1] = -1;

            arr = new int[n];
            freeSpot = 0;
        }

        void enqueue(int data, int qn){
            
            //check overflow condition
            if( freeSpot == -1 ){
                cout << "Free space is not available" << endl;
                return;
            }

            //find first free index
            int index = freeSpot;

            //update freespot
            freeSpot = next[index];

            //check whether first element
            if(front[qn] == -1){
                front[qn] = index;
            }else{
                //link new element to prev element
                next[rear[qn]] = index;
            }

            //update next
            next[index] = -1;

            //update rear
            rear[qn] = index;

            //push element
            arr[index] = data;
        }

        int dequeue(int qn){

            //check underflow condition
            if(front[qn] == -1){
                cout << "Queue Underflow" << endl;
                return -1;
            }

            //find the index to pop
            int index = front[qn];

            //front ko aage badhado (delete karne ke baad front ko aage badhate the)
            front[qn] = next[index];

            //freeSpot ko manage kro
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }
};

int main()
{
    Kqueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);


    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}

 */




