#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* &Head)
{
    Node* temp = Head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    
}

void deleteNode(int position,Node* &Head)
{   
    if (position==1){//SINCE IT CAN'T HAVE A PREV POINTER.
        Node* temp = Head;
        temp->next->prev=NULL;
        Head = temp->next;
        temp->next = NULL; 
        delete temp; 
    }
    
    else{
        Node* temp = Head;
        int i=1;
        while (i<position-1)
    {
        temp=temp->next;
        i++;
    }
    Node*current = temp->next;
    
    if (current->next == NULL)
    {   //Last position node deletion.
        current->prev->next= NULL;
        current->prev=NULL; 
    }
    else{
    current->next->prev=current->prev;
    temp->next=current->next;
    }
    delete current;
}}

void InsertHead(int d,Node* &Head,Node* &Tail)
{
    if (Head==NULL)
    {//FOR EMPTY LISTS.
        Node* temp = new Node(d);
        Head = temp;
        // tail = temp; (IF IT EXISTS)
    }
       
    else{
        Node* temp = new Node(d);
        temp->next = Head;
        Head->prev = temp;
        Head = temp;
}}

void InsertTail(int d,Node* &Tail,Node* &Head)
{
    if (Tail==NULL)
    {   //FOR EMPTY LISTS.
        Node* temp = new Node(d);
        Tail = temp;
        Head = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->prev = Tail;
        Tail->next = temp;
        Tail = temp;
}}

void InsertMiddle(int d,int position,Node* &Head)
{   //wont work for first position.
    //wont work for last position.
    Node* temp = Head;
    int i = 1;
    while (i<position-1)
    {
        temp = temp->next;
        i++;
    }
    
    Node* NodetoInsert = new Node(d);

    NodetoInsert->next = temp->next;
    temp->next = NodetoInsert;
    NodetoInsert->prev = temp;
    NodetoInsert->next->prev= NodetoInsert;
//NodetoInsert ke next ka previous.
}

int main(){
    system("cls");
    Node* Head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    Head->next = second;
    Head->prev = NULL;

    second->next = third;
    second->prev = Head;

    third->next = NULL;
    third->prev = second;
    // InsertHead(5,Head);
    // InsertTail(35,third);
    // InsertMiddle(25,3,Head);
    print(Head);
    cout<<endl;
    deleteNode(3,Head);    
    print(Head);
    return 0;
}