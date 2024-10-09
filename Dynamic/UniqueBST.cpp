#include<bits/stdc++.h>
using namespace std;


// CATALAN NUMBER
int memoizationsolve(int n, vector<int> &memo)
{   
    if(n <= 1)
        return 1;

    if(memo[n] != -1)
        return memo[n];

    int ans = 0;
    for(int i=1;i<=n; i++)
    {
        ans += memoizationsolve(i-1, memo)*memoizationsolve(n-i, memo);
    }

    return memo[n] = ans;    
}
int memoization(int n)
{   
    vector<int> memo(n+1, -1);

    return memoizationsolve(n, memo);
}

int tabulation(int n)
{
    vector<int> tab(n+1, 0);

    int ans = 0;
    tab[0] = 1;
    tab[1] = 1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1;j<=i; j++)
        {
            tab[i] += tab[j-1] * tab[i-j];
        }         
    }   
    return tab[n];
}

int main(){

}