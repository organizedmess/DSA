#include<iostream>
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

void Morris_Inorder(Node* root){
    Node* curr = root;
    Node* predec;

    if (root == NULL)
        return ; 
    
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout<<curr->data<<" ";//print toh sirf curr kra skta h
            curr = curr->right;
        }

        else//current->left exists
        {
            predec = curr->left;
            while (predec->right != NULL && predec->right != curr)
            {
                predec = predec->right;
            }

            //we have made a connection with the root node and now it is safe to move curr from its place
            // and to the available nodes. 
            if (predec->right == NULL)
            {
                predec->right = curr;//curr is now safe to move
                curr = curr->left;
            }

            //else part represents that we have already visited and now its time to print the node and 
            //undo the changes that we made
            else
            {   
                predec->right = NULL;
                cout<<curr->data<<" ";//we print the nodes whilst we are comning back to the node as this is LNR
                                      //and rightmost should be printed last  
                
                curr = curr->right;//left subtree is printed now so please move to the right tree
            }

        }

    }

}

int main(){
    system("cls");

    return 0;
}