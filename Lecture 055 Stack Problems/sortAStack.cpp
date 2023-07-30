// https://www.codingninjas.com/studio/problems/sort-a-stack_985275



#include<bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &stack, int num)
{
    //base case
    if( (stack.empty()) || (!stack.empty() && stack.top() < num) )
    {
        stack.push(num);
        return;
    }
    
    int val = stack.top();
    stack.pop();
    
    //recursive call
    sortedInsert(stack, num);
    
    stack.push(val);
}

void sortStack(stack<int> &stack)
{
	//base case
    if(stack.empty())
        return;
    
    int num = stack.top();
    stack.pop();
    
    //recursive call
    sortStack(stack);
    
    sortedInsert(stack, num);
}