#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* minValue(Node* root){
    Node* temp = root;

    while (temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

Node* maxValue(Node* root){
    Node* temp = root;

    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }

    return temp;
}

void  findPredecessor(Node* root, Node* &pred, int x){
    //base case
    if(root == NULL) return;

    if(root -> data == x){
        if(root -> left != NULL){
            pred = maxValue(root -> left);
        }
    }
    else if(x < root -> data){
        pred = root;
        findPredecessor(root -> left, pred, x);
    }
    else if(x > root -> data){
        
        findPredecessor(root -> right, pred, x);
    }
    return ;
}

void findSuccessor(Node* root, Node* &succ, int x){
    //base case
    if(root == NULL) return ;

    if(root -> data == x){
        if(root -> right != NULL){
            succ = minValue(root -> right);
        }
    }else if( x > root -> data){
        //right part me jao
        succ = root;
        findSuccessor(root -> right, succ, x);
    }else{
        findSuccessor(root -> left, succ, x);
    }

    return ;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root == NULL){
        return root;
    }

    if(root -> data == val){
        //0 child
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        //1 child
            //left child
        if(root -> left != NULL && root -> right == NULL){
            Node* temp = deleteFromBST(root -> left, val);
            delete root;
            return temp;
        }

            //right child
        if(root -> left == NULL && root -> right != NULL){
            Node* temp = deleteFromBST(root -> right, val);
            delete root ;
            return temp;
        }

        //2 child
        if(root -> left != NULL && root -> right != NULL){
            //finding mini from the right part
            int mini = minValue(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }

    }else if(root -> data > val){
        //left part me jana hai

        root -> left = deleteFromBST(root -> left, val);
        return root;
    }else{
        //right part me jana hoga
        root -> right = deleteFromBST(root-> right, val);
        return root;
    }
}

void inOrderTraversal(Node* root){
    //base case
    if(root == NULL) return ;

    inOrderTraversal(root -> left);
    cout << root -> data << " " ;
    inOrderTraversal(root -> right);
}

void preOrderTraversal(Node* root){
    //base case
    if(root == NULL) return;

    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);

}

void postOrderTraversal(Node* root){
    //base case
    if(root == NULL) return ;

    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

void levelOrderTraversal(Node* root){
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

Node* insertIntoBST(Node* root, int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(data > root -> data){
        root -> right = insertIntoBST(root -> right, data);
    }

    if(data < root -> data){
        root -> left = insertIntoBST(root -> left, data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main(){
    Node* root = NULL;
    cout << "\nEnter the data to create BST => ";
    takeInput(root);

    cout << "\nPrinting BST using Level Order Traversal " << endl;
    levelOrderTraversal(root);

    cout << "\nPrinting BST using Inorder Traversal " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "\nPrinting BST using Pre-Order Traversal " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "\nPrinting BST using Post-Order Traversal " << endl;
    postOrderTraversal(root);

    cout << endl;
    cout << "\nMaximum value is => " << maxValue(root) -> data ;

    cout << endl;
    cout << "\nMinimum value is => " << minValue(root) -> data ;
    
    cout << endl;
    // int x;
    // cout << "\nEnter the element to find their predecessor => ";
    // cin >> x;
    // Node* pred = NULL;

    // findPredecessor(root, pred, x);
    // if(pred -> data != -1){
    //     cout << "\nThe predecessor of node " << x << " is " << pred -> data;
    // }else{
    //     cout << "\nThe predecessor of node doesn't exist";
    // }

    // cout << endl;
    // int k;
    // cout << "\nEnter the elements to find their successor => ";
    // cin >> k;
    // Node* succ = NULL;

    // findSuccessor(root, succ, k);
    // if(succ -> data != -1){
    //     cout << "\nThe Successor of node " << k << " is " << succ -> data ;
    // }else{
    //     cout << "\nThe Successor of node doesn't exist";
    // }
    // cout << endl << endl;

    //DELETION Of Node
    int val;
    cout << "\nEnter the val to delete from the BST => ";
    cin >> val;
    deleteFromBST(root, val);

    cout << "\nPrinting BST using Level Order Traversal AFTER DELETION" << endl;
    levelOrderTraversal(root);

    cout << "\nPrinting BST using Inorder Traversal " << endl;
    inOrderTraversal(root);
    cout << endl;
    cout << "\nPrinting BST using Pre-Order Traversal " << endl;
    preOrderTraversal(root);
    cout << endl;
    cout << "\nPrinting BST using Post-Order Traversal " << endl;
    postOrderTraversal(root);

    cout << endl;
    cout << "\nMaximum value is => " << maxValue(root) -> data ;

    cout << endl;
    cout << "\nMinimum value is => " << minValue(root) -> data ;


    return 0;
}

//What is inorder predecessor and how we calculate it?
//what is inorder successor and how we calculate it?

//v.v.i deletion of BST
