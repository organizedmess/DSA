#include<iostream>
using namespace std;

class CircularQueue{
    public:
    int* arr;
    int front=-1;
    int rear=-1;
    int size;
    
    CircularQueue(int size){
        this->size=size;
        arr=new int[size];
    }

    bool enqueue(int value){
        if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
        {   
            cout<<"overflow"<<endl;
            return 0;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front]=value;
            cout<<"pushed in 1st cond"<<endl;
            return 1;
        }
        else{
            rear = (rear+1)%(size);
            arr[rear]=value;
            cout<<"pushed in 2nd cond"<<endl;
            return 1;
        }
    }

    int dequeue(){
        if (front == -1)
        {    
            cout<<"underflow"<<endl;
            return -1;
        }
        else if(front == rear){
            int t= front;
            front = -1;
            rear = -1;
            cout<<"popped in 1st cond"<<endl;
            return arr[t];
        }
        else{    
            int t= front;
            front = (front+1)%(size);
            cout<<"popped in 2nd cond"<<endl;
            return arr[t];
        }
    }
};

int main(){
    system("cls");
    CircularQueue q(3);
    q.enqueue(2);
    // q.dequeue();    

    return 0;
}