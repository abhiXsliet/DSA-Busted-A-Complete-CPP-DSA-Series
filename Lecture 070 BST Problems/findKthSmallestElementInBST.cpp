// https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333


#include <bits/stdc++.h> 
using namespace std;
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int>* root, int &i, int k) {
    //base case
    if(root == NULL)
        return -1;

    //left part
    int left = solve(root -> left, i, k);
    
    if(left != -1){
        return left;
    }
    i++;

    if(i == k) return root -> data;

    return solve(root -> right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    int ans = solve(root, i, k);
    return ans;
}