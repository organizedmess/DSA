#include<iostream>
using namespace std;

class Node{
    public :    
    int data ;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void InsertHead(int data, Node* &Head){
    Node* temp = new Node(data);//Creating a node.
    temp->next = Head;//Pointing the new towards the head. 
    Head = temp;//Now changing the 'Head' pointer.
}

void print(Node* &Head){
    Node* temp = Head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;   
}

int main(){
    system("cls");
    Node* Head = new Node(10);
    
    print(Head);
    InsertHead(50,Head);
    print(Head);
    
    return 0;
}
