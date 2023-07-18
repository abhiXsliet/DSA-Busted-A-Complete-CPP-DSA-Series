// https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1



//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverse(Node* head)
    {
        Node* prev = NULL;
        Node* forward = NULL;
        Node* curr = head;
        
        while(curr != NULL)
        {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    void insertAtTail(struct Node* &head, Node* &tail, int val)
    {
        Node* temp = new Node(val);
        
        //empty ll
        if(tail == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail -> next = temp;
            tail = temp;
        }
    }
    
    struct Node* add(struct Node* first, struct Node* second)
    {
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        int carry = 0;
        while(first != NULL || second != NULL || carry != NULL)
        {
            int val1 = 0;
            if(first != NULL)
                val1 = first -> data;
                
            int val2 = 0;
            if(second != NULL)
                val2 = second -> data;
            
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            
            //adding digit into the node
            insertAtTail(ansHead, ansTail, digit);
            
            carry = sum/10;
            
            if(first != NULL)
                first = first -> next;
            
            if(second != NULL)
                second = second -> next;
        }
        
        return ansHead;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        //step-1 : reverse the given linked list
        first = reverse(first);
        second = reverse(second);
        
        //step-2 : add 2 LL
        Node* ans = add(first, second);
        
        //step-3 : reverse and return ans
        ans = reverse(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends