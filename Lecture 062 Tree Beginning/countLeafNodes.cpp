// https://www.codingninjas.com/studio/problems/count-leaf-nodes_893055


#include<bits/stdc++.h>
using namespace std;

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
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
    
***********************************************************/
void inOrderTraversal(BinaryTreeNode<int> *root, int &cnt){
    //base case
    if(root == NULL) return;
    
    //LNR
    inOrderTraversal(root -> left, cnt);
    
    //counting leaf nodes
    if(root -> left == NULL && root -> right == NULL){
        cnt ++;
    } 
    
    inOrderTraversal(root -> right, cnt);  
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt = 0;
    inOrderTraversal(root, cnt);
    return cnt;
}