#include<iostream>
#include<map>
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

Node* mapCreation(Node* root,map<Node*,Node*> &ChildToParent,int target){
    queue<Node* > q;
    q.push(root);
    Node* res = NULL;
    ChildToParent[root] = NULL;

    while (!q.empty())
    {   
        Node* frontNode = q.front();
        q.pop();

        if (frontNode->data == target)
            res = frontNode;
        
        if (frontNode->left)
        {
            ChildToParent[frontNode->left] = frontNode; 
            q.push(frontNode->left); 
        }
        if (frontNode->right)
        {
            ChildToParent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return res;
}

int burningTree(Node* target,
                    map<Node*,Node*> &ChildToParent,map<Node*,bool> &visited)
{
        queue<Node*> burned;
        
        burned.push(target);
        visited[target] = true;
        int time = 0;

        while (!burned.empty())
        {
            int size = burned.size();
            
            bool burning_happened = false ; 
            
            //this loop represents the havoc caused in a single time unit i.e.
            //the burning of children and parent of a single node in one iteration

            for(int i = 0; i < size; i++)//even if the nodes are being pushed into the queue here,it would still only run for 
            {                           // limited iterations
                Node* frontNode = burned.front();
                burned.pop();
                if (frontNode->left != NULL && visited[frontNode->left] == false)
                {   
                    burning_happened = true; 
                    burned.push(frontNode->left);
                    visited[frontNode->left] = true;
                }
                if (frontNode->right != NULL && visited[frontNode->right] == false)
                {   
                    burning_happened = true; 
                    burned.push(frontNode->right);
                    visited[frontNode->right] = true;
                }

                Node* parent = ChildToParent[frontNode];
                if (parent != NULL && visited[parent] == false)
                {
                    burning_happened = true; 
                    burned.push(parent);
                    visited[parent] = true;
                }
            }
            if(burning_happened == true)
            {
                time++;
            }
        }
    return time;
}

int solve(Node* root, int target){
    map<Node*,Node*> ChildToParent;
    Node* res = mapCreation(root,ChildToParent,target);

    map<Node*,bool> visited; 

    int ans = burningTree(res,ChildToParent,visited); 
    return ans;
}

int main(){
    system("cls");
    Node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildTree(root);
    int target = 5;
    cout<< solve(root,target);
    return 0;
}