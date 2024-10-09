#include<iostream>
using namespace std;

int expo(int a,int b){
    
    if(b == 1){
        return a;//BASE CASE
    }
    else if(b == 0){
        return 1;//BASE CASE
    }

    else{
        int ans = expo(a,b/2); 

        if (b%2==0)
        {
            return ans * ans;
        }
        else
        {
            return a * ans * ans;
        }
    }
    }

int main(){
    system("cls");
    int a=3 ;
    int b=2 ;
    cout<<expo(a,b);
    return 0;
}