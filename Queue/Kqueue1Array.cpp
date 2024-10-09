#include<iostream>
using namespace std;

class Queue{
    public:
    int* arr;
    int* next;
    int* front;
    int* rear;
    int freespot=0;
    int data;
    int size;
    int Qtotal;

    Queue(int size,int k){
        this->Qtotal=k;
        front=new int[k];
        rear=new int[k];

        this->size=size;
        arr=new int[size];
        next=new int[size];

        for (int i = 0; i < k; i++)
        {
            front[i]=-1;
            rear[i]=-1;
        }
        
        for (int i = 0; i < size; i++)
        {   
            if (i==(size-1))
            {
                next[i]=-1;
            }
            next[i]=i+1;
        }
    }

    void push(int d,int QueueNo){
        //overflow
        if (freespot==-1)
        {
            cout<<"overflow"<<endl;
            return ; 
        }
        int index=freespot;

        freespot= next[freespot];

        if (front[QueueNo-1]==-1)
        {//if we are puhsing first element that, concerns front as well.
            front[QueueNo-1]=index;
        }
        else
        {//LINK the new element to the previous element of that particular Queue.
            next[rear[QueueNo-1]]=index;
        //this means the 'rear' index in the next must be changed to 'index' as that is where our new element will be inserted and rear is gonna change as well
        }

        //update next//this "index" represents the last no. 
        next[index]=-1;//representing that this is the last num of that particular queue

        //update rear
        rear[QueueNo-1]=index; 

        //push element 
        arr[index]=data;
        cout<<"Pushed"<<endl;
    }


    void pop(int QueueNo){
        if (front[QueueNo-1] == -1)
        {   //Underflow
            cout<<"Underflow"<<endl;
            return ;
        }
    
        //find index to pop 
        int index=front[QueueNo-1];

        //front ko aage badhao 
        front[QueueNo-1]=next[index];

        //freeSlots ko manage karo 
        next[index]=freespot;
        freespot=index;
        cout<<"Popped"<<endl;
        return ;
    }
};

int main(){
    system("cls");
    Queue q(10, 3);
    q.push(10, 1);
    q.push(15,1);
    q.push(20, 2);
    q.push(25,1);

    q.pop(1); 
    q.pop(2);
    q.pop(1); 
    q.pop(1);
    q.pop(1); 

    return 0;
}