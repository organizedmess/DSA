#include<iostream>
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
    cout<<"Enter The data:";
    cin>>data;

    while (data != -1)
    {
        root = construct(root,data);
        cin>>data;   
    }
    cout<<endl;
    return ;
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

    // METHOD 1
void BstToInorder(Node* root,vector<int> &vec){
    if (root == NULL)
        return ;
    
    BstToInorder(root->left,vec);
    vec.push_back(root->data);
    BstToInorder(root->right,vec);
}

Node* InorderToBST(vector<int> vec,int start,int end){
    if (start >= end)
        return NULL;
    
    int mid = start + (end-start)/2;   

    Node* root = new Node(vec[mid]);

    root->left = InorderToBST(vec,start,mid);
    root->right = InorderToBST(vec,mid+1,end);

    return root;
}

Node* method1(Node* root1,Node* root2){
    //  BST - Inorder

    vector<int> inorder1,inorder2;
    BstToInorder(root1,inorder1);
    BstToInorder(root2,inorder2);

    //merging the 2 inorders
    vector<int> final(inorder1.size() + inorder2.size());
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < inorder1.size() && j < inorder2.size())
    {
        if(inorder1[i] < inorder2[j])
           final[k++] = inorder1[i++]; 
        else
           final[k++] = inorder2[j++]; 
    }
    while(j < inorder2.size())
        final[k++] = inorder2[j++];  
    
    
    while(i < inorder1.size())
        final[k++] = inorder1[i++]; 

    //final vector is now ready 
    //now inorder to BST

    Node* merged_tree = InorderToBST(final,0,final.size());
    return merged_tree;
}


int main(){
    system("cls");
    Node* root1 = NULL; 
    Node* root2 = NULL;

    // 3 2 1 5 4 6 -1
    // 4 1 7  10 9 11 -1

    insertion(root1);
    insertion(root2);

    Node* ans = method1(root1,root2);

    // LevelOrderTraversal(ans);
    
    return 0;
}