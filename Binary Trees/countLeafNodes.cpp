#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* BuildTree(Node* &root){
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

int countLeafNodes(Node* root){
    Node* temp=root;
    int count=0;
    
    if (temp == NULL)
    {
        return 0;
    }
        
    if(temp->left == NULL && temp->right == NULL)
    {   
        return 1;
    }

    count+=countLeafNodes(temp->left);
    count+=countLeafNodes(temp->right);
    
    return count;
}

int main(){
    system("cls");
    Node* root =NULL;
    BuildTree(root);
    cout<<countLeafNodes(root);
    return 0;
}