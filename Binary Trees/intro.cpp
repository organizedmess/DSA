#include<iostream>
#include<queue>
#include<stack>
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

Node *BuildTree(Node* &root){
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;
    root = new Node(data);

    if (data==-1)
    {
        return NULL;
    }
    
    cout<<"Enter The data for the left Node of "<<data<<":"<<endl;
    root->left=BuildTree(root->left);
    cout<<"Enter The data for the right Node of "<<data<<":"<<endl;
    root->right=BuildTree(root->right);

    return root;
}

void CreateUsingLvlOrder(Node* &root){
    
    queue<Node*> q;
    cout<<"Enter data for root:"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        
        cout<<"Enter the right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}


//Tnis function is only used to print tree in a levelled fashion, 
//You are still gonna need the upper function to build a tree

void LevelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp==NULL)
        {//meaning there exists a seperator indicating that previous level has been completed
            cout<<endl;
                if (!q.empty())
                {//check if queue is empty or not coz if its not then we are gonna need the NULL pointer that we just popped out for the children of the previous level to keep them seperated. 
                    q.push(NULL);
                }
        }
        else
        {  
            cout<<temp->data<<" ";
            if (temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if (temp->right!=NULL)
            {
                q.push(temp->right);
            }
        }
    }

}

void ReverseLevelOrder(Node* root){
    stack<Node*> s;
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        s.push(temp);
    
        if (temp->right!=NULL)
        {
            q.push(temp->right);
        }
        if (temp->left!=NULL)
        {
            q.push(temp->left);
        }
    }

    while (!s.empty())
    {
        root = s.top();
        cout<<root->data<<" ";
        s.pop();
    }
}
            

void InorderTraversal(Node* root){
    if(root==NULL)
            return ;
        
    InorderTraversal(root->left);//L
    cout<<root->data<<" ";//N
    InorderTraversal(root->right);//R
}

void PreOrderTraversal(Node* root){
    if (root == NULL)
    {
        return ;
    }
    
    cout<<root->data<<" ";//N
    PreOrderTraversal(root->left);//L
    PreOrderTraversal(root->right);//R
}

void PostOrderTraversal(Node* root){
    if (root == NULL)
    {
        return ;
    }
    
    PostOrderTraversal(root->left);//L
    PostOrderTraversal(root->right);//R
    cout<<root->data<<" ";//N

}
    

int main(){
    system("cls");
    Node* root = NULL;
    // BuildTree(root);
    CreateUsingLvlOrder(root);
    LevelOrderTraversal(root);
    // ReverseLevelOrder(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // InorderTraversal(root);
    // cout<<endl;
    // PreOrderTraversal(root);
    // cout<<endl;
    // PostOrderTraversal(root);
    return 0;
}