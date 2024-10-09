#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data= d;
        this->next= NULL;
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

void Reverse(Node* &Head){
    Node* prev = NULL;
    Node* curr = Head;
    
    while(curr != NULL)
    {   
        Node* forward = curr->next;
        curr->next=prev;
        prev = curr;
        curr = forward;
    }
    Head = prev;
    
}

void recur1(Node* prev,Node* curr,Node* &Head){
    // base case
    if (curr == NULL)
    {   Head = prev;
        return ;
    }   

        // Node* curr=prev->next;
        Node *forward=curr->next;
        curr->next=prev;
        recur1(curr,forward,Head);
}

Node* recur2(Node* Traverse){
    if (Traverse==NULL || Traverse->next==NULL)
    {
        return Traverse;//This would return the last node of the list which is our new Head.
    }

    Node* FinalHead=recur2(Traverse->next);//This would save the New Head of the list.

    Traverse->next->next=Traverse;//These two lines are here simply to adjust the pointers.
    Traverse->next=NULL;//These two lines are here simply to adjust the pointers.


    return FinalHead;//BEHOLD THE NEW HEAD.
                     //Every time recursion is called FinalHead will remain same throughtout the list.

}    


int main(){
    system("cls");
    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thrdElement = new Node(30);
    Node* fourthElement = new Node(40);
    Head->next = secElement;
    secElement->next = thrdElement;
    thrdElement->next = fourthElement;
    fourthElement->next= NULL;

    Node* prev = NULL;
    // print(Head); 
    // recur1(prev,Head,Head);

    // cout<<recur2(Head)->data;

    return 0;
}

