#include<bits/stdc++.h>
#include<stack>
using namespace std;

void deleteMid(stack<int> &st){
    int n=st.size();
    stack<int> ab;

    for (int i = 0; i < n/2; i++)
    {   
        ab.push(st.top());
        st.pop();
    }
    st.pop();

    while (!ab.empty())
    {
        st.push(ab.top());
        ab.pop();
    }
    
}

void method2(stack<int> &st,int size,int n){
    if (size==((n/2)+1))
    {   
        st.pop();
        return;
    }
    
    int value=st.top();
    st.pop();
    method2(st,(size-1),n);
    st.push(value);

    return;
    
}

void PrintStack(stack<int> s)
{
    if (s.empty())
        return;
    
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

int main(){
    system("cls");
    stack<int> st;
    st.push(4);
    st.push(6);
    st.push(9);
    st.push(0);
    st.push(4);
    // st.push(1);

    PrintStack(st);
    cout<<endl;
    method2(st,st.size(),st.size());
    PrintStack(st);

    return 0;
}