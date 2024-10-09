#include<iostream>
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
    cin>>data;

    while (data != -1)
    {
        root = construct(root,data);
        cin>>data;   
    }
}

Node* minNode(Node* root)
{
    if (root->left == NULL)
        return root;
    
    Node* minn = minNode(root->left);

    return minn;    
}
Node* maxNode(Node* root)
{
    if (root->right == NULL)
        return root;
    
    Node* maxx = maxNode(root->right);

    return maxx;    
}

Node* deletion(Node* &root,int key){
    Node* temp = root;

    if (temp->data == key)
    {
        // 0 CHILD
        if (temp->right == NULL && temp->left == NULL)
        {   
            return NULL;
        }
        //1 CHILD
        else if (temp->right == NULL && temp->left != NULL)
        {//left child exists 
            Node* toDelete = temp->left;
            delete(temp);
            return toDelete;
        }
        else if (temp->left == NULL && temp->right != NULL)
        {//right child exists
            Node* toDelete = temp->right;
            delete(temp);
            return toDelete;
        }
        //2 CHILD
        else if (temp->right != NULL && temp->left != NULL)
        {//we cant delete the 'temp' here because then we will lose the link to its other branch
            Node* replacer = minNode(temp->right);
            temp->data = replacer->data;
            temp->right = deletion(temp->right,replacer->data);
            return temp;
        }

    }

    else if (temp->data > key)
        temp->left = deletion(temp->left,key);
    
    else if (temp->data < key)
        temp->right = deletion(temp->right,key);

    return temp;

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
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<" Enter data for tree :"<<endl;
    insertion(root);
    LevelOrderTraversal(root);
    cout<<endl;
    deletion(root,6);
    LevelOrderTraversal(root);


    return 0;
}
