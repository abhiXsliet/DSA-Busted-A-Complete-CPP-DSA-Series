// https://www.codingninjas.com/codestudio/problems/lca-in-a-bst_981280


#include <bits/stdc++.h> 
using namespace std;
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    //iterative solution 
    while(root != NULL){
        if(root -> data > P -> data && root -> data > Q -> data)
            root = root -> left;

        else if(root -> data < P -> data && root -> data < Q -> data)
            root = root -> right;

        else
            return root;
    }

}






