#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;//index

    Stack(int s){
        this->size=s;
        arr=new int[size];
        top=-1;
    }

    void push(int d){
        if(top<(size-1))
        {
            top++;
            arr[top]=d;
            cout<<"Done"<<endl;
        }
        else
        {
        cout<<"Stack Overflow."<<endl;
        }
    }

    void pop(){
        if(this->top<0){
            cout<<"Stack Underflow."<<endl;
        }
        else{
            top--;
            cout<<"Pop Done."<<endl;
        }
    }
    
    void peek(){
        if (this->top<0){
            cout<<"Stack is empty."<<endl;
        }
        else{
            cout<<arr[top]<<endl;
        }
    }

    bool isEmpty(){
        if (this->top<0){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    system("cls");
    Stack st(5);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.peek();
    cout<<st.isEmpty();
    return 0;
}