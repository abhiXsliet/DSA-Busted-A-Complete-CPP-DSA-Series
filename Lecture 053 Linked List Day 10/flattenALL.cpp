// https://www.codingninjas.com/studio/problems/flatten-a-linked-list_1112655



#include <bits/stdc++.h> 
using namespace std;
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* mergeLinkedList(Node* down, Node* right)
{
    if(down == NULL)
        return right;
    if(right == NULL)
        return down;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    while(down != NULL && right != NULL)
    {
        if(down -> data < right -> data)
        {
            temp -> child = down;
            temp = down;
            down = down -> child;
        }
        else
        {
            temp -> child = right;
            temp = right;
            right = right -> child;
        }
    }
    
    if(down != NULL)
    {
        temp -> child = down;
        temp = down;
        down = down -> child;
    }
    
    if(right != NULL)
    {
        temp -> child = right;
        temp = right;
        right = right -> child;
    }
    return ans -> child;
}
Node* flattenLinkedList(Node* head) 
{
	//base case
    if(head == NULL)
        return head;
    
    //creating nodes
    Node* down = head;
    Node* right = head -> next;
    down -> next = NULL;
    
    //recursive calls for other part
    right = flattenLinkedList(right);
    
    //merging & returning sorted linked list down and right
    return mergeLinkedList(down, right);
}
