#include <iostream>
using namespace std;

// Q: Convert BST To Min Heap
// https://www.codingninjas.com/codestudio/problems/convert-bst-to-min-heap_920498?leftPanelTab=0

// #include <bits/stdc++.h> 
// /*************************************************************
    
//     Following is the Binary Tree node structure:

// 	class BinaryTreeNode {
		
// 	public :
// 		int data;
// 		BinaryTreeNode* left;
// 		BinaryTreeNode* right;

// 		BinaryTreeNode(int data) {
// 		this -> left = NULL;
// 		this -> right = NULL;
// 		this -> data = data;
// 		}
// 	};

// *************************************************************/
// void inOrder(BinaryTreeNode* root, vector<int> &v){
// 	//base case
// 	if(root == NULL)
// 		return;
	
// 	inOrder(root -> left, v);
// 	v.push_back(root -> data);
// 	inOrder(root -> right, v);
// }

// void preOrder(BinaryTreeNode* root, vector<int> &v, int &index){
// 	//base case
// 	if(!root)
// 		return ;
	
// 	root -> data = v[index++];
// 	preOrder(root -> left, v, index);
// 	preOrder(root -> right, v, index);
// }

// BinaryTreeNode* convertBST(BinaryTreeNode* root)
// {
//     //edge case
// 	if(root == NULL)
// 		return NULL;
	
// 	vector<int>v;
// 	inOrder(root, v);
// 	int index = 0;
// 	preOrder(root, v, index);
// 	return root;
// }






