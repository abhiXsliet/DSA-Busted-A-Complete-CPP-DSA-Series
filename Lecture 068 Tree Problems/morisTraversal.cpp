// HW -> Morris Traversal whose sc = O(1) and tc = O(n)
// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion-and-without-stack/


#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this-> data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << " Enter the data => " ;
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) return NULL;

    cout << "\nFor inserting in left of " << data;
    root -> left = buildTree(root -> left);
    cout << "\nFor inserting in right of " << data;
    root -> right = buildTree(root -> right);

    return root;
}

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}

void morisTraversal(Node* root){
    Node* curr, *pred;

    if(root == NULL) return ;

    curr = root;
    while (curr != NULL)
    {
        if(curr -> left == NULL)
        {
            cout << curr-> data << " ";
            curr = curr -> right;
        }
        else
        {
            //find predecessor(ek baar left jana hota ushke baar right jaate rho jb tk null na mille)
            pred = curr -> left;
            while(pred -> right != NULL && pred -> right != curr){
                pred = pred -> right;
            }

            if(pred -> right == NULL){
                pred -> right = curr;
                curr = curr -> left;
            }
            else
            {
                pred -> right = NULL;
                cout << curr -> data << " ";
                curr = curr -> right;
            }
        }
    }
    
}

int main(){
    Node* root = NULL;
    //creating Tree using Recursion
    root = buildTree(root);
    cout << "Printing after calling Level Order Traversal" << endl;
    LevelOrderTraversal(root);
    morisTraversal(root);

    return 0;
}
