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

void print(Node* &Tail)
{
    Node* temp=Tail;
    if (Tail == NULL)
    {
        cout<<"List is empty.";
        return;
    }
    
    do
    {   cout<<temp->data<<" ";//Tail will be printed first.
        temp=temp->next;
    } while (temp != Tail);
    cout<<endl;
}

void InsertNode(Node* &Tail,int d,int value)
{
    Node* temp=new Node(d);
    // case 1: Empty list
    if (Tail == NULL)
    {
        Tail=temp;
        temp->next=temp;
    }
    
    //case 2: NON-EMPTY LISTS
    else
    {   
        Node* crnt=Tail;

        while (crnt->data != value)
        {
            crnt=crnt->next;
        }
        //Now 'current' is the node with data 'value' ;

        temp->next=crnt->next;
        crnt->next=temp;

}}

void deleteNode(Node* &Tail,int value)
{   
    Node* prev = Tail;
    while (prev->next->data != value)
    {
        prev=prev->next;    
    } 
    // prev here will represent the node which is previous to the node that has the element 'value'.

    Node* curr = prev->next;
    
    if (Tail == curr)//meaning temp->next represents Tail.
    {   
        prev->next = curr->next;
        Tail = prev;//We have to make the last node 'tail'.
        delete curr;
    }

    else
    {
        prev->next = curr->next;
        delete curr;
    }
    
    
}

int main(){
    system("cls");
    Node* Tail =NULL;

    InsertNode(Tail,7,0);
    // print(Tail);

    InsertNode(Tail,5,7);
    // print(Tail);

    InsertNode(Tail,16,7);
    // print(Tail);

    InsertNode(Tail,4,16);
    print(Tail);

    deleteNode(Tail,7);
    print(Tail);
    cout<<Tail->data;
    return 0;
}