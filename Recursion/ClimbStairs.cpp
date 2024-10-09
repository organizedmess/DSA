#include<iostream>
using namespace std;


// top-bottom
int step(int n)
{
    if(n==0){
        return 1;//only one way to go to zero: 0 - 0
    }
    else if (n==1)
    {
        return 1;//only one way to go to one: 0 - 1 
    }
    else{ 
        
        return step(n-1) + step(n-2);  
    }
    
}

// bottom-up
int solve(int n,int i){
    if(n == i)
        return 1;
        
    if(n < i)//invalid approach 
        return 0;

    return solve(n,i+1) + solve(n,i+2); 
}

int main(){
    system("cls");
    cout<<step(4)<<" ";
    cout<<solve(4,0);
    return 0;
}