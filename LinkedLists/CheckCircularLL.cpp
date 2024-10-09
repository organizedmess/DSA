#include<iostream>
#include<vector>
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


bool isCircular(Node* head){
     Node* temp=head->next;

    if(temp == NULL||temp->next == NULL){
        return 1;
    }
    
    while (temp!=head && temp!=NULL )
    {
        temp=temp->next;
        // cout<<"hi";
    }
    
    if(temp == head)
    {
        return 1;
    }
       
    return 0;
}

    

int main(){
    system("cls");
    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thirdElement = new Node(30);
    Node* fourthElement = new Node(40);
    Node* fifthElement = new Node(50);
    Node* sixthElement = new Node(60);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = Head;

    cout<<isCircular(Head);

    return 0;
}