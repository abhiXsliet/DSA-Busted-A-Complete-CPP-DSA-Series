//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;
 
//stack 
#include<stack>

int main(){
    // TC for all operations -> O(1)
    stack<string> s;

    s.push("Abhishek");
    s.push("Kumar");
    s.push("Sharma");

    cout << "Top Element -> " << s.top() << endl;

    s.pop();
    cout << "Top Element -> " << s.top() << endl;

    cout << "size of stack -> " << s.size() << endl;

    cout << "Empty or not -> " << s.empty() << endl;

    return 0;
}
