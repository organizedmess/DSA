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

class Queue{
    public:
    Node* front;
    Node* rear;
    
    Queue(int d){
        front=NULL;
        rear=NULL;
    }

    void enqueue(int d){
        Node* newNode=new Node(d);
        if (rear==NULL)
        {
            front=rear=newNode;
            return ;
        }
     
        rear->next=newNode;
        rear=rear->next;//rear advanced
        cout<<"enqueued!!"<<endl;
    }

    void dequeue(){
        if (front==NULL)
        {
            return ;
        }
        Node* temp=front;
        front=front->next;

        if (front==NULL)
        {
            rear=NULL;
        }
        
        delete(temp);
        cout<<"dequeued!!"<<endl;
    }
};

int main(){
    system("cls");
    Queue q(5);
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(34);

    // cout<<q.size();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // cout<<q.isEmpty();

    return 0;
}