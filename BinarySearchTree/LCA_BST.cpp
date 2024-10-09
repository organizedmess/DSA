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

Node* construct(Node* root, int d){
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > (root->data))
    {
        root->right = construct(root->right,d); 
    }
    if (d < (root->data))
    {
        root->left = construct(root->left,d);
    }

    return root;
}

void insertion(Node* &root){
    int data;
    cin>>data;

    while (data != -1)
    {
        root = construct(root,data);
        cin>>data;   
    }
}

int lca_bst(Node* root ,int a,int b){
    if (root == NULL)
        return -1;
    
    int res = -1;
    // only one of these conditions will be executed
    if (root->data > a && root->data > b)
    {
        res = lca_bst(root->left,a,b);
    }
    else if (root->data < a && root->data < b)
    {
        res = lca_bst(root->right,a,b);
    }
    else if (a < root->data && root->data < b )
    {
        res = root->data;
    }
    return res;
}

int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<"Enter data for tree :"<<endl;
    insertion(root);
    
    cout<<lca_bst(root,1,5);
    return 0;
}