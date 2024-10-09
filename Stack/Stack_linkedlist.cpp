#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this->data=d;
        this->next=NULL;
        cout<<"Node"<<endl;
    }
};

class Stack
{
    public: 
    Node* Head=new Node(-1);

    Stack(int d){
        this->Head->data=d;
        cout<<"Stack"<<endl;
    }

    void push(int d){
        Node* newNode=new Node(d);
        newNode->next=Head;
        Head=newNode;
        cout<<"push"<<endl;
    }

    void pop(){
        if (Head==NULL||Head->data==-1)
        {
            cout<<"Stack Underflow.";
        }
        else{
            Node* temp=this->Head;
            this->Head=this->Head->next;
            delete temp;
            cout<<"popped"<<endl;
        }}

    void peek(){
        if (Head==NULL||Head->data==-1)
        {
            cout<<"Empty Stack.";
        }
        else{
            cout<<Head->data<<endl;
        }
    }
    
    bool isEmpty(){
        if (Head==NULL||Head->data==-1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }

};

int main(){
    system("cls");
    
    Stack st(4);

    st.push(5);
    st.push(7 );
    st.push(1);
    st.push(3);
    st.pop();
    st.pop();
    st.pop();
    st.peek();
    cout<<st.isEmpty();
    
    return 0;
}