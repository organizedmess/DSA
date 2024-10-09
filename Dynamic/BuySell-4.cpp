#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(vector<int> &prices, int index, int k, int operation, vector<vector<int>> &memo){

        if(index == prices.size())
            return 0;

        if(2*k == operation)
            return 0;
        
        if(memo[index][operation] != -1)
                return memo[index][operation];

        int profit1=0;int profit2 = 0;
        if(operation%2==0)
        {
            int buy = -prices[index] + memoizationSolve(prices, index+1, k, operation+1, memo);
            int ignore = memoizationSolve(prices, index+1, k, operation, memo);
            profit1 = max(buy, ignore);
        }
        else
        {
            int sell = prices[index] + memoizationSolve(prices, index+1, k, operation+1, memo);
            int ignore = memoizationSolve(prices, index+1, k, operation, memo);
            profit2 = max(sell, ignore);
        }
        return memo[index][operation] = max(profit1, profit2);
    }
int memoization(int k, vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>> memo(n+1 ,vector<int> ((2*k)+1, -1));
    return memoizationSolve(prices, 0, k, 0, memo);
}

int tabulation(vector<int> &prices, int n, int k)
{
    vector<vector<int>> tab(n+1 ,vector<int> ((2*k)+1, 0));

    for(int i=n-1; i>=0; i--)
    {
        for(int op = 0; op <2*k; op++)
        {
            int profit1=0;int profit2 = 0;
            if(op%2==0)
            {
                int buy = -prices[i] + tab[i+1][op+1];
                int ignore = tab[i+1][op];
                profit1 = max(buy, ignore);
            }
            else
            {
                int sell = prices[i] + tab[i+1][op+1];
                int ignore = tab[i+1][op];
                profit2 = max(sell, ignore);
            }

            tab[i][op] = max(profit1, profit2);
        }
    }
    return tab[0][0];
    
}

int main(){

}