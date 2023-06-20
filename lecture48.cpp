#include<bits/stdc++.h>
using namespace std;

//remove duplicates from the sorted linked list problem on code studio -> done
//HW :- remove duplicates from the unsorted linked list problem on code studio 
// use all 3-ways to solve the homework 
//1. you can solve using two while loop in the order of time complexity = (n2) & space complexity = O(1)
//2. you can solve using map where your tc = O(n) ans space complexity incresed to O(n);
//3. you can sorted the given ll first by using O(nlog) time complexity and then solve it


//HW :- split the circular linked into the two half problem 

//Q. Remove duplicates from an unsorted linked list 
//fist approach code;
/* 


Node *removeDuplicates(Node *head)
{
    if(head == NULL)
    {
        return head;
    }
    
    Node* curr = head;
    while(curr != NULL && curr -> next != NULL) //not required curr -> next != NULL
    {
        Node* temp = curr;
        while(temp -> next != NULL)
        {
            if(curr -> data == temp -> next -> data)
            {
                Node* nodeToDel = temp -> next;
                temp -> next = temp -> next -> next;
                delete(nodeToDel);
            }else{
                temp = temp -> next;
            }
        }
        curr = curr -> next;
    }
    return head;
}

 */


Node* getMid(Node* &head)
{
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* merge(Node* &left, Node* &right)
{
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2-sorted linked list
    while(left != NULL && right != NULL)
    {
        if(left -> data < right -> data)
        {
            temp -> next = left;
            temp = left;
           left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL)
    {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL)
    {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
}

Node *mergeSort(Node* &head)
{
    //base case
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    
    //spliting the linked list into 2-halves
    Node* mid = getMid(head);
    
    mid -> next = NULL;
    Node* left = head;
    Node* right = mid -> next;
       
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merging both left and right halves
    Node* result = merge(left, right);
    
    return result;
}    

