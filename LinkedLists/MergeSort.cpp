#include<iostream>
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

void print(Node* Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

Node* mid(Node* Head){
    Node* fast =Head;
    Node* slow =Head;
    
    while (fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;   
}

Node* merge(Node* a,Node* b){
    Node* atemp=a;
    Node* btemp=b;
    Node* finalans=new Node(-1);//this node is obviously gonna be the smallest
    Node* temp=finalans;

    while(atemp!=NULL && btemp!=NULL)
    {
        if (atemp->data < btemp->data)  
        {//temp->atemp->btemp
            temp->next=atemp;
            temp=atemp;
            atemp=atemp->next;
        }
        else
        {
            temp->next=btemp;
            temp=btemp;
            btemp=btemp->next;
        }
    }
    
        while (btemp!=NULL)
        {
            temp->next=btemp;
            temp=btemp;
            btemp=btemp->next;
        }
    
        while (atemp!=NULL)
        {
            temp->next=atemp;
            temp=atemp;
            atemp=atemp->next;
        }
    
    finalans=finalans->next;//removing dummy node

    return finalans;     
}


Node* divide(Node* &head){
    
    if(head==NULL||head->next==NULL)
    {
        return head;//Base Case
    }

    Node* middlepoint=mid(head);

    Node* left=head;
    Node* right=middlepoint->next;
    middlepoint->next=NULL;

    //divide 
    left=divide(left);
    right=divide(right);
    //merge them
    Node* res=merge(left,right);
    
    return res;
}

int main(){
    system("cls");
    Node* Head = new Node(1);
    Node* secElement = new Node(0);
    Node* thirdElement = new Node(5);
    Node* fourthElement = new Node(3);
    Node* fifthElement = new Node(7);
    Node* sixthElement = new Node(2);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = NULL;

    Node* result=divide(Head);
    print(result);
    
    return 0;
}