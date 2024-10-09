#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(vector<int>& prices, int index, int fee, bool buy, vector<vector<int>> &memo)
{
    if(index == prices.size())
        return 0;

    if(memo[index][buy] != -1)
        return memo[index][buy];

    int profit1 = 0;
    int profit2 = 0;
    if(buy)// if buy is 1 then can buy
    {
        int buy = -prices[index] + memoizationSolve(prices, index+1, fee, 0, memo);

        int ignore = memoizationSolve(prices, index+1, fee, 1, memo);
    
        profit1 = max(buy, ignore);
    }
    else
    {
        int sell = prices[index] - fee + memoizationSolve(prices, index+1, fee, 1, memo);

        int ignore = memoizationSolve(prices, index+1, fee, 0, memo);

        profit2 = max(sell, ignore);
    }    
    return memo[index][buy] = max(profit1, profit2);
}
int memoization(vector<int>& prices, int fee)
{
    int n = prices.size();
    vector<vector<int> > memo(n, vector<int> (2, -1));
    int ans = memoizationSolve(prices, 0, fee, 1, memo);
    return ans;
}

int main(){
    
}