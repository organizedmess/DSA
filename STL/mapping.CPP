#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;

int main(){
    system("cls");
    map<string,int>Array;
    //map in memory is stored as a pair of a key and its value.


    Array["Pahadia"]=24;
    Array["Rastogi"]=25;
    Array["Saluja"]=26;

    Array.insert({{"Jain",25},{"Garg",35}});

    map<string,int> :: iterator itr;

    for (itr = Array.begin(); itr != Array.end(); itr++)//cant do itr+1 for maps because they are not stored in continous blocks in memory 
    //itr++ will take us to the slot where next itr is stored while itr will take us to the adjacent block which might throw a garbage value.
    {  
        cout<<(*itr).first<<" "<<(*itr).second<<"\n";
    }

    for(auto value:Array)//'auto' automatically determines the datatype. 
    {//another way to access map without using iterators.   
        cout<<value.first<<" "<<value.second<<endl;
    }


    return 0;
}