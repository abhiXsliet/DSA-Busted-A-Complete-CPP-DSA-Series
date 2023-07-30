//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;

//Queue 
#include<queue>

int main(){
    // TC for all operations -> O(1)
    queue<string> q;

    q.push("Abhishek");
    q.push("Kumar");
    q.push("Sharma");

    cout << "Size before pop -> " << q.size() << endl;

    cout << "First Element -> " << q.front() << endl;

    q.pop();
    cout << "Fist Element -> " << q.front() << endl;

    cout << "Size after pop -> " << q.size() << endl;

    return 0;
}
