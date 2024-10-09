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

Node* BuildTree(Node* root){
    int data;
    cout<<"enter the data:"<<endl;
    cin>>data;
    Node* temp = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    root->left = BuildTree(root->left);
    root->right = BuildTree(root->right);

    return root;   
}

bool CheckIdentical(Node* r1,Node* r2)
{
    if(r1 == NULL && r2 == NULL){
        return 1;
    }
    else if(r1 == NULL && r2 != NULL){
        return 0;
    }
    else if(r1 != NULL && r2 == NULL){
        return 0;
    }
    

    bool Checkleft= isIdentical(r1->left,r2->left);
    bool CheckRight=isIdentical(r1->right,r2->right);
    bool check = (r1->data == r2->data);
    
    if(Checkleft == 1 && CheckRight == 1 && check == 1)
        return 1;    
    
    else
        return 0;    
}

int main(){
    system("cls");
    
    return 0;
}