// https://www.codingninjas.com/studio/problems/two-sum-in-a-bst_1062631


#include <bits/stdc++.h> 
using namespace std;
// Following is the Binary Tree node structure
/**************
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
***************/

void inorder(BinaryTreeNode<int>* root, vector<int> &in){
    //base case
    if(root == NULL)
        return;

    inorder(root-> left, in);
    in.push_back(root -> data);
    inorder(root -> right, in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {

	vector<int>inorderVal;

    //store inorder -> sorted values in vector
    inorder(root, inorderVal);

    //Use 2-pointer approach to check if pair exists
    int i = 0; 
    int j = inorderVal.size()-1;
    
    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target){
            return true;
        }
        else if( sum > target){
            j--;
        }
        else{
            i++;
        }
    }
    return false;
}