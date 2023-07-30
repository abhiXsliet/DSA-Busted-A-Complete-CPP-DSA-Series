//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;

//doubly ended queue or deque (pronounced as 'deck');
#include<deque>

//perform all previous opr.
//it is dynamic in nature since it can reduce or enlarge their size

int main(){
    deque<int> d;
    
    d.push_back(1);
    d.push_front(2);
    d.push_back(5);
    d.push_back(6);
    for(int i:d){
        cout << i << " ";
    }

    
    d.pop_back();
    cout << endl;
    for(int i: d){
        cout << i << " ";
    }

    d.pop_front();
    cout << endl;
    for(int i:d){
        cout << i << " ";
    }

    
    cout << endl;
    cout << "printing first Index element -> " << d.at(1) << endl;
    cout << "front -> " << d.front() << endl;
    cout << "back -> " << d.back() << endl;

    cout << "Empty or not -> " << d.empty() << endl;

    cout << "before erase ==> " << d.size() << endl;

    // we tell the range of deletion here
    d.erase(d.begin(), d.begin()+1); 

    // erase will reduced the size to zero but the capacity remains the same
    cout << "after erase ==> " << d.size() << endl;

    for(int i:d){
        cout << i << " ";
    }

    //TC of all operations are o(1) 
    //TC of erase operation will be o(n) since we are traversing through each element;

}
