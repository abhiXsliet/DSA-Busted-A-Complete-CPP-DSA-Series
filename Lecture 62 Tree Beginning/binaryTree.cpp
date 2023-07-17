#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right= NULL;
    }
};

node* buildTree(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left  = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

node* levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //purana level complete ho chuka hai
            cout << endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }else
        {
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }            
        }

    }

}

void buildFromLevelOrderTraversal(node* &root){
    queue<node*>q;
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1){
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right node for " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1){
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

//HW
node* reverseLevelOrderTraversal(node* root){

    stack<node*> s;
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        s.push(temp);
        
        if(temp -> right) q.push(temp -> right);
        if(temp -> left ) q.push(temp -> left );
    }
    
    while(!s.empty()){
        node* temp = s.top();
        s.pop();
        
        cout << temp -> data << " ";
    }

}

void inOrderTraversal(node* root){
    //base case
    if(root == NULL){
        return;
    }

    //LNR or LPR
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void preOrderTraversal(node* root){

    //base case
    if(root == NULL){
        return;
    }

    //NLR or PLR
    cout << root->data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(node* root){

    //base case
    if(root == NULL){
        return ;
    }

    //LRN or LRP
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

int main()
{
    node* root = NULL;

    //creating a Tree using iteration 
    // buildFromLevelOrderTraversal(root);
    // levelOrderTraversal(root) ;


    //creating a Tree using recursion
    root = buildTree(root);

    //reverse level order traversal
    cout << "\nReverse of level order traversal" << endl;
    reverseLevelOrderTraversal(root);

    //level order traversal
    cout << "\nPrinting level order traversal " << endl;
    levelOrderTraversal(root);

    //Inorder Traversal
    cout << "\nPrinting inorder traversal " << endl;
    inOrderTraversal(root);

    cout << "\nPrinting pre-order traversal " << endl;
    preOrderTraversal(root);

    cout << "\nPrinting post-order traversal " << endl;
    postOrderTraversal(root);



    return 0;
}