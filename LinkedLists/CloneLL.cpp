#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* rand;

    Node(int d){
        this->data=d;
        this->next=NULL;
        this->rand=NULL;
    }
};

void InsertAtTail(Node* &Head,Node* &Tail,int d)
{   
    Node* newNode=new Node(d);

    if(Head==NULL)
    {
          Head=newNode;  //the first Node
          Tail=newNode;  
    }
    else
    {
        Tail->next=newNode;
        Tail=newNode;
    }
}


// METHOD 1 : CREATE A MAP 
Node* clone(Node* &Head)
{   
    Node* temp=Head;

    // CLONE A LINKED LIST WITHOUT THE RANDOM POINTER 
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    
    while (temp!=NULL)
    {   
        InsertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;    
    }

    //create the map
    map<Node*,Node*> OldToNew;

    Node* cloneNode=cloneHead;
    Node* originalNode=Head;

    while(originalNode != NULL)
    {
        OldToNew[originalNode]=cloneNode;

        originalNode=originalNode->next;
        cloneNode=cloneNode->next; 
    }

    originalNode=Head;
    cloneNode=cloneHead;

    while(originalNode!=NULL)
    {
        cloneNode->rand=OldToNew[originalNode->rand];//IN THIS:- originalNode->rand = fourthElement(lets say), so now cloneNode->rand = OldToNew[forthElement] and OldToNew[fourthelement] is the key to fourthElement (of clone Node)

        originalNode=originalNode->next;
        cloneNode=cloneNode->next;
    }
    return cloneHead;
    
}


// METHOD 2 : WE DO NOT CREATE A MAP INSTEAD REALLOCATE THE POINTERS.
Node* clone2(Node* &Head)
{
    Node* temp=Head;
    Node* cloneHead=NULL;
    Node* cloneTail=NULL;
    // SIMPLY CLONE THE LIST WITHOUT RAND POINTER.
    while (temp!=NULL)
    {
        InsertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    
    //NOW WE MERGE THE TWO LISTS.
    Node* originalNode=Head;
    Node* cloneNode=cloneHead;

    while(originalNode != NULL && cloneHead != NULL)
    {   
        Node* forward=originalNode->next;
        originalNode->next=cloneNode;
        originalNode=forward;

        Node* cloneForward = cloneNode->next;
        cloneNode->next=originalNode;
        cloneNode=cloneForward;
    }

    //NOW WE DEAL WITH RANDOM POINTERS. 
    temp=Head;
    while(temp!=NULL)
    {   
        if (temp->next!=NULL)
        {   
            if(temp->rand != NULL)
            {
                temp->next->rand=temp->rand->next;
            }
            else
            {
                temp->next->rand=NULL;//because temp->rand->next does not exist as temp->rand = NULL
            }
        }

    temp=temp->next->next;//temp onlys stays at original Node.
    }
    //NOW WE UN-MERGE THE STRINGS
     originalNode=Head;
     cloneNode=cloneHead;

    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next=cloneNode->next;
        originalNode=originalNode->next;

        if (originalNode != NULL)
        {
            cloneNode->next=originalNode->next;
        }
        cloneNode=cloneNode->next;
    }
    return cloneHead;
}


int main(){
    system("cls");
    Node* Head1 = new Node(3);
    Node* secElement1 = new Node(1);
    Node* thrdElement1 = new Node(7);
    Node* fourthElement1 = new Node(9);
    Head1->next = secElement1;
    secElement1->next = thrdElement1;
    thrdElement1->next = fourthElement1;
    fourthElement1->next= NULL;

    Head1->rand = fourthElement1;
    secElement1->rand = Head1;
    thrdElement1->rand = Head1;
    fourthElement1->rand= thrdElement1;

    Node* cloneHead = clone2(Head1);
    cout<<cloneHead->data<<endl;
    cout<<cloneHead->next->data<<endl;
    cout<<cloneHead->rand->data<<endl;


    return 0;
}
