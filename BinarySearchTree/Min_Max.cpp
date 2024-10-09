#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

Node* construct(Node* root, int d){
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > (root->data))
    {
        root->right = construct(root->right,d); 
    }
    if (d < (root->data))
    {
        root->left = construct(root->left,d);
    }

    return root;
}

void insertion(Node* &root){
    int data;
    cin>>data;

    while (data != -1)
    {
        root = construct(root,data);
        cin>>data;   
    }
}

int minNode(Node* root)
{
    if (root->left == NULL)
        return root->data;
    
    int minn = minNode(root->left);

    return minn;    
}

int maxNode(Node* root)
{
    if (root->right == NULL)
        return root->data;
    
    int maxx = maxNode(root->right);

    return maxx;    
}

int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<" Enter data for tree :"<<endl;
    insertion(root);

    cout<<minNode(root);
    cout<<endl;
    cout<<maxNode(root);

    return 0;
}
