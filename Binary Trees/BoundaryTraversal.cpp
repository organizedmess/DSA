#include<iostream>
#include<queue>
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

void print(vector<int> v){
        for(int i=0; i<v.size();i++)
            {cout<<v[i]<<" ";}
            cout<<endl;
}

Node* buildTree(Node* &root){
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;

    root = new Node(data);

    if (data == -1)
        return NULL;
    
    
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

void traverseLeft(Node* root,vector<int> &ans){
    
    if((root == NULL) || (root->left == NULL && root->right == NULL)){
        return ;
    }
    
    ans.push_back(root->data);

    if (root->left)
        traverseLeft(root->left,ans);
    else
        traverseLeft(root->right,ans);

    return ;
}

void traverseLeafNode(Node* root,vector<int> &ans){
    if (root == NULL)
        return ;
    
    if (root->left == NULL && root->right == NULL)
        {   
            ans.push_back(root->data);
            return ;
        }

    traverseLeafNode(root->left,ans);
    traverseLeafNode(root->right,ans);

    return ;    
}

void traverseRight(Node* root,vector<int> &ans){
    
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return ;
    
    if (root->right)
        traverseRight(root->right,ans);
    else
        traverseRight(root->left,ans);
    
    ans.push_back(root->data);
    return ;
}

vector<int> Boundary(Node* root){
    vector<int> ans;
    if(root == NULL)
        return ans;

    ans.push_back(root->data);

    //left part
    traverseLeft(root->left,ans);

    //LEAF NODES 
    traverseLeafNode(root,ans);
    
    //right part
    traverseRight(root->right,ans);

    return ans;
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    buildTree(root);
    vector<int> ans= Boundary(root); 
    print(ans);
    return 0;
}