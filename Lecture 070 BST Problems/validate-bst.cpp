// https://www.codingninjas.com/codestudio/problems/validate-bst_799483


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

bool isBST(BinaryTreeNode<int> *root, int min, int max){
    //base case 
    if(root == NULL){
        return true;
    }

    if(root -> data >= min && root -> data <= max){
        bool left = isBST(root -> left, min, root -> data);
        bool right = isBST(root -> right, root -> data, max);
        return left && right;
    }else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}

