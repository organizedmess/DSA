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
    cout<<"Enter data :"<<endl;
    cin>>data;
    root = new Node(data);

    if (data==-1)
        return NULL; 
    
    root->left=BuildTree(root->left);
    root->right=BuildTree(root->right);
    
    return root;
}

int maxx(int a,int b){
    if (a<b)
        return b;
    else
        return a;
}

int height(Node* root){
    if(root==NULL)
        return 0;

    int left = height(root->left);
    int right= height(root->right);

    int ans=maxx(left,right);

    return ans+1;
}

pair<bool,int> isBalanced(Node *root){
    pair<bool,int> p;
    if (root == NULL){
        p = make_pair(0,0);
        return p;
    }
    
    pair<bool,int> leftCheck = isBalanced(root->left);
    pair<bool,int> rightCheck = isBalanced(root->right);
        
    bool check = abs(leftCheck.second - rightCheck.second) <= 1;//abs gives us the magnitude(mod) of a value

    p.second= maxx(leftCheck.second,rightCheck.second)+1 ;
    if(leftCheck.first == 1 && rightCheck.first == 1 && check == 1)
    {   
        p.first=1;
        return p;
    }
    else
    {
        p.first=0;
        return p;
    }
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    BuildTree(root);
    pair<bool,int> ans = isBalanced(root);
    cout<<ans.first;
    return 0;
}