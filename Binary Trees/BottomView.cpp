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

vector<int> bottom(Node* root){
    vector<int> ans;
    map<int,int> mp;
    queue<pair<Node*,int>> q;

    if (root == NULL)
        return ans;
    
    
    q.push(make_pair(root,0));

    while (!q.empty())
    {
        pair<Node*,int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        mp[hd] = frontNode->data;
        //Node will keep overwriting the previous data in that key
        //the bottom-most node->data will be the last to overwrite 
        
        if (frontNode->left)
            q.push(make_pair(frontNode->left,hd-1));

        if (frontNode->right)
            q.push(make_pair(frontNode->right,hd+1));
    }

    for (auto i : mp)
    {
        ans.push_back(i.second);
    }

    return ans;
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 20 8 5 -1 -1 3 10 -1 -1 14 -1 -1 22 -1 25 -1 -1 
    Node* root = NULL;
    BuildTree(root);
    
    vector<int> ans = bottom(root); 
    print(ans);
    
    return 0;
} 