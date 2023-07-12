// https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472


#include<bits/stdc++.h>
using namespace std;
/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

void inorder(TreeNode<int>* root, vector<int> &v){
    //base case
    if(root == NULL)
        return ;

    inorder(root -> left, v);
    v.push_back(root -> data);
    inorder(root -> right, v);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int>& v){
    if(s>e)
        return NULL;

    int mid = (s+e)/2;

    TreeNode<int>* newRoot = new TreeNode<int>(v[mid]);

    newRoot -> left = inorderToBST(s, mid -1, v);
    newRoot -> right = inorderToBST(mid+1, e, v);
    return newRoot;
}

TreeNode<int>* balancedBst(TreeNode<int>* root){
    vector<int>v;

    //store inorder -> sorted values
    inorder(root, v);
    
    return inorderToBST(0, v.size()-1, v);
}

