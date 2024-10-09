#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void InsertMiddle(Node* &Head,int d,int position){
    Node* temp = Head; 
    int i = 1;//linked lists start from 1 and not 0.

    //WHEN INSERTING AT FIRST POSITION.
    
/*    if (position == 1)
    {
       InsertAtHead() 
    }
*/
    //WHEN INSERTING AT LAST POSITION.
 
 /*   if (temp->next == NULL )
    {
        InsertAtTail();
    }
*/
while (i<position-1)
    {   
        temp = temp->next;
        i++;
    }

    Node* nodetoInsert = new Node(d);

    nodetoInsert->next = temp->next ;
    temp->next = nodetoInsert;
    
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


    //THIS FUNCTION WONT WORK FOR 1ST POSITION.
    
    InsertMiddle(Head,25,4);//3 denotes the position we want to insert this node.
    print(Head);
    return 0;
}