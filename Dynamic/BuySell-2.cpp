#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(vector<int>& prices, int index, bool buy, vector<vector<int>> &memo)
{
    if(index == prices.size())
        return 0;

    if(memo[index][buy] != -1)
        return memo[index][buy];

    int profit1 = 0;
    int profit2 = 0;
    if(buy)// if buy is 1 then can buy
    {
        int buy = -prices[index] + memoizationSolve(prices, index+1, 0, memo);

        int ignore = memoizationSolve(prices, index+1, 1, memo);
    
        profit1 = max(buy, ignore);
    }
    else
    {
        int sell = prices[index] + memoizationSolve(prices, index+1, 1, memo);

        int ignore = memoizationSolve(prices, index+1, 0, memo);

        profit2 = max(sell, ignore);
    }    
    return memo[index][buy] = max(profit1, profit2);
}
int memoization(vector<int>& prices)
{
    int n = prices.size();

    vector<vector<int> > memo(n, vector<int> (2, -1));

    int ans = memoizationSolve(prices, 0, 1, memo);
    return ans;
}

int tabulation(vector<int>& prices, int n)
{
    vector<vector<int>> tab(n+1, vector<int> (2, 0));
    for(int i=n-1; i>=0; i--)
    {
        for(int b=0; b<2; b++)
        {
            int profit1 = 0;
            int profit2 = 0;
            if(b == 1)// if buy is 1 then can buy
            {
                int buy = -prices[i] + tab[i+1][0];

                int ignore = tab[i+1][1];
                
                profit1 = max(buy, ignore);
            }
            else
            {
                int sell = prices[i] + tab[i+1][1];

                int ignore = tab[i+1][0];

                profit2 = max(sell, ignore);
            }
            tab[i][b] = max(profit1, profit2);
        }
    }

    return tab[0][1];
}

int optimized(vector<int>& prices, int n)
{
    // vector<vector<int>> tab(n+1, vector<int> (2, 0));
    vector<int> curr(2,0);
    vector<int> next(2,0);

    for(int i=n-1; i>=0; i--)
    {
        for(int b=0; b<2; b++)
        {
            int profit1 = 0;
            int profit2 = 0;
            if(b == 1)// if buy is 1 then can buy
            {
                int buy = -prices[i] + next[0];
                int ignore = next[1];
                profit1 = max(buy, ignore);
            }
            else
            {
                int sell = prices[i] + next[1];
                int ignore = next[0];
                profit2 = max(sell, ignore);
            }
            curr[b] = max(profit1, profit2);
        }
            next = curr;
    }
    return curr[1];
    
}

int main(){

}