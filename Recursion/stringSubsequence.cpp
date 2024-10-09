#include<iostream>
#include<vector>
using namespace std;

void print(vector<string> v){

        for (int i = 0; i < v.size() ; i++)
        {
            cout<< v[i];
            cout<<endl;
        }
        }
 

void solve(string str,vector<string>& output,int index,string newStr){
    
    if(index >= str.length())//BASE CASE
    {   
        output.push_back(newStr);
        return ;
    }
    //EXCLUDE
    solve(str,output,index+1,newStr);   
    
    //INCLUDE 
    char element = str[index];
    newStr.push_back(str[index]);
    solve(str,output,index+1,newStr);   

}

int main(){
    system("cls");
    string str = "abc";
    string newStr ="";
    vector<string> output;
    solve(str,output,0,newStr);
    print(output);   
    return 0;
}