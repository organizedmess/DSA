#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

Node* buildTree(Node* &root){
    int data;
    cout<<"Enter the data:"<<endl;
    cin>>data;

    root = new Node(data);

    if (data == -1)
        return NULL;
    
    
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

vector<int> verticalOrder(Node* root){
    vector<int> finalans;
    map<int,map<int,vector<int> > > nodes;
    //first int from left represents horizontal distance 
    //second int represents level of the node 
    //vector int stores the data of the nodes on that particulat level
    
    queue<pair<Node*,pair<int,int> > > q;
    // first pair contains the node in consideration 
    // the second pair's first int : horizontal distance 
    // the second pair's second int : vertical distance  

    if(root == NULL)
    {
        return finalans;//if binary tree does not exists.       
    }

    // lets push root node in the queue
    q.push(make_pair(root, make_pair(0,0)));

    while (!q.empty())
    {
        pair<Node*,pair<int,int>> temp = q.front();
        q.pop();
            Node* frontNode = temp.first; 
            int hd = temp.second.first;//horizontal distance    
            int lvl = temp.second.second;

        // now we store all this info about this particular node in the map

        nodes[hd][lvl].push_back(frontNode->data); 
        // we are pushing into the vector  

        if (frontNode->left)
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            
        if (frontNode->right)
            q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));        
    }

    //the map was filled in the while loop, now we push the nodes in the final vector 
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
            {
                finalans.push_back(k);
            }
            
        }
                
    }

    return finalans;    
}

int main(){
    system("cls");
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node* root = NULL;
    buildTree(root);
    vector<int> vec = verticalOrder(root);
    print(vec);
    return 0;
}
