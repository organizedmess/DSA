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

int findIndex(int element,int inorder[],int n){

    for (int i = 0; i < n; i++)
    {
        if (element == inorder[i])
        {
            return i;
        }
    }
    return -1;
}

Node* solve(int inorder[],int postorder[],int &postIndex,int inorderStart,int inorderEnd,int n)
{    
    if ( postIndex < 0 || inorderStart > inorderEnd)
        return NULL;
    
    int element = postorder[postIndex--];
    Node* root = new Node(element);
    int rootIndex = findIndex(element,inorder,n);

    root->right = solve(inorder,postorder,postIndex,rootIndex+1,inorderEnd,n);
    root->left = solve(inorder,postorder,postIndex,inorderStart,rootIndex-1,n);

    return root;
}

Node* build(int in[], int post[], int n) {
    int postIndex = n-1 ;
    Node* ans = solve(in,post,postIndex,0,n-1,n);
    return ans;
}

int main(){
    system("cls");
    
    int inOrder[] = {4,8,2,5,1,6,3,7};
    int postOrder[] = {8,4,5,2,6,7,3,1};
    int n = 8;
    int postIndex = n;
    Node* ans = build(inOrder,postOrder,n);
    LevelOrderTraversal(ans);

    return 0;
}
