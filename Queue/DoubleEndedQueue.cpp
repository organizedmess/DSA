#include<iostream>
using namespace std;

class dequeue{
    public:
    int* arr;
    int front=-1;
    int rear=-1;
    int n;

    dequeue(int s){
        this->n=s;
        arr=new int[n];
    }

    void push_front(int val){
        if ((front==0 && rear==n-1) ||
            (front!=0 && rear==(front-1)%(n-1)))        //checking if the array is full
        {   
            cout<<"Stack Overflow!!"<<endl;
            return;
        }

        else if(front==-1)
        {
            front=rear=0;
        }
        else if (front==0)//another way of maintaining cyclic nature
        {
            front=n-1;
        }
        else{
            front--;
        }
        arr[front]=val;
        cout<<"Pushed in front."<<endl;
        return;
    }

    int pop_front(){
        int ans;
        if(front==-1)
        {
            cout<<"Stack Underflow!!"<<endl;
            return -1;
        }
        else if(front==rear)
        {
            ans =arr[front];
            arr[front] = -1;//discarding the element in that index by overwriting with -1;
            front=-1;
            rear=-1;
        }
        else if (front==n-1)
        {
            ans =arr[front];
            arr[front] = -1;//discarding the element in that index by overwriting with -1;
            front=0;//cyclic nature
        }
        else
        {
            ans =arr[front];
            arr[front] = -1;//discarding the element in that index by overwriting with -1;
            front++;
        }
        return ans;
    }



    void push_back(int val){
        if((front==0 && rear==n-1) ||
            (front!=0 && rear==(front-1)%(n-1)))
        {
            cout<<"Overflow"<<endl;
            return ;
        }
        else if(rear==-1){
            front=0;
            rear=0;
        }
        else if(rear==n-1)
        {
            rear=0;//cyclic nature
        }
        else{
            rear++;
        }
        arr[rear]=val;
        cout<<"Pushed in back."<<endl;
        return;
    }

    int pop_back(){
        int ans;
        if(rear==-1)
        {
            cout<<"Queue Underflow!"<<endl;
            return -1;
        }

       else if(rear==front)
        {   
            ans=arr[rear];
            arr[rear]=-1;
            front=rear=-1;//reset
        }
        else if (rear==0)
        {   
            ans=arr[rear];
            arr[rear]=-1;
            rear=n-1;//Cyclic Nature
        }
        else
        {
            ans=arr[rear];
            arr[rear]=-1;
            rear--;
        }
        return ans;
    }

};

int main(){
    system("cls");

    dequeue q(5);
    q.push_front(10);
    q.push_front(20);
    q.push_front(30);
    q.push_back(40);
    q.push_back(50);
    q.push_back(60);

    // cout<<q.size();
    // q.dequeue();
    // q.dequeue();
    // q.dequeue();
    // cout<<q.isEmpty();
    return 0;
}