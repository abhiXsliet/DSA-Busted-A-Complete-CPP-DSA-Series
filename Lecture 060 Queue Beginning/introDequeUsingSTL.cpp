#include<bits/stdc++.h>
using namespace std;


int main()
{
    //deque initialization
    deque<int> q;

    q.push_back(20);
    q.push_back(30);
    q.push_back(40);
    q.push_front(50);
    q.push_front(100);
    q.push_front(200);

    cout << "Size of Dequeue : " << q.size() << endl;
    cout << "front element of dequeue : " << q.front() << endl;
    cout << "back element of dequeue : " << q.back() << endl;
    
    q.pop_front();
    q.pop_front();
    cout << "front element of dequeue : " << q.front() << endl;
    cout << "back element of dequeue : " << q.back() << endl;
    cout << endl;
    
    q.pop_front();
    cout << "front element of dequeue : " << q.front() << endl;
    cout << "back element of dequeue : " << q.back() << endl;
    cout << endl;
    
    q.pop_front();
    cout << "front element of dequeue : " << q.front() << endl;
    cout << "back element of dequeue : " << q.back() << endl;

    cout << endl;
    return 0;
}