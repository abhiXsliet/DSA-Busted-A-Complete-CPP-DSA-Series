// https://www.codingninjas.com/studio/problems/valid-parenthesis_795104


#include<bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;
    for(int i=0; i<expression.length(); i++)
    {
        char ch = expression[i];
        
        //if opening bracket --> we do push opr
        //if closing bracket --> we do check stacktop and perform pop opr
        
        if(ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            //for closing bracket
            if(!s.empty())
            {
                char top = s.top();
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if(s.empty())
        return true;
    else
        return false;
}