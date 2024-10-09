#include<iostream>
#include<queue>
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

bool searchTree_recursive(Node* root,int key){ 
   
    if (root == NULL)
    {
        return false;//we traversed the entire tree but couldn't find the key
    }

    if (root->data == key)
    {    
        return true;
    }

    if (key < root->data)
    {
        searchTree_recursive(root->left,key);
    }
    else
    {
        searchTree_recursive(root->right,key);
    }

}

bool searchTree_iterative(Node* root,int key){

    Node* temp = root;
    while (temp != NULL)
    {
        if (key < temp->data)
        {
            temp = temp->left;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else if (temp->data == key)
        {
            return true;
        }
    }
    return false;
}

int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<" Enter data for tree :"<<endl;
    insertion(root);
    int key = 35;
    
    cout<<searchTree_recursive(root,key);
    cout<<endl;
    cout<<searchTree_iterative(root,key);
 
    return 0;
}