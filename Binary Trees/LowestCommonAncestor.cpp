// #include<bits/stdc++.h>
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

Node* buildTree(Node* &root)
{   
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

Node* lca(Node* root,int n1,int n2){
    
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;
     
    Node* leftCheck = lca(root->left,n1,n2);
    Node* rightCheck = lca(root->right,n1,n2);

    if(leftCheck != NULL && rightCheck != NULL)
    {
        return root;//this is the common ancestor 
    }
    else if(leftCheck != NULL && rightCheck == NULL)
    {
        return leftCheck;//we found one of the key, now we go trail its path upwards
    }
    else if(rightCheck != NULL && leftCheck == NULL)
    {
        return rightCheck;//we found one of the key, now we go trail its path upwards
    }
    else
    {
        return NULL;
    }
    
} 

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    buildTree(root);
    Node* ans = lca(root,7,5);
    cout<<ans->data;
    return 0;
}