#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(int start, int end, vector<vector<int>>& memo)
{
    if(start>=end)
        return 0;

    if(memo[start][end] != -1)
    {
        return memo[start][end];
    }

    int maxx = INT_MAX;

    for(int i=start; i<= end; i++)
    {
        maxx = min(maxx, (i + max(memoizationSolve(start, i-1, memo),memoizationSolve(i+1, end, memo) ) ));
    }
        return memo[start][end] = maxx;
}
int memoization(int n)
{
    vector<vector<int> > memo(n+1, vector<int> (n+1, -1));
    return memoizationSolve(1, n, memo);
}

int tabulation(int n)
{
    vector<vector<int> > tab(n+2, vector<int> (n+2, 0));
        
    for(int start=n; start>=1; start--)
    {   
        for(int end=start; end<=n; end++)
        {
            if(start==end)
                continue;

            int maxx = INT_MAX;
            for(int i=start; i<=end; i++)
            {                  
                maxx = min(maxx, ( i + max(tab[start][i-1], tab[i+1][end])));
            }
            tab[start][end] = maxx;
        }   
    }
    return tab[1][n];

}

int main(){

}