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

void print(Node* &Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

Node* reverse(Node* Head){
    Node* temp=Head;
    if(temp==NULL||temp->next==NULL){
        return temp;
    }

    Node* finalHead=reverse(temp->next);
    temp->next->next=temp;
    temp->next=NULL;

    return finalHead;
}

Node* sum(Node* h1,Node* h2){
    Node* temp1=reverse(h1);
    Node* temp2=reverse(h2);
    int carry=0;
    int sum;
    Node* ans=new Node(-1);
    while(temp1!=NULL || temp2!=NULL || carry!=0)
    {
        int val1=0;
        if (temp1!=NULL)
        {
            val1=temp1->data;
        }


        int val2=0;
        if (temp2!=NULL)
        {
            val2=temp2->data;
        }

        sum = val1 + val2 + carry;
        carry = sum / 10;
        int value = (sum % 10);

        Node* newDig = new Node(value);
        newDig->next=ans->next;

        ans->next=newDig;
        
        if (temp1!=NULL)
        {
            temp1=temp1->next;
        }

        if (temp2!=NULL)
        {
            temp2=temp2->next;
        }
    }

    ans=ans->next;
    return ans;
}


int main(){
    system("cls");
    Node* Head1 = new Node(3);
    Node* secElement1 = new Node(1);
    Node* thrdElement1 = new Node(0);
    Node* fourthElement1 = new Node(0);
    Head1->next = secElement1;
    secElement1->next = thrdElement1;
    thrdElement1->next = fourthElement1;
    fourthElement1->next= NULL;

    Node* Head = new Node(1);
    Node* secElement = new Node(4);
    Node* thrdElement = new Node(0);
    Head->next = secElement;
    secElement->next = thrdElement;
    thrdElement->next = NULL;
    // fourthElement->next= NULL;
    
    Node* result = sum(Head1,Head);
    print(result);

    return 0;
}