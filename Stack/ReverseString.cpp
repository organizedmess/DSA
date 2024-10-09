#include<iostream>
#include<stack>
using namespace std;

int main(){
    system("cls");
    string str="abcde";

    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }
    
    string ans= "";
    int j=0;
    while (!st.empty())
    {   
        ans[j++] = st.top();
        st.pop();
    }

    for (int i = 0; i < str.length(); i++)
    {
        cout<<ans[i];
    }
    
    return 0;
}