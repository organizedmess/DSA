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

int findKsmall(Node* root,int k,int &count)
{   
    if (root == NULL)
        return -1;
    //L
    int left = findKsmall(root->left,k,count);
    
    //N
    count++;
    if (count == k)
        return root->data;

    //R
    return findKsmall(root->right,k,count);
    
}

int main(){
    system("cls");

    return 0;
}