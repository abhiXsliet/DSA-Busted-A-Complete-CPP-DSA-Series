// https://leetcode.com/problems/implement-queue-using-stacks/



#include<bits/stdc++.h>
using namespace std;


// TC = O(N)
// SC = O(2N)
class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    // TC = O(N)
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    // TC = O(1)
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    // TC = O(1)
    int peek() {
        if(!s1.empty()) {
            return s1.top();
        }
        else return -1;
    }
    
    // TC = O(1)
    bool empty() {
        if(s1.empty()) return 1;
        else return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */




// Another Approach 
// TC = amortised O(1)
// SC = O(2N)
class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {
        
    }
    // TC = O(1)
    void push(int x) {
        s1.push(x);
    }
    
    // TC = O(N)
    int pop() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        s2.pop();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    // TC = O(N)
    int peek() {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    // TC = O(1)
    bool empty() {
        if(s1.empty()) return 1;
        else return 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */