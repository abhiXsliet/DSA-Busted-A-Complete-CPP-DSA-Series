#include<bits/stdc++.h>
using namespace std;


// Stack Implementation using linked list

class Node
{
    public:
    int data;
    Node* link;

    Node(int d)
    {
        this -> data = d;
        this -> link = NULL;
    }
};

class Stack
{
    Node* top;
    public:
        Stack()
        {
            top = NULL;
        }
        
        void push(int element)
        {
            //creating a node & allocating memory dynamically
            Node* newNode = new Node(element);
            
            //checking stack has space or not
            if(!newNode)
            {
                cout << "Stack Overflow" << endl;
            }
            
            newNode -> data = element;
            newNode -> link = top;
            top = newNode;
            
        }

        void pop()
        {
            Node* newNode;

            //checking stack has element or not
            if(top == NULL)
            {
                cout << "Stack Underflow" << endl;
            }
            else
            {
                newNode = top;
                top = top -> link;
                delete newNode ;
            }
        }

        bool isEmpty()
        {
            return top == NULL;
        }

        int peek()
        {
            if(!isEmpty())
            {
                return top -> data;
            }
            else
            {
                cout << "Stack is empty" << endl;
                return -1;
            }
        }

        void display()
        {
            Node* temp ;
            if(temp == NULL)
            {
                cout << "Stack underflow" << endl;
            }
            else
            {
                temp = top;
                while(temp != NULL)
                {
                    cout << temp -> data << " -> " ;
                    temp = temp -> link;
                }cout << endl;
            }
        }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.display();
    cout << "Top element of stack is => " << st.peek() << endl;

    st.pop();
    st.pop();
    st.pop();
    st.display();
    cout << "Top element of stack is => " << st.peek() << endl;

    if(st.isEmpty())
    {
        cout << "Stack khali hai mere bhaai" << endl;
    }
    else
    {
        cout << "Stack is not khali mere bhaai" << endl;
    }

    cout << endl;
    return 0;
}