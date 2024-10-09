#include<iostream>
#include<vector>
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

Node* buildTree(Node* &root){   
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

int maxx(int a,int b){
    return (a>b?a:b);
}

pair<int,int> solve(Node* root){
    pair<int,int> p;
    // first : inclusion
    // second : exclusion
    if(root == NULL)
    {
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftCheck = solve(root->left);
    pair<int,int> rightCheck = solve(root->right);

    int currInc = root->data + leftCheck.second + rightCheck.second;//we included the current node 
    int currExc = maxx(leftCheck.first,leftCheck.second) + maxx(rightCheck.first,rightCheck.second);//we excluded the current node
    p = make_pair(currInc,currExc); 
    
    return p;
}

int maxSum(Node* root){
    pair<int,int> ans;
    ans = solve(root);
    
    int result = maxx(ans.first,ans.second);
    return result;
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 20 -1 -1 -1 -1 -1 
    // 1 3 5 7 11 N 17 N N N N N N 20 
    Node* root = NULL;
    buildTree(root);

    int result = maxSum(root);
    cout<< result;
    return 0;
}