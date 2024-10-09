#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int recursion(vector<int> &val,int i,int j,vector<vector<int>> &memo)
{
    if(i+1 == j)
    {
        return 0;
    }
    if(memo[i][j] != -1)
    {
        return memo[i][j];
    }

    int mini = INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        int ans = val[i]*val[j]*val[k] + recursion(val,i,k,memo) + recursion(val,k,j,memo);
        mini = min(mini ,ans);
    }
    memo[i][j] = mini;
    return mini;
}

int tabulation(vector<int> &val,int n)
{
    vector<vector<int> > tab(n,vector<int> (n,0));
    
    for(int i=n-1; i>=0; i--)
    {// tab[x][y] represents the minimum score for the figure from x to y

        for(int j=i+2; j<n;j++)// i=2 becoz before this point no triangle will be made by i and j
        {
            int mini = INT_MAX;

            for(int k=i+1; k<j; k++)
            {
                int ans = val[i]*val[j]*val[k] + tab[i][k] + tab[k][j];
                mini = min(mini ,ans);
            }
            tab[i][j] = mini;
        }
    }    
    return tab[0][n-1];//represents the minimum score for the figure pf sides from 0 to n-1
}

int main()
{   
    vector<int>& values;

    int n = values.size();
    vector<vector<int>> memo(n-1,vector<int> (n,-1));
    int res = recursion(values, 0, n-1,memo);
    int res2 = tabulation(values,n);
    
    return 0;
}
