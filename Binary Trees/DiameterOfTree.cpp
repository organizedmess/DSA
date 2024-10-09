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

// Method 1: Terrible Time complexity(o(n^2)) because of calling the leafHeight function in every call
int leafHeight(Node* root){
    if(root==NULL)
        return 0;

    int left = leafHeight(root->left);
    int right= leafHeight(root->right);

    int ans=maxx(left,right);

    return ans+1;
}

int FindDiameter1(Node* root){
    Node* temp = root;

    if (root == NULL)
        return 0;

    int op1 = FindDiameter1(root->left);//diamter is passed only to compare and is never altered. Either it is accepted becoz its higher or straight up discared
    int op2 = FindDiameter1(root->right);//this helps us going lower into the tree.

    int op3 = leafHeight(root->left) + leafHeight(root->right) + 1;

    return (maxx(op1,op2),op3);
}

// Method 2: Better Time complexity o(n) as instead of calling LeafHeight, we simply return the height as well as diameter in first traversal only 
pair <int,int> FindDiameter2(Node* root){   
    
    if(root == NULL)
        {  
            pair <int,int> ptt = make_pair(0,0);//because this would be a leaf node, Its height and diameter will be both 0.
            return ptt;
        }

    pair <int,int>leftTree = FindDiameter2(root->left);
    pair <int,int>rightTree = FindDiameter2(root->right);

    int op1=leftTree.first;
    int op2=rightTree.first;
    int op3=leftTree.second + rightTree.second + 1;//this is the case where longest path goes through the root nodes

    pair<int,int> p;
    p.first = maxx(op1,maxx(op2,op3));
    p.second = maxx(leftTree.second,rightTree.second) + 1;//we need it because it might add up to become larger than the diameter of that time and might replace 

    return p;
}


int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    BuildTree(root);
    // cout<<FindDiameter1(root);
    pair<int,int> ans=FindDiameter2(root); 
    cout<<ans.first<<endl;
    cout<<ans.second<<endl;
    return 0;
}