#include<iostream>
#define MOD 1000000007
using namespace std;

int memoization(int n, int k,vector<int> &memo) {
    if(n==1)
        return k;
    
    if(n==2)
        return (k%MOD + (k%MOD*1LL*(k-1)%MOD)%MOD)%MOD;
 
     if(memo[n]!=-1)
     {
        return memo[n];
    }

    memo[n] = (k-1)%MOD*1LL*(( memoization(n-1,k,memo)%MOD + memoization(n-2,k,memo)%MOD)%MOD)%MOD;
    
    return memo[n];
}

int tabulation(int n, int k) {
    vector<int> tab(n+1);

    tab[0] = 0;
    tab[1] = k;
    tab[2] = ((1LL * k * (k-1)) % MOD + k) % MOD;

    for (int i = 3; i <= n; i++) {
        tab[i] = ((1LL * (k-1) * (tab[i-1] + tab[i-2])) % MOD);
    }
    
    return tab[n];
}


int spaceOtimization(int n, int k) {
    vector<int> tab(n+1);

    int prev2 = k;
    int prev1 = ((1LL * k * (k-1)) % MOD + k) % MOD;

    int curr;
    for (int i = 3; i <= n; i++) {
        curr = ((1LL * (k-1) * (prev1 + prev2)) % MOD);
    
        prev2=prev1;
        prev1=curr;
    }
    
    return prev1;
}

int main()
{
    int n=;
    int k=;

    vector<int> memo(n+1,-1);
    cout<<memoization(n,k,memo);
    cout<<endl;
    cout<<tabulation(n,k);
    cout<<endl;
    cout<<spaceOtimization(n,k);

    return 0;
}