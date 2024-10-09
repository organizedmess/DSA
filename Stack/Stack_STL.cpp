#include<iostream>
#include<stack>//using STL implementation 
using namespace std;

int main(){
    system("cls");
    stack<int> s;//declaring stack 
    
    // PUSH OPERATION
    s.push(4);
    s.push(2);
    s.push(11);
    cout<<s.top()<<endl;

    //POP OPERATION
    s.pop();
    cout<<s.top()<<endl;

    //IS EMPTY 
    
    if(s.empty()==1)
    {
        cout<<"stack is empty!!";
    }
    else
    {
        cout<<"stack is not empty. The elements are :";
        while (s.empty()==0)
        {
            cout<<s.top()<<" ";
            s.pop();
        }
    }
    
    return 0;
}
