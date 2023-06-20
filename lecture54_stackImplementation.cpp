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
/* 
 */
/* 

class Stack
{
    public:
    int top;
    int *arr;
    int size;

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

    //my logic here we are including index 0 while pushing elements
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
            top--;
        }
    }

    int peek()
    {
        if(top >= -1)
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
    Stack st(4);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << st.peek() << endl;

    st.pop();
    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty())
    {
        cout << "Stack khali hai mere dost" << endl << endl;
    }
    else
    {
        cout << "Stack khali nhi hai mere dost" << endl << endl;
    }
}

 */


/* 

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

}

 */


//Did question on coding ninja
//Two stack problem using an array