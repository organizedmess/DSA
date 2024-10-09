#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

print(Node* &Head){
    Node* temp = Head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
    

InsertAtTail(Node* &Tail,int data){
    Node* temp = new Node(data);
    Tail->next = temp;
    Tail = temp;
}

int main(){ 
    system("cls");
    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thrdElement = new Node(30);

    Head->next = secElement;
    secElement->next = thrdElement;
    thrdElement->next = NULL;
    Node* Tail = thrdElement;
    InsertAtTail(Tail,40);
    print(Head);
    return 0;
}
  