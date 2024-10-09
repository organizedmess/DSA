#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int *next;
    int *top;
    int freeSpot;
    int size;
    int m;
    Stack(int s,int m){
        this->size=s;
        this->m=m;
        arr= new int[s];
        
        top= new int[m];
        for (int i=0;i<m;i++){
            top[i]=-1;
        }
        
        next=new int[s];
        for (int i=0;i<s;i++){
            if (i==s-1)
            next[i]=-1;
            
            else
            next[i]=s+1;
        }
        freeSpot=0;
    }
        
    
    void push(int d,int m){
       
       if(freeSpot == -1)
        {
            cout<<"stack overflow";       
        }
        else
        {
            arr[freeSpot]=d;

            int temp=freeSpot;
            freeSpot=next[temp];    
            next[temp]=top[m-1];
            
            top[m-1]=temp;  
            cout<<"PUSHED"<<endl;      
        }
    }
    
    void pop(int m){
        if (top[m-1]==-1)
        {
            cout<<"Empty"<<endl;
        }
        int temp=top[m-1];
        cout<<"temp is"<<arr[temp]<<endl;

        top[m-1]=next[temp];

        next[temp]=freeSpot;

        freeSpot=temp;
        cout<<"POPPED: "<<arr[temp]<<" from "<<m<<" Stack"<<endl;
    }
};

int main(){
    system("cls");
    Stack st(8,3);
    st.push(4,2);
    st.push(3,3);
    st.pop(3);
    return 0;
}