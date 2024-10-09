#include<iostream>
#include<vector>
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

void preorder(Node* root,vector<int> &v){
    if(root == NULL)
       return ;
    
    preorder(root->left,v);
    v.push_back(root->data);
    preorder(root->right,v);

}

void inorder(Node* root,vector<int> &v,int &index){
    if (root == NULL)
        return ;

    root->data=v[index++];
    
    inorder(root->left,v,index);
    inorder(root->right,v,index);

}

int main(){
    system("cls");
    Node* root = NULL;
    insertion(root);
    // 4 1 7 10 9 11 -1
    // 3 2 1 5 4 6 -1
    vector<int> v;
	preorder(root,v);
	int index = 0;
	inorder(root,v,index);
    cout<<"done";
    
    return 0;
}