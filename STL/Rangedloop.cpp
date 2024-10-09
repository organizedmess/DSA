#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;
        
         
int main(){
    system("cls");

    vector<int> vec ={4,7,2,6,3,7};
    vector<string> Names ={"abf","gfd","rey","iyu"};

    for (auto value:vec){//a copy will be sent for every value in vec
       
        value++;//wont make any change in the actual value of vector but in the copy
        cout<<value<<" ";
    }
    cout<<endl;     

    for(int &value: vec){//the address of every value in 'vec' is sent
        value++;//will change the actual value of the element in the vector.
        cout<<value<<" ";
    }
    cout<<endl;
    for(string str: Names){
        cout<<str<<endl;
    }
    
    return 0;
}