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

Node* solve(Node* &a,Node* &b){

    if (a->next==NULL)
    {
        a->next=b;
        return a;
    }
    
    Node* curra= a;
    Node* forwarda= a->next;
    Node* currb= b;
    Node* forwardb= b->next;
    
    while (curra!=NULL && forwardb!=NULL)
    {
        if(curra->data <= currb->data && currb->data <= forwarda->data)
        {
            curra->next=currb;
            forwardb=currb->next;
            currb->next=forwarda;

            curra=currb;
            currb=forwardb;
        }
        else
        {   
            curra=forwarda;
            forwarda=forwarda->next;
            
            if (forwarda==NULL)
            {
                curra->next=currb;
                return a;
            }
            
        }
    }
    return a;
}


Node* merge(Node* &h1,Node* &h2){

    if (h1==NULL)
    {
        return h2;
    }
    if (h2==NULL)
    {
        return h1;
    }


    if (h1->data < h2->data)
    {
        return solve(h1,h2);        
    }
    else
    {
        return solve(h2,h1);
    }
    
}

int main(){
    system("cls");

    Node* Head = new Node(0);
    Node* secElement = new Node(1);
    Node* thirdElement = new Node(2);
    Node* fourthElement = new Node(3);
    Node* fifthElement = new Node(4);
    Node* sixthElement = new Node(6);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = NULL;

         
    Node* Head2 = new Node(1);
    Node* secElement2 = new Node(2);
    Node* thirdElement2 = new Node(2);
    Node* fourthElement2 = new Node(3);
    Node* fifthElement2 = new Node(5);
    Node* sixthElement2 = new Node(7);
    Head2->next = secElement2;
    secElement2->next = thirdElement2;
    thirdElement2->next = fourthElement2;
    fourthElement2->next = fifthElement2;
    fifthElement2->next = sixthElement2;
    sixthElement2->next = NULL;

    Node* ans=merge(Head,Head2);
    print(Head);
    cout<<endl;

    return 0;
}