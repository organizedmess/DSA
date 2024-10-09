 #include<iostream>
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


int InorderSuccess(Node* root,int key){
    Node* temp = root;
    Node* possible_successor = NULL;

    while (temp!=NULL)
    {
        if (key >= temp->data)
        {
            temp = temp->right;//Not gonna do anything if its smaller than the key
        }
        else
        {   //its possible that current temp is the successor so 
            //we will save it and then look for a data smaller 
            //than temp's but bigger than key's
            possible_successor = temp;
            temp = temp->left;
        }
    }
    return possible_successor->data;
}

int Inorder_Predec(Node* root,int key){
    Node* temp = root;
    Node* possible_predec = NULL;
    
    while (temp!=NULL)
    {
        if (key <= temp->data)
        {
            temp = temp->left;//Predecessor will always be smaller than key so we wont find anything here
        }
        else
        {
            possible_predec = temp;
            temp = temp->right;//looking for a data that is bigger than temp but smaller than key .
        }
    }
    return possible_predec->data;
}


int main(){
    system("cls");
    Node* root = NULL;
    // 3 2 1 5 4 6 -1
    cout<<"Enter data for tree :"<<endl;
    insertion(root);
    cout<<Inorder_Predec(root,4);
    cout<<endl;
    cout<<InorderSuccess(root,4);
    return 0;
}