#include <bits/stdc++.h>
using namespace std;

class Stack {
    public:
        queue<int> Q1, Q2;
        Stack() {

        }

        void push(int x) {
            Q2.push(x);
            cout << x << endl;
            while(!Q1.empty()) {
                int el = Q1.front();
                Q1.pop();
                Q2.push(el);
            }
            swap(Q1, Q2);
        }

        int pop() {
            if(Q1.empty()) {
                return - 1;
            } else {
                int el = Q1.front();
                Q1.pop();
                return el;
            }
        }

        int top() {
            if(!Q1.empty())
                return Q1.front();
            else return -1;
        }

        bool isEmpty() {
            if(!Q1.empty())
                return false;
            else return true;
        }
};

class Stack_UsingSingleQueue{
    public:
        queue<int> Q;
        Stack_UsingSingleQueue() {}

        void push(int x) {
            Q.push(x);
            for(int i = 0; i < Q.size(); i++) {
                int el = Q.front();
                Q.pop();
                Q.push(el);
            }
            cout << x << endl;
        }

        int pop() {
            if(Q.empty()) return -1;
            else {
                int el = Q.front();
                Q.pop();
                return el;
            }
        }

        int top() {
            if(Q.empty()) return -1;
            else {
                return Q.front();
            }
        }

        bool isEmpty() {
            if(Q.empty()) return 1;
            else return 0;
        }
};

int main() {
    Stack S;
    if(S.isEmpty()){
        cout << "\nStack is empty" << endl;
    } else {
        cout << " \nStack is not empty" << endl;
    }
    cout << "Popped Element : " << S.pop() << endl;
    S.push(10);
    cout << "Top Element : " << S.top() << endl;
    S.push(20);
    S.push(30);
    S.push(40);
    S.push(50);
    cout << "Poped Element : " << S.pop() << endl;
    cout << "Popped Element : " << S.pop() << endl;
    cout << "Top Element : " << S.top() << endl;
    if(S.isEmpty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }


    cout << "\n------IMPLEMENTING STACK USING SINGLE QUEUE-------" << endl;

    Stack_UsingSingleQueue S1;
    if(S1.isEmpty()) {
        cout << "\nStack is empty" << endl;
    } else {
        cout << "\nStack is not empty" << endl;
    }
    cout << "Top Element : " << S1.top() << endl;
    cout << "Popped Element : " << S1.pop() << endl;
    S1.push(100);
    cout << "Top Element : " << S1.top() << endl;
    cout << "Popped Element : " << S1.pop() << endl;
    S1.push(200);
    S1.push(300);
    S1.push(400);
    S1.push(500);
    cout << "Popped Element : " << S1.pop() << endl;
    cout << "Popped Element : " << S1.pop() << endl;
    cout << "Popped Element : " << S1.pop() << endl;
    cout << "Top Element : " << S1.top() << endl;
    if(S1.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    cout << endl;
    return 0;
}