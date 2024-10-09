#include<iostream>
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

void InorderTraversal(Node* &root,vector<Node*> &vec){
    if(root==NULL)
            return ;
        
    InorderTraversal(root->left,vec);//L
    vec.push_back(root);//N
    InorderTraversal(root->right,vec);//R
}

Node* flatten(Node* &root){
    vector<Node*> vec; 
    InorderTraversal(root,vec);
    Node* newRoot = new Node(vec[0]->data);
    Node* curr = newRoot;
    
    for(int i=1; i<=(vec.size()-1) ; i++)
    {
        Node* next = vec[i];
        
        curr->left=NULL;
        curr->right=next;   
        curr = next; 
    }
    return newRoot;
}

int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<"Enter data for tree :"<<endl;
    insertion(root);

    Node* ans = flatten(root);
    cout<<ans->right->data;
    return 0;
}