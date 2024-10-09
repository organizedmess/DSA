#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data){
        this->data=data;
        this->left=this->right=NULL;
    }
};

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

int TotalCountNode(Node* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1 + TotalCountNode(root->left) + TotalCountNode(root->right);
    return ans;
}

bool isCbt(Node* root ,int TotalCount ,int index){
   
    if(root==NULL){
        return true;
    }
    if(index >= TotalCount){//this condition checks whether the node was submitted from the left or right side
        cout<<index<<"||"<<TotalCount<<"||"<<root->data<<endl;
        return false;//this means that the node is not 
    }                //null and its also out of total count
     

    bool leftCheck = isCbt(root->left,TotalCount,2*index);
    bool rightCheck = isCbt(root->right,TotalCount,2*index+1);

    return (leftCheck&&rightCheck);
}

bool isMaxHeap(Node* root){
    if(!root->left && !root->right)
    {
        return true;
    }

    if(root->left && !root->right)
    {
        if(root->left->data < root->data)
           return true; 
    }
    
    bool Checkleft = isMaxHeap(root->left);//O(n)
    bool Checkright = isMaxHeap(root->right);
    bool condition = (root->data > root->left->data && root->data > root->right->data);

    if(condition&&Checkleft&&Checkright)
        return true;
    else
        return false;
}

bool isHeap(Node* root){
    int TotalCount = TotalCountNode(root);//o(n)
    
    if(isCbt(root,TotalCount,1)==true && isMaxHeap(root)==true)
        return true;
    else
        return false;

}

int main(){
    system("cls");
    Node* root = NULL;
    BuildTree(root);
    LevelOrderTraversal(root);
    cout<<"*************************************************"<<endl;
    //11 7 4 -1 -1 5 -1 -1 5 3 -1 -1 2 -1 -1 
    //11 7 4 -1 -1 6 -1 -1 5 2 9 3 -1 -1 2 -1 -1 -1 -1 -1 -1 -1
    //11 7 4 -1 -1 6 -1 -1 5 2 9 -1 -1 -1 -1 -1 -1 -1
    vector<int> vec;
    
    cout<<isHeap(root);
    return 0;
}