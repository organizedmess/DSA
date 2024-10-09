#include<iostream>
#include<vector>
using namespace std;

// string removeDupli(string str){
//     string temp="";
//     for (int i = 0;i<str.length(); i++)
//     {   //char c =str[i];
//         if(str[i]!=str[i-1] && str[i]!=str[i+1]){
//             temp.push_back(str[i]);
//             }
//         else{
//             char prev=' ';
//             int j=i;
//             while(str[j]==str[j-1])
//             {   
//                 // prev = str[j-1];
//                 temp.pop_back();
//                 // temp.pop_back();
//                 j--;
//             }
//             }
//     }
//     {           
//         int j =0;
//         while (temp[j]!='\0')
//         {
//             cout<<temp[j];
//             j++;
//         }
//     }
//     return temp;
// }


void remove(string str)
{
    int count =0;
    string temp="";
    for (int i = 0; i < str.length(); i++)
    {   
        if( str[i]==str[i-1] || str[i]==str[i+1] )
        {           
            count ++;
            continue;
        }   
        else
        {
            temp.push_back(str[i]);    
        }
    }


    if(count!=0)
    {
        remove(temp);
    }
    
    else
    {           
        int j =0;
        while (temp[j]!='\0')
        {
            cout<<temp[j];
            j++;
        }
    }
    
}


int main(){
    system("cls");
    string str="azxxzy";
    remove(str);
}