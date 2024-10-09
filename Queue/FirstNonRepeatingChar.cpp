#include<iostream>
#include<queue>
#include<map>
using namespace std;



string FirstNonRepeating(string str){
    queue<int> q;
    map<char,int> count;
    string ans="";
    for (int i = 0; i < str.length(); i++)
    {   
        count[str[i]]++;
        q.push(str[i]);

        while (!q.empty())
        {
            if (count[q.front()]>1)//first time appearing 
            {
                q.pop();
            }
            else//has already appeared aka repeating 
            {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){//only 2 ways to get out of while loop:(1) You found a non repeating char (2) You ran out of queue
        
        ans.push_back('#');//there was no non-repeating character 
        }   
    }
    return ans;
}

int main(){
    system("cls");
    string str="aabc";
    string result = FirstNonRepeating(str);
    cout<<result[0];
    cout<<result[1];
    cout<<result[2];
    cout<<result[3];
    return 0;
}