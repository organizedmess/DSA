#include<iostream>
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

Node* solve(Node* root ,int node,int k,int &count){
    if (root == NULL)
        return NULL;
    
    if(root->data == node)
        return root;
    
    Node* leftCheck = solve(root->left,node,k,count);
    Node* rightCheck = solve(root->right,node,k,count);

    if(leftCheck != NULL)
    {   
            count++;
            
            if (count == k)
            {
                return root;
            }
    
            return leftCheck;
    }
    else if(rightCheck != NULL)
    {
        count++;
            
            if (count == k)
            {
                return root;
            }
    
            return rightCheck;
    }

    else
    {
        return NULL;
    }

}

int K_Ancestor(Node* root,int node,int k){
    int count = 0;
    Node* ans = solve(root,4,2,count);
    
    if (ans == NULL || ans->data == node)//ans->data for the case when node is actually the root node coz then it wont have any ancestors 
        return -1;
    else
        return ans->data;
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 20 -1 -1 -1 -1 -1
    // 1 3 7 N N 11 N N 5 17 20 N N N N N
    //1 2 -1 -1 3 4 -1 5 7 -1 -1 -1 6 -1 -1 
    Node* root = NULL;
    buildTree(root);
    int count = 0;
    int result = K_Ancestor(root,4,2);
    cout<< result ;
    
    return 0;
}
