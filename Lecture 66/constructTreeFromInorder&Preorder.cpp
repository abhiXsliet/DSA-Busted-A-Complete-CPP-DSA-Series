// https://practice.geeksforgeeks.org/problems/construct-tree-1/1



//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

class Solution{
    public:

    Node* solve(int in[], int pre[], int &preorderIndex, int n, int inorderStart, int inorderEnd){
        //base case
        if(preorderIndex >= n || inorderStart > inorderEnd){
            return NULL;
        }
        
        int element = pre[preorderIndex++];
        Node* root = new Node(element);
        
        int position = inorderStart;
        
        for(; position < inorderEnd; position++){
            if(in[position] == element) break;
        }
        
        root -> left = solve(in, pre, preorderIndex, n, inorderStart, position - 1);
        root -> right= solve(in, pre, preorderIndex, n,  position + 1, inorderEnd);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex = 0;
        Node* ans = solve(in, pre, preorderIndex, n, 0, n-1);
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
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends