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

Node* MiddlePointer(Node* Head)//this function will give the value farther from the Head in case of linked list.
{
    Node* pro = Head;//double jump
    Node* noob = Head;//single jump

    if (Head == NULL || Head->next==NULL)
    {
        return Head;//empty or 1 node list.
    }
    
    while (pro != NULL)
    {
        pro=pro->next;      //first jump 

        if (pro != NULL)    //check if we exited list
        {
            pro=pro->next;  //2nd jump 
        }
            noob=noob->next;//ONLY one jump
    }
        return noob;
        
}

Node* Middle(Node* &Head){//this function will give the value closer to the head in case of even linked list.
    Node* fast = Head;
    Node* slow= Head;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast =fast->next->next;
        slow =slow->next;
    }
    return slow;
}

    

int main(){
    system("cls");
    Node* Head = new Node(10);
    Node* secElement = new Node(20);
    Node* thirdElement = new Node(30);
    Node* fourthElement = new Node(40);
    Node* fifthElement = new Node(50);
    Head->next = secElement;
    secElement->next = thirdElement;
    thirdElement->next = fourthElement;
    fourthElement->next = fifthElement;
    fifthElement->next = NULL;

    cout<<MiddlePointer(Head)->data<<endl;
    cout<<Middle(Head)->data;

    return 0;
}