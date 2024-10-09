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

pair<bool,int> SumTree(Node* root){
    
    if (root == NULL)
    {   
        pair<bool,int> p;
        p.first= true;
        p.second = 0;
        return p;
    }
    if (root->left == NULL && root->right == NULL)
    {   
        pair<bool,int> p;
        p.first= true;
        p.second = root->data;
        return p;
    }


    pair<bool,int> checkLeft = SumTree(root->left); 
    pair<bool,int> checkRight = SumTree(root->right); 
    bool condition = (checkLeft.second + checkRight.second == root->data);
    
    pair<bool,int> ans;
    
    if (checkLeft.first && checkRight.first && condition)
    { 
        ans.first = 1;
        //in a Sum Tree root.data will be equal to sum of its child subtrees
        //hence p.second == 2* root.data
        ans.second = root->data + checkLeft.second + checkRight.second ;
        // cout<<ans.second;
        return ans;
    }
    else
    {   
        ans.first = 0;
        return ans;
    }
    
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 35 18 7 -1 -1 11 -1 -1 17 17 -1 -1 -1
    Node* root = NULL;
    BuildTree(root);
    pair<bool,int> ans=SumTree(root); 
    cout<<ans.first<<endl;
    cout<<ans.second<<endl;
    return 0;
}