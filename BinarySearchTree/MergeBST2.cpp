#include<iostream>
#include<queue>
#include<vector>
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

//  method 2
void inorder(Node* root,vector<Node*> &v){
    if(root == NULL)
        return ;

    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}

void BSTintoSorted_LL(Node* root,Node* &head){
    if (root == NULL)
        return NULL;

    BSTintoSorted_LL(root->right,head);

    if (head != NULL)
    {
        head->left = root;
    } 

    head = root;    
    
    BSTintoSorted_LL(root->left,head);
}

Node* mergeBst(Node * )

Node* FlattenBST(Node* root1,Node* root2){
    //bst to inorder
    vector<Node*> v1;
    inorder(root1,v1);
    vector<Node*> v2;
    inorder(root2,v2);
    int i = 0;
    Node* curr1 = new Node(v1[0]);

    while (i < v1.size())
    {   
        Node* next = new Node(v1[i]);

        curr1->right = next;
        curr1->left = NULL;
        curr1 = next;    
    }
    




    
}

int main(){
    system("cls");

    return 0;
}