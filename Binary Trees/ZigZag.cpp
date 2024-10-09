#include<iostream>
#include<queue>
#include<vector>
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

void print(vector<int> v){
        for(int i=0; i<v.size();i++)
            {cout<<v[i]<<" ";}
            cout<<endl;
}

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

vector<int> ZigZagTraversal(Node* root){
    vector<int> result;
    
    if (root == NULL)//checking if binary tree exists or not
        return result;
    
    
    queue<Node*> q;
    q.push(root);//since we are simply pushing the nodes into a vector and not printing them, we don't need NULL. 
    
    bool direction = true;//true: left to right , false: right to left
    
    while (!q.empty())
    {   
        int size = q.size();//will be equal to no. of nodes in that particular level
        vector<int> ans(size);//is new for everty iteration

        //this loop is where we fill 'ans' with one level in either direction
        for (int i = 0; i < size; i++)
        {    //in this loop we are traversing node in a level 
            Node* temp = q.front();//these nodes were pushed in the last iteration. 
            q.pop();//nodes of this iteration will be pushed in the next iteration.
            
            // now we have a node stored in 'temp', but we have to figure out how 
            // exactly will we put it in the array.

            int index = direction ? i : size - i - 1;
            ans[index] = temp->data;//temp being pushed according to index which depends on the direction.

            if (temp->left)//meaning : temp->left != NULL
                q.push(temp->left);
            //children are being pushed into the queue
            if (temp->right)
                q.push(temp->right);
        }
        //you will exit the loop only when i reaches size ,size here depends on the previous level's size. 
        
        
        
        direction = !direction;// direction change
        
        for (auto i : ans)//filling the result vector
        {                // after every iteration
            result.push_back(i);
        }
    }
        return result;                            
}   
        
       
int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 35 18 7 -1 -1 11 -1 -1 17 17 -1 -1 -1
    Node* root = NULL;
    BuildTree(root);
    vector<int> ans=ZigZagTraversal(root); 
    print(ans);
    
    return 0;
}
