#include<iostream>
#include<stack>
using namespace std;


int main()
{
    //creation of stack using STL
    stack<int>s;
    
    //push operation
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    //pop operation
    s.pop();
    s.pop();
    s.pop();

    cout << "Top element of the stack => " << s.top() << endl;

    if(s.empty())
    {
        cout << "Element is not present in stack" << endl;
    }
    else
    {
        cout << "Element is present in stack" << endl;
    }

    cout << "Size of stack => " << s.size() << endl;

    return 0;
}
