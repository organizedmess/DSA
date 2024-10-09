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

void print(Node* Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

Node* reverse(Node* &head2){
    Node* curr= head2;
    Node* prev= NULL;

    while(curr!=NULL)
    {
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    cout<<endl;
    head2=prev;
    return head2;
}


Node* Middle(Node* &Head){//we want element closer to the head in case of even linked list.
    Node* fast = Head;
    Node* slow= Head;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast =fast->next->next;
        slow =slow->next;
    }
    return slow;
}

bool checkPalindrome(Node* &Head){
    Node* temp=Head;
    Node* temp2=Middle(Head);
    
    Node* mid=reverse(temp2);
    while (temp!=NULL)
    {
        if (temp->data != mid->data)
        {
            return 0;
        }
        temp=temp->next;
        mid=mid->next;
    }
    return 1;
}


int main(){
    system("cls");
    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thirdElement = new Node(30);
    Node* fourthElement = new Node(30);
    Node* fifthElement = new Node(20);
    Node* sixthElement = new Node(10);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = NULL;
    
    cout<<checkPalindrome(Head);
    
    return 0;
}