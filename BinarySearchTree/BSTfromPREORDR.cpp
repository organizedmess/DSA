#include<bits/stdc++.h>
#include<vector>
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

Node* solve(vector<int> preorderVec,int minn,int maxx,int &i){
    if (i >= preorderVec.size())
        return NULL;

    if (preorderVec[i] < minn || preorderVec[i] > maxx)
        return NULL;// it is out of range so wont get inserted in this particular branch
    
    
    Node* newNode = new Node(preorderVec[i++]);
    newNode->left = solve(preorderVec,minn,newNode->data,i);
    newNode->right = solve(preorderVec,newNode->data,maxx,i);

    return newNode;
}

Node* PreOrder(vector<int> preorderVec){
    int minn = INT_MIN;
    int maxx = INT_MAX;
    int i = 0;
    Node* tree = solve(preorderVec,minn,maxx,i);
    return tree;
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

int main(){
    
    vector<int> preorderVec = {20,10,5,15,13,35,30,42};
    
    vector<int> notPreorder = {20,10,13,5,15,35,30,42};
    
    Node* tree = PreOrder(preorderVec);
    Node* tree2 = PreOrder(notPreorder);
    
    LevelOrderTraversal(tree);
    LevelOrderTraversal(tree2);
    return 0;
}