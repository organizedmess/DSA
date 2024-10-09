#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node *BuildTree(Node* &root){
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;
    root = new Node(data);

    if (data==-1)
    {
        return NULL;
    }
    
    cout<<"Enter The data for the left Node of "<<data<<":"<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter The data for the right Node of "<<data<<":"<<endl;
    root->right=BuildTree(root->right);

    return root;
}

bool Validate(Node* root,int min,int max){
   //BASE CASE
    if (root == NULL)
        return 1;
    
    if((min < root->data) && (root->data < max))
    {
        bool leftCheck = Validate(root->left,min,root->data);
        bool rightCheck = Validate(root->right,root->data,max);
        
        return leftCheck && rightCheck;
    }
    else
    {
        return 0;
    }
}

bool isBST(Node* root){
    return Validate(root,INT64_MIN,INT64_MAX);
}

int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<"Enter data for tree :"<<endl;
    BuildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    cout<<isBST(root);
    return 0;
}