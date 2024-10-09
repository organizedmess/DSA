#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(vector<int>& prices, int index, int limits, bool buy, vector<vector<vector<int> > > &memo) 
{
    if(index == prices.size())
        return 0;
    
    if(limits == 0)
        return 0;

    if(memo[index][buy][limits] != -1)
        return memo[index][buy][limits];

    int profit1 = 0;
    int profit2 = 0;
    if(buy)// if buy is 1 then can buy
    {
        int buy = -prices[index] + memoizationSolve(prices, index+1, limits, 0, memo);

        int ignore = memoizationSolve(prices, index+1, limits, 1, memo);
    
        profit1 = max(buy, ignore);
    }
    else
    {
        int sell = prices[index] + memoizationSolve(prices, index+1, limits-1, 1, memo);

        int ignore = memoizationSolve(prices, index+1, limits, 0, memo);

        profit2 = max(sell, ignore);
    }    
    return memo[index][buy][limits] = max(profit1, profit2);
}
int memoization(vector<int>& prices)
{
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(3, -1)));

        int ans = memoizationSolve(prices, 0, 2, 1, memo);
        return ans;
}

int tabulation(vector<int> &prices, int n)
{
    vector<vector<vector<int>>> tab(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    for(int i=n-1; i>=0; i--)
    {
        for(int b=0; b<2; b++)
        {
            for(int l=1; l<=2; l++)
            {
                int profit1 = 0;
                int profit2 = 0;
                if(b == 1)// if buy is 1 then can buy
                {
                    int buy = -prices[i] + tab[i+1][0][l];

                    int ignore = tab[i+1][1][l];
                    
                    profit1 = max(buy, ignore);
                }
                else
                {
                    int sell = prices[i] + tab[i+1][1][l-1];

                    int ignore = tab[i+1][0][l];

                    profit2 = max(sell, ignore);
                }
                    tab[i][b][l] = max(profit1, profit2);
            }
        }
    }
    return tab[0][1][2];

}

int SpaceOptimizedtabulation(vector<int> &prices, int n)
{
    // vector<vector<vector<int>>> tab(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    vector<vector<int> > curr(2, vector<int> (3, 0));
    vector<vector<int> > next(2, vector<int> (3, 0));

    for(int i=n-1; i>=0; i--)
    {
        for(int b=0; b<2; b++)
        {
            for(int l=1; l<=2; l++)
            {
                int profit1 = 0;
                int profit2 = 0;
                if(b == 1)// if buy is 1 then can buy
                {
                    int buy = -prices[i] + next[0][l];
                    int ignore = next[1][l];
                    profit1 = max(buy, ignore);
                }
                else
                {
                    int sell = prices[i] + next[1][l-1];
                    int ignore = next[0][l];
                    profit2 = max(sell, ignore);
                }
                    curr[b][l] = max(profit1, profit2);
            }
        }
        next = curr;
    }
    return curr[1][2];

}

int main(){

}