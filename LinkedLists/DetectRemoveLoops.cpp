#include<bits/stdc++.h>
#include<vector>
#include<map>
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
Node* start = NULL;

void print(Node* Head){
    Node* temp = Head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

map<Node*,bool> m;

bool detectLoop(Node* &Head){
    Node* temp = Head;
    while (temp!=NULL)
    {
        if (m[temp]==true)
        {
            cout<<"loop starts at "<<temp->data<<endl;
            return 1;
        }
        m[temp]=true;
        temp=temp->next;
    }
    return 0;
}

// 2nd approach
// FLOYD'S WARSHALL ALGORITHM

Node* startNode(Node* poi,Node* Head){
    if (Head==NULL)
    {   return NULL;    }    
        
    Node* slow =Head;
    while (poi != slow)
    {
        slow=slow->next;
        poi=poi->next;
    }
    return slow;
}


bool floyd(Node* &Head){
    Node* fast= Head;
    Node* slow= Head;
 
    while(fast!=NULL)
    {
        fast=fast->next;//1st jump
        
        if ( fast==NULL||fast->next==NULL)
        {//check if the second jump would even be valid or not.
            return 0;
        }
        else
        {
            fast=fast->next;//2nd jump
        }
        slow=slow->next;
        
        if (fast == slow)
        {   
            cout<<startNode(fast,Head)->data<<endl;
            start = startNode(fast,Head);
            return 1;
        }
    }
    return 0;
}      

void removeLoop(Node* &startNode){
    Node* temp = startNode;
    
    while (temp->next!=startNode)
    {
        temp=temp->next;
    }
    temp->next=NULL;
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
    fifthElement->next = thirdElement;

    detectLoop(Head);//will always give the correct Node
    // cout<<endl;
    floyd(Head);//might or might not give the correct Node
    removeLoop(start);
    print(Head);
    return 0;
}
