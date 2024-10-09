#include<iostream>
#include<vector>
#include<queue>
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

int FindIndex(int element,vector<int> inOrder){
    for (int i = 0; i < inOrder.size(); i++)
    {
        if (inOrder[i] == element)
        {
            return i;//found the index where the root node is at.
        }
    }
    return -1;
}

Node* solve(vector<int> inOrder,vector<int> preOrder,int &preIndex,int inOrderStart, int inOrderEnd){
    
    if (inOrderStart > inOrderEnd || preIndex >= preOrder.size())
        return NULL;

    int element = preOrder[preIndex++];
    Node* temp = new Node(element);//creating a node with the first data in preOrder i.e root.

    int rootIndex = FindIndex(element,inOrder);//finding the index of root node in inOrder 

    temp->left=solve(inOrder,preOrder,preIndex,inOrderStart,rootIndex-1);    
    temp->right=solve(inOrder,preOrder,preIndex,rootIndex+1,inOrderEnd);    
    
    return temp;
}

int main(){
    system("cls");
    
    vector<int> inOrder = {7,3,11,1,17,3,18};
    vector<int> preOrder = {1,3,7,11,3,17,18};
    int preIndex = 0;
    Node* ans = solve(inOrder,preOrder,preIndex,0,inOrder.size());
    LevelOrderTraversal(ans);

    return 0;
}