#include<iostream>
using namespace std;

bool check(string str,int start,int end){

    if (start > end){
        return true;//BASE CASE
    }
    
    else if (str[start]!=str[end])
    {
        return false;//BASE CASE
    }

    else if (str[start]==str[end])
    {
        return check(str,++start,--end);
    }

}

int main(){
    system("cls");
    string str = "naman";
    cout<<check(str,0,4);
    return 0;
}