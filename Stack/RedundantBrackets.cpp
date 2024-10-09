#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool redundant(string str){
    stack<char> s;

    int i=0;
    bool answer=true;//if a bracket is redundant
    char value;
    while (i< str.length())
    {
        if ( str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' )
        {   
            value = str[i];
            s.push(str[i]);
            answer=true;
        }
        else
        {
            if (str[i]==')')
            {   
                while (s.top() != '(')
                {
                    if(s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                        {
                            answer=false;
                        }
                    s.pop();
                }
                
            }
            
        }
        i++;
    }
    return answer;
    

}

int main(){
    system("cls");
    string str="(a+(c*b)+c)";
    cout<<redundant(str);

    return 0;
}