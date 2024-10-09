#include<bits/stdc++.h>
#include<stack>
using namespace std;

void insert(stack<int> &st,int key)
{
    if (st.empty())
    {   
        st.push(key);//Base Case
        return ;
    }
    
    int value=st.top(); 
    st.pop();
    insert(st,key);
    st.push(value);

    return;
}

void reversal(stack<int> &st){
    
    if (st.empty())
    {
        return ;

    }

    int value=st.top();
    st.pop();

    reversal(st);
    insert(st,value);
    
    return ;
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
    st.push(3);
    st.push(9);
    st.push(1);
    st.push(7);
    st.push(2);
    stack<int> ans;

    PrintStack(st);
    reversal(st);
    cout<<endl;
    PrintStack(st);
    
    return 0;
}