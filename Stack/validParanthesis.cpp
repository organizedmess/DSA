#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool paran(string str){
    stack<char> st;
    int i=0;
    while (i<str.length())
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            st.push(str[i]);
        }
        
        else if (str[i] == ')')
        {   
            if( st.top() == '(' )
            {   
                st.pop();
            }
            else
            {
                return 0;
            }
            
        }
        else if ( str[i] == '}' )
        {

            if ( st.top() == '{' )
            {   
                st.pop();
            }
            else
            {
                return 0;
            }
        }
        else if ( str[i] == ']' )
        {
            if ( st.top() == '[' )
            {   
                st.pop();
            }
            else
            {
                return 0;
            }
        }
    i++;
    }
    
    return 1;
}

int main(){
    system("cls");
    string str =  "[(])";

    cout<<paran(str);
    return 0;
}