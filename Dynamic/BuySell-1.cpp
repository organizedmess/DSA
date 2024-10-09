#include<bits/stdc++.j>
using namespace std;

int maxProfit(vector<int>& prices)
{   
    int prft = 0;
    int mini = 0;
    int maxi = 0;
        
    for(int i=0; i<prices.size(); i++)
    {
        if(prices[i] < prices[mini])
        {
            mini = i;
        }  

        prft = max(prft, prices[i] - prices[mini]);
    }
    
    return prft;
}

int main(){
    maxProfit();
    return 0;
}