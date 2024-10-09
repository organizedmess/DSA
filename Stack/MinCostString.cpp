#include<iostream>
#include<stack>
using namespace std;

int cost(string str){
    
    if(str.length()%2 == 1)
    {
        return -1;
    }
    
    //removing valid paranthesis.
    stack<char> s;
    int i=0;
    while (i<str.length())
    {
        if (str[i]=='{')
        {
            s.push('{');
        }

        else //if(str[i]=='}')
        {   
            if(!s.empty() && s.top() == '{')
            {
                s.pop();
            }

            else
            {
                s.push(str[i]);
            }
        }

        i++;
    }
    
    //dealing with invalid paranthesis
    int a=0;
    int b=0;
    while(!s.empty())
    {   
        if (s.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }
    // cout<<a<<endl;
    // cout<<b<<endl;
    int answer = (a+1)/2 + (b+1)/2;

    return answer;
}

int main(){
    system("cls");
    string str="}}{{{}{{";
    
    cout<<cost(str);
    return 0;
}