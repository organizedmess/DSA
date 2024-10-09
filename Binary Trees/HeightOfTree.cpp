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


int FindHeight(Node* root,int h)
{   Node* temp=root;

    if(temp==NULL)
       return h;//BASE CASE
    
    h++;
    int l=FindHeight(temp->left,h);
    int R=FindHeight(temp->right,h);
    if (l > R)
       return l; 
    
    else
       return R; 

}

int FindHeight2(Node* root)
{
    if(root == NULL)
        return 0;
    
    
    int left = FindHeight2(root->left);
    int right= FindHeight2(root->right);

    if (left > right)
        return left+1;
    else
        return right+1;
    
}


int main(){
    // system("cls");
    Node* root=NULL;
    BuildTree(root);

    cout<<FindHeight(root,0);
    cout<<endl;
    cout<<FindHeight2(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 9 10 3 -1 -1 -1 -1 -1 -1
    return 0;
}