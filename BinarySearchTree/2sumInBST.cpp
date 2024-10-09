#include<iostream>
#include<vector>
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

vector<int> inorder(Node* root,vector<int> &v){
    
    Node* curr = root;
    Node* predec;

    while (curr!=NULL)
    {
        if (!curr->left)
        {
            v.push_back(curr->data);
            curr = curr->right;
        }

        else
        {   
            predec = curr->left;
            while (predec->right != NULL && predec->right != curr)
            {
                predec = predec->right;
            }
            if (predec->right == NULL)
            {
                predec->right = curr;
                curr = curr->left;
            }
            else
            {
                predec->right = NULL;
                v.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return v;
}

bool twoSumBST(Node* root,int TargetSum){
    
    vector<int> inorderVector;
    inorder(root,inorderVector);
    
    int small = 0;
    int big = inorderVector.size()-1;

    while (small <= big)
    {
        int s1 = inorderVector[small];
        int s2 = inorderVector[big];

        if (s1+s2 == TargetSum)
            return true;
        
        if(s1+s2 > TargetSum)
        {
            big--;
        }
        else
        {
            small++;
        }
    }
    return 0;
}

int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    // 4 1 7  10 9 11 -1
    cout<<"Enter data for tree :"<<endl;
    insertion(root);
    
    cout<<twoSumBST(root,8);
    return 0;
}
