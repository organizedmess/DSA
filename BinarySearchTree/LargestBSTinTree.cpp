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

class info{
    public:
    int maxx;
    int minn; 
    bool isBst;
    int size;
};

Node* BuildTree(Node* &root){
    int data;
    cout<<"Enter data :"<<endl;
    cin>>data;
    root = new Node(data);

    if (data==-1)
        return NULL; 
    
    root->left=BuildTree(root->left);
    root->right=BuildTree(root->right);
    
    return root;
}

int minNode(int a,int b)
    {return ( a > b ? b : a);}
int maxNode(int a,int b)
    {return ( a < b ? b : a);}

info solve(Node* root,int &ans){
    if (root == NULL)
        return {INT_MIN,INT_MAX,true,0};//we need to reverse maxx and minn because if we didn't then
                                       // line 59 wont work for leaf node
    
    info leftCheck = solve(root->left,ans);
    info rightCheck = solve(root->right,ans);

    info currNode;
    currNode.size = leftCheck.size + rightCheck.size + 1;//height of the tree 
    currNode.maxx = maxNode(root->data,rightCheck.maxx);
    currNode.minn = minNode(root->data,leftCheck.minn);

    if (leftCheck.isBst && rightCheck.isBst && (root->data > leftCheck.maxx && root->data < rightCheck.minn))
    {//Primary condition 
        currNode.isBst = true;
    }
    else
    { 
        currNode.isBst = false;
    }

    if (currNode.isBst)
    {
        ans = maxNode(ans,currNode.size);
    }

    return currNode;    
}

int largestBST(Node* root){
    int maxSize = 0;
    info temp = solve(root,maxSize);
    return maxSize;
}

int main(){
    system("cls");
    Node* root = NULL;
    
    cout<<"Enter data for tree :"<<endl;
    BuildTree(root);

    cout<<largestBST(root);
    return 0;
}