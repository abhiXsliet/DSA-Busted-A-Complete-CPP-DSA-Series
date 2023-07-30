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