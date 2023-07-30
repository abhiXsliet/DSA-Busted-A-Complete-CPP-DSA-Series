// https://www.codingninjas.com/studio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465


#include <stack>
using namespace std;

class SpecialStack {
    
    stack<int> s;
    int mini;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //push for the 1st element
        if(s.empty()){
            s.push(data);
            mini = data;
        }else{
            if(data < mini){
                int val = 2*data - mini;
                s.push(val);
                mini = data;
            }else{
                s.push(data);
            }
        }        
    }

    int pop() {
        //underflow condition
        if(s.empty())
            return -1;
        
        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }else{
            int prevMini = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMini;
        }
        
    }

    int top() {
        if(s.empty())
            return -1;
        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else{
            return curr;
        }
    }

    bool isEmpty() {
        if(s.empty())
            return true;
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};