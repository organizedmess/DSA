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

//iterative 
vector<int> leftView(Node* root){
    vector<int> vec;
    
    if(root == NULL) 
        return vec;
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            Node* frontNode= q.front();
            q.pop();

            if(i == 1)
                vec.push_back(frontNode->data);

            if (frontNode->left)
               q.push(frontNode->left);

            if (frontNode->right)
               q.push(frontNode->right);
        }
    }
        
    return vec;
}

//recursive 
void leftViewRecursive(Node* root,int lvl,vector<int> &ans){
    if (root == NULL)
        return ;
    
    if (lvl == ans.size())
        ans.push_back(root->data);// ans+1
    //this condition indicates that we have come to this level for the first time.


    leftViewRecursive(root->left,lvl+1,ans);//lvl+1
    leftViewRecursive(root->right,lvl+1,ans);
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    BuildTree(root);
    
    vector<int> ans;
    leftViewRecursive(root,0,ans);
    
    //ans = leftView(root);
    
    print(ans);
    return 0;
}