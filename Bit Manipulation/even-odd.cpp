#include<bits/stdc++.h>
using namespace std;

int odd_even(int n)
{
    if((n & 1) == 1) 
        return false;
    else  
        return true;
}

int main(){
    int n = 2;

    if(odd_even(n)){
        cout<<"Even";
    }
    else{
        cout<<"Odd";
    }

}