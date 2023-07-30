// https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103


#include <bits/stdc++.h> 
using namespace std;
/************************************************************

    Following is the Binary Tree node structure
    
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
class info{
   public:
       int size;
       bool isBST;
       int max;
       int min;
       
};
info solve(TreeNode<int>* root,int &ans){
   if(root==NULL)
       return{0,true,INT_MIN,INT_MAX};
   info left=solve(root->left,ans);
   info right=solve(root->right,ans);
   
   info curr;
   curr.min=min(root->data,left.min);
   curr.max=max(root->data,right.max);
   curr.size=left.size+right.size+1;
   if((root->data>left.max && root->data<right.min) && left.isBST && right.isBST)
   {
       curr.isBST=true;
   }
   else
   {
       curr.isBST=false;
   }
   if(curr.isBST)
       ans=max(curr.size,ans);
   return curr;
}

int largestBST(TreeNode<int>* root) 
{
   int ans=0;
   info dummy= solve(root,ans);
   return ans;
}