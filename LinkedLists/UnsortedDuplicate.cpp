#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void deleteNode(Node* &head,Node* &duplicate)
{
    Node* temp = head;
    while (temp->next!=duplicate)
    {
        temp =temp->next;
    }
    temp->next = duplicate->next;
    duplicate->next =NULL;
    
    delete duplicate;
}

Node *removeDuplicates(Node* &head)
{
    if (head==NULL)
    {
        return head;
    }
    

    map<int,bool> dupli;
    Node* temp=head;
    while (temp!=NULL)
    {
        if (dupli[temp->data]==true)
        {    if(temp->next!=NULL){
                Node* forward=temp->next;
                deleteNode(head,temp);
                temp=forward;
                }
             else{
                  deleteNode(head,temp);
                  temp=NULL;
             }
        }
        else
        {
            dupli[temp->data]=true;
            temp=temp->next;
        }
        
    }
    return head;
}

void duplicate(Node* &Head){
        // cout<<"hi1";
    Node* temp = Head;
    if (temp == NULL)
    {
        // cout<<"hi";
        return;
    }

    Node* curr=temp->next;
    while (curr!=NULL)
    {
        if (temp->data==curr->data)
        {   
            Node*forward =curr->next;
            deleteNode(Head,curr);
            curr=forward;
        }
        
        else
        {
            curr=curr->next;    
        }

    }
    duplicate(temp->next);
    
}

void print(Node* Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

int main(){
    system("cls");
    Node* Head = new Node(4);
    Node* secElement = new Node(2);
    Node* thirdElement = new Node(5);
    Node* fourthElement = new Node(4);
    Node* fifthElement = new Node(2);
    Node* sixthElement = new Node(2);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = NULL;

    print(Head);
    // print(removeDuplicates(Head));
    duplicate(Head);
    print(Head);

    return 0;
}