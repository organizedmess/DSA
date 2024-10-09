#include<iostream>
#include<queue>
#include<stack>
using namespace std;


// method 1:use stack (T.C = o(n) S.C = o(n))
queue<int> rev1(queue<int> q){
    stack<int> st;
    
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    
    return q;
}


// method 2:recursion (T.C = o(n) S.C = o(1))
queue<int> rev2(queue<int> &q){   
    if(q.empty()){
        return q;
    }
    int val=q.front();
    q.pop();
    rev2(q);
    q.push(val);
    
    return q;
}



void PrintQueue(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();   
    }
    cout<<endl;
}

int main(){

    system("cls");
    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    queue<int> ans;
    PrintQueue(q);

    ans=rev2(q);

    PrintQueue(ans);

    return 0;
}