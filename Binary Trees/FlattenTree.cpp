#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data= d;
        Node* left = NULL;
        Node* right = NULL;
    }
};

Node* buildTree(Node* &root){   
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;
    root = new Node(data);
    
    if (data == -1)
        return NULL;
    
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);

    return root;
}
//We will use Morris traversal becoz space constraint is O(1)
void flatten(Node* &root){
    Node* curr = root;
    Node* predec;

    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            predec = curr->left;
            while(predec->right != NULL)
                predec = predec->right;
            
            predec->right = curr->right;
            curr->right = curr->left;//now we dont need curr->left
            curr->left = NULL;
        }
        //as curr->right is actually pointing towards curr->left
        curr = curr->right;
    }
    cout<<"done";
    return;
}

int main(){
    system("cls");
    Node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildTree(root);
    
    flatten(root);
    return 0;
}