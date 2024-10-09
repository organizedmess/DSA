#include<iostream>
using namespace std;

string rev(string &s,int i,int r){
    if (i >= r)
    {
        return s;//Base case
    }
    else{
        char temp = s[i];
        s[i] = s[r-1];
        s[r-1] = temp ;
        rev(s,i+1,r-1);
    }
    return s;
}

int main(){
    system("cls");
    string str = "hello";
    cout << rev(str,0,5);
    return 0;
}