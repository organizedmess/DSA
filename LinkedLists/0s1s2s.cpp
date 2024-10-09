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


//APPROACH 1
void insert(Node* &newHead,int value){
    Node* temp=newHead;
    Node* newNode=new Node(value);
    
    if(temp!=NULL)
    {  
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next= newNode;
        newNode->next=NULL;
    }

    else
    {   
        newHead=newNode;
        newHead->next=NULL;
    }
    
}

Node* count(Node* &Head){
    Node* temp=Head;
    int arr[3]={};
    while (temp!=NULL)
    {
        arr[temp->data]++;
        temp=temp->next;
    }
    Node* newList=NULL;
    for (int i=0;i<3;i++)
    {   
        int j=0;
        while (j<arr[i])
        {   
            insert(newList,i);
            j++;
        }
    }
    return newList;
}


//APPROACH 2
void insertAtTail(Node* &Tail,int value){

    Node* newNode = new Node(value);
    Tail->next=newNode;
    Tail=newNode;  
}

void method2(Node* &head){
    Node* head0 = new Node(-1);
    Node* tail0 = head0;
    Node* head1 = new Node(-1);
    Node* tail1 = head1;
    Node* head2 = new Node(-1);
    Node* tail2 = head2;

    Node* temp = head;

    while (temp!=NULL)
    {
        if (temp->data==0){
            insertAtTail(tail0,0);
        }
        else if(temp->data==1){
            insertAtTail(tail1,1);
        }
        else if(temp->data==2){
            insertAtTail(tail2,2);
        }
        temp=temp->next;
    }
     
    //  MERGE THEM
     
    if (head1->next!=NULL)//this will check if the list 'head1' is empty or not
    {
        tail0->next=head1->next;
    }
    else{
        //there is no zero in the list 
        tail0->next=head2->next;
    }

    tail1->next=head2->next;
    tail2->next=NULL; 

    //setup head 
    head=head0->next;
    //delete dummy Nodes
    delete head0;
    delete head1;
    delete head2;
}   



int main(){
    system("cls");
    Node* Head = new Node(1);
    Node* secElement = new Node(0);
    Node* thirdElement = new Node(1);
    Node* fourthElement = new Node(0);
    Node* fifthElement = new Node(2);
    Node* sixthElement = new Node(0);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = sixthElement;
    sixthElement->next = NULL;
    
    print(Head);
    // Node* head2=count(Head);
    method2(Head);
    print(Head);
    

    return 0;
}