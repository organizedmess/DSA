#include<iostream>
using namespace std;

class Queue{
    public:
    int* arr;
    int s;
    int front=0;
    int rear=0;

    Queue(int s){
        this->s=s;
        arr=new int[s];
    }

    void enqueue(int d){
        if(rear>=s){
            cout<<"Queue overflow!!"<<endl;
        }
        else{ 
            rear++;
            arr[rear]=d;
            cout<<"Enqueued!!"<<endl;
        }
    }
    void dequeue(){
        if (front==rear){
            cout<<"Queue is empty!!"<<endl;
        }
        else{
            front++;
            if (front==rear)
            {
                front=0;
                rear=0;
            }
            cout<<"Dequeued!!"<<endl;
        }
    }
    int size(){
        return (rear-front); 
    }
    bool isEmpty(){
        if (front==rear)
        {
            return true;
        }
        else
        {
            return false; 
        }
        
    }
};
            


int main(){
    system("cls");
    Queue q(5);
    q.enqueue(3);
    q.enqueue(8);
    q.enqueue(34);

    cout<<q.size();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout<<q.isEmpty();

    return 0;
}