#include<iostream>
#include<vector>
#define MOD 1000000007// to avoid integer overflow
using namespace std;

long long int memoization(int n,vector<long long int> &memo)
{
    if (n <= 1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    if(memo[n] != -1)
        return memo[n];
    // fn(n-1) is is the case in which elements are not swapped 
    // fn(n-2) is is the case in which elements are swapped 
    memo[n]= ((n-1)%MOD) *((memoization(n-1,memo)%MOD) + (memoization(n-2,memo)%MOD))%MOD;   
    //MOD  needs to be applies at every step as this calculation is a risk of getting overflow 
    //even within the formula
    return memo[n];
}

long long int tabulation(int n){

    vector<long long int> tab(n+1,-1);
    tab[0]=0;
    tab[1]=0;
    tab[2]=1;
        
    for(int i=3;i<=n;i++)
    {    
        tab[i] = ((i-1)%MOD)*((tab[i-1]%MOD) + (tab[i-2]%MOD))%MOD;
    }

    return tab[n];
}

long long int spaceOptimization(int n){

    vector<long long int> tab(n+1,-1);
   
    int prev2 = 0;
    int prev1 = 1;
    int curr;
    
    for(int i=3;i<=n;i++)
    {    
        curr = ((i-1)%MOD)*((prev1%MOD) + (prev2%MOD))%MOD;

        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}


int main(){
    int n;
    vector<long long int> memo(n+1,-1);
    cout<<memoization(n,memo);
    cout<endl;
    
    cout<<tabulation(n);
    cout<endl;
    
    cout<<spaceOptimization(n);

    return 0;
}