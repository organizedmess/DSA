#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

void RightViewRecursive(Node* root,int lvl,vector<int> &ans){
    if (root == NULL)
        return ;
    
    if (lvl == ans.size())
        ans.push_back(root->data);// ans+1
    //this condition indicates that we have come to this level for the first time.


    RightViewRecursive(root->right,lvl+1,ans);
    RightViewRecursive(root->left,lvl+1,ans);//lvl+1
}


int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    BuildTree(root);
    
    vector<int> ans;
    RightViewRecursive(root,0,ans);
    
    print(ans);
    return 0;
}