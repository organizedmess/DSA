#include<bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0; i<=5; i++){
        cout<<i<<" "; 
        for(int j=i; j<=5; j++){
            if(i%2 != 0){

            }
            else{
                cout<<"j is "<<j<<" ";
                i = j;
                break;
            }
        }


        cout<<"--"<<i<<endl;
    }
    return 0;
}