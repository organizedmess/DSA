#include<iostream>
#include<queue>
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

void InorderTraversal(Node* &root,vector<int> &vec){
    if(root==NULL)
            return ;
        
    InorderTraversal(root->left,vec);//L
    vec.push_back(root->data);//N
    InorderTraversal(root->right,vec);//R
}

Node* InorderToBST(vector<int> &vec,int start,int end){ 
    if (start >= end)//binary search will break the array in equal parts hence least height
        return NULL;

    int mid = start + (end-start)/2;    

    Node* root = new Node(vec[mid]);
    root->left = InorderToBST(vec,start,mid);    
    root->right = InorderToBST(vec,mid+1,end);    
    
    return root;
}

Node* balanced(Node* root){
    vector<int> vec;
    InorderTraversal(root,vec);
    
    Node* balanced_tree = InorderToBST(vec,0,vec.size()-1);

    return balanced_tree; 
}

int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<"Enter data for tree :"<<endl;
    insertion(root);
    Node* ans = balanced(root);
    cout<<ans->right->data;
    return 0;
}