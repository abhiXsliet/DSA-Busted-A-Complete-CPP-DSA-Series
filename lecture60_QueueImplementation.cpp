#include<iostream>
#include<queue>
using namespace std;
//queue
//circular queue
//doubly ended queue (dequeue)

//43:00 HW
//i/p restricted queue => input is possible through one side only where the output can be done from the both side
// push_back( = rear), pop_back(rear)/pop_front => this is the condition of i/p restricted queue

//o/p restricted queue => input can be done through both the side but the ouput can be taken from only one of the side
//push_front()/push_back(rear) , pop_front() => this is the condition for o/p restricted queue

int main()
{
    /*
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    //front of queue is always remains the same
    cout << "Front of Queues is => " << q.front() << endl;
    q.push(40);
    q.push(50);
    cout << "Front of Queue is => " << q.front() << endl;

    cout << "The size of the queue is => " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();
    cout << "The size of the queue is => " << q.size() << endl;

    q.pop();
    q.pop();
    
    if(q.empty()) cout << "The Queue is empty" << endl;
    else cout << "The Queue is not empty" << endl;
    */


   deque<int> q;
   q.push_back(20);
   q.push_back(30);
   q.push_back(40);
   q.push_front(50);
   q.push_front(100);
   q.push_front(200);

   cout << "Size of Dequeue => " << q.size() << endl;
   q.pop_front();
   cout << "front element of dequeue => " << q.front() << endl;
   q.pop_front();
   q.pop_front();
   cout << "front element of dequeue => " << q.front() << endl;
   cout << "back element of dequeue => " << q.back() << endl;
   cout << endl;
   
   q.pop_front();
   cout << "front element of dequeue => " << q.front() << endl;
   cout << "back element of dequeue => " << q.back() << endl;
   cout << endl;
   
   q.pop_front();
   cout << "front element of dequeue => " << q.front() << endl;
   cout << "back element of dequeue => " << q.back() << endl;


}

//HW : Implement queue using stack