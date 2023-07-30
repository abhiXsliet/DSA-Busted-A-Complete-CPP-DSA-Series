#include<iostream>
#include<stack>
using namespace std;

class Stack
{
    //properties
    public:
    int top;
    int *arr;
    int size;

    //behaviour
    Stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = val;
            cout << arr[top] << endl;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    //other way
    // void push(int val)
    // {
    //     if(top >= size)
    //     {
    //         cout << "Stack overflow" << endl;
    //     }
    //     else
    //     {
    //         top++;
    //         arr[top] = val;
    //         cout << arr[top] << endl;
    //     }
    // }
    

    void pop()
    {
        if(top <= -1)
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            cout << "Popped - " << arr[top] << endl;
            top--;
        }
    }

    int peek()
    {
        if(top > -1)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main()
{
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << "Peek Of Stack - " << st.peek() << endl;

    st.pop();
    st.pop();

    cout << "Peek Of Stack - " << st.peek() << endl;

    if(st.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }


    cout << endl;
    return 0;
}