#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data= d;
        Node* left = NULL;
        Node* right = NULL;
    }
};

Node* buildTree(Node* &root)
{   
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;
    root = new Node(data);
    
    if (data == -1)
        return NULL;
    
    root->left=buildTree(root->left);
    root->right=buildTree(root->right);

    return root;
}


pair<int,int> sumLongestPath(Node* root){
    
    pair<int,int> p;
   
    if (root == NULL)
        return make_pair(0,0);
    

    if (root->left == NULL && root->right == NULL)
    {.
        p.first = 0;
        p.second = root->data;
    }

    pair<int,int> leftCheck = sumLongestPath(root->left);
    pair<int,int> rightCheck = sumLongestPath(root->right);

    if (leftCheck.first > rightCheck.first)
    {
        p.first = leftCheck.first + 1;//height increased 
        p.second = leftCheck.second + root->data;//data added
    }
    else
    {
        p.first = rightCheck.first + 1;//height increased 
        p.second = rightCheck.second + root->data;//data added
    }

    return p;
}

int basefunction(Node* root){
    if (root == NULL)
        return 0;
    
    pair<int,int> p;
    p = sumLongestPath(root);
    
    int result = p.second;
   
    return result;
}


int main(){
    system("cls");
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    buildTree(root);
    
    int answer = basefunction(root);
    cout<<answer;
    return 0;
}