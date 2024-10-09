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

void diagonal(Node* root,int hd,map<int,vector<int>> &ans){

    if (root == NULL)
        return ;

    ans[hd].push_back(root->data);

    if (root->left)
        diagonal(root->left,hd+1,ans);
    
    if (root->right)
        diagonal(root->right,hd,ans);
    
}

vector<int> DiagonalView(Node* root){
    map<int,vector<int>> ans;
    vector<int> final;
    diagonal(root,0,ans);

    for (auto i : ans)
    {   
        for (auto j : i.second)
        {
            final.push_back(j);
        }
    }
    
    return final;
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    BuildTree(root); 
    
    vector<int> res;
    res = DiagonalView(root);

    print(res);
    return 0;
}