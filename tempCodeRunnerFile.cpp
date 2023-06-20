
    void push(int val)
    {
        if(top >= size)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
            cout << arr[top] << endl;
        }
    }