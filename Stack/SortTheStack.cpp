#include<bits/stdc++.h>
#include<stack>
using namespace std;

void sortedInsertion(stack<int> &st,int key){
    if (st.empty() || ((!st.empty()) && st.top() <= key)){
        st.push(key);
        return ;
    }

    int value=st.top();
    st.pop();
    sortedInsertion(st,key);
    st.push(value);
    return ;    
}

void sort(stack<int> &st){
    if (st.empty())
    {
        return ;
    }

    int value=st.top();
    st.pop();
    sort(st);
    
    sortedInsertion(st,value);

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

    PrintStack(st);
    sort(st);
    cout<<endl;
    PrintStack(st);

    return 0;
}