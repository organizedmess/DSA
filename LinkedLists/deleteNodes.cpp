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
    ~Node(){
        cout<<"Deleted "<<this->data<<endl;
        
    }
};

void deleteNode(int position,Node* &Head){
    Node* prev = Head;
    Node* current = Head;
    int i=1;
    
    if (position==1){//SINCE IT CAN'T HAVE A PREV POINTER.
    Node* temp = Head;
    Head = Head->next; 
    delete temp; 
    }
    else{
    while(i<position-1)
    {   
        prev = prev->next;
        i++;
    }

    current = prev->next;
    prev->next = current->next;

    delete current; 
    }
}

void print(Node* &Head){
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
    Node* thrdElement = new Node(30);

    Head->next = secElement;
    secElement->next = thrdElement;
    thrdElement->next = NULL;
    print(Head);   
    deleteNode(1,Head);
    print(Head);   

    return 0;
}