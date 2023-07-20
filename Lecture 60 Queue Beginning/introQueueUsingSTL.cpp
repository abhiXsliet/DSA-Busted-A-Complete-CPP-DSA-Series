#include<iostream>
#include<queue>
using namespace std;


int main() {
    //create a queue
    queue<int> q;

    q.push(11);
    cout << "\nfront of q is : " << q.front() << endl;

    q.push(15);
    cout << "front of q is : " << q.front() << endl;

    q.push(13);
    cout << "front of q is : " << q.front() << endl;

    cout << "Size of queue is : " << q.size() << endl;

    q.pop();
    cout << "front of queue is : " << q.front() << endl;
    q.pop();
    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if(q.empty()) cout << "Queue is empty" << endl;
    else cout << "Queue is not empty" << endl;


    cout << endl;
    return 0;
}