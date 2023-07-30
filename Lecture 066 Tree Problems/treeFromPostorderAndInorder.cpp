// https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1



//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.

Node* solve(int in[], int post[], int inorderStart, int inorderEnd, int postorderStart, int &index){
    //base case
    if(index < 0 || inorderStart > inorderEnd){
        return NULL;
    }
    
    int element = post[index--];
    Node* root = new Node(element);
    
    int position = inorderStart;
    for(; position < inorderEnd ; position++){
        if(in[position] == element) break;
    }
    
    root -> right = solve(in, post, position + 1, inorderEnd, postorderStart, index);
    root -> left  = solve(in, post, inorderStart, position -1, postorderStart, index);
    
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    int index = n-1;
    Node* ans = solve(in, post, 0, n-1, 0, index);
    return ans;
}
