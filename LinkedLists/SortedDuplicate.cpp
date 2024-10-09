#include<bits/stdc++.h>
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

void removeDuplicate(Node* &Head){
    Node* curr= Head;
    Node* prev= NULL;
    
    
    while (curr!=NULL){
        if(prev!=NULL && curr->data==prev->data)
        {   
            deleteNode(Head,prev);
        }
        
        prev=curr;
        curr=curr->next;
}
}

//2nd Approach
Node * uniqueSortedList(Node * head) {
    Node* curr= head;
    
    if(head==NULL){
        return head;    
    }
    
    while (curr!=NULL){
       if(curr->next!=NULL && curr->data==curr->next->data)
        {   Node* next_next=curr->next->next;
            Node* delNode=curr->next;  
            delete(delNode);
            curr->next=next_next;
        }else{
        curr=curr->next;
    }
    }
    return head;
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

    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thirdElement = new Node(20);
    Node* fourthElement = new Node(30);
    Node* fifthElement = new Node(40);
    Node* sixthElement = new Node(40);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = NULL;

    print(Head);
    removeDuplicate(Head);
    print(Head);

    return 0;
}