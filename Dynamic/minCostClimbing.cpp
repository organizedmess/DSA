#include<bits/stdc++.h>
using namespace std;


int recursionsolve(int n,vector<int> cost)
{
    if(n==0||n==1)
        return cost[n];
    
    return min(recursionsolve(n-1,cost),recursionsolve(n-2,cost)) + cost[n];
}
int recursion(vector<int>& cost) 
{
        int n = cost.size();

        return min(recursionsolve(n-1,cost),recursionsolve(n-2,cost));//minimum of (when we take 1 step , when we take 2 steps)
}


int memoizationsolve(int n, vector<int> cost, vector<int> &memo)
{
    if(n==1||n==0)
        return cost[n];

    if(memo[n] != -1)
        return memo[n];

    memo[n] = min(memoizationsolve(n-1,cost,memo), memoizationsolve(n-2,cost,memo)) + cost[n];//cost is added here because its lower than the target node and we will go above(go above in the sense of physical ladder) 
                                                                                             //hence their cost will be added 
    return memo[n];
}
int memoization(int n, vector<int> cost, vector<int> &memo)
{
    int ans = min(memoizationsolve(n-1, cost, memo) ,memoizationsolve(n-2, cost, memo)) ;// cost of target node wont be added as we dont have to go above that step

    return ans;
    
}

int tabulation(int n, vector<int> cost, vector<int> tab)
{
    tab[0] = cost[0];
    tab[1] = cost[1]; 

    for (int i = 2; i < n; i++)
    {
        tab[i] = min(tab[i-1] ,tab[i-2]) + cost[i];
    }
    
    return min(tab[n-2],tab[n-1]);//returning overall cost of reaching n-1 ,n-2
}

int spaceOptimization(int n,vector<int>& cost)
{

    int prevStair = cost[1];
    int secondprevStair = cost[0];
    int curr;
    for(int i=2; i<n; i++){
        curr = min(prevStair, secondprevStair) + cost[i];

        secondprevStair = prevStair;
        prevStair = curr;
    }
    return min(secondprevStair,prevStair);
}

int main(){
    system("cls");
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<recursion(cost)<<" ";

    int n = cost.size();
    vector<int> memo(n+1,-1);
    cout<<memoization(n, cost, memo)<<" ";
    
    vector<int> tab(n+1);
    cout<<tabulation(n , cost, tab)<<" ";
    
    cout<<spaceOptimization(n, cost);
    return 0;
}