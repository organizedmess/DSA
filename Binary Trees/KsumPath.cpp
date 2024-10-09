//Time Complexity : O(n*t*t)
//for every node at distance 't' from root, we will have to traverse through a vector af 't' size  
//hence making the complexity O(n*t*t);
#include<iostream>
#include<vector>
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

Node* buildTree(Node* &root)
{   
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

void solve(Node* root,int k,int &count ,vector<int> &path){

    if (root == NULL)
        return ;
    
    path.push_back(root->data);
    //first we are just pushing all the nodes of a certain path and 

    //then we use the permutations on the 'path' vector.  
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    //check for sum 'k'
    //or the permutations of the vector
    int size = path.size();
    int sum = 0;      
    for (int i = size-1; i >= 0; i--)
    {
        sum += path[i];//adding the nodes one by one in upward 
                      //direction from the current node towards root node 
        if (sum == k)
            count++; // we found another path which has its sum equal to 'k'
    }
    
    path.pop_back();//becoz now we have to return a path that is up until previous node
}

int NumPath(Node* root,int k){
    vector<int> path;
    int count = 0; 
    solve(root,k,count,path);
    return count;
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 9 -1 -1 -1
    Node* root = NULL;
    buildTree(root);
    int ans = NumPath(root,15);
    cout<<ans;
    return 0;
}