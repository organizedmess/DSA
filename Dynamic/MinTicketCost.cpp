#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int recursionSolve(int n, vector<int> days, vector<int> cost, int validity)
{
    if(n>=days.size())
    {
        return 0;
    }
    if(validity >= days[n])
    {
        return solve(n+1,days,cost,validity);
    }
    else
    {
        //option 1: 1 day pass
        int pass1 = cost[0] + solve(n+1,days,cost,days[n]+0);
    
        //option 2: 7 days pass
        int pass7 = cost[1] + solve(n+1,days,cost,days[n]+6);
    
        //option 3: 30 days pass 
        int pass30 = cost[2] + solve(n+1,days,cost,days[n]+29);

        return min(pass1, min(pass7, pass30));
    }
} 
int recursion(int n, vector<int> days, vector<int> cost)
{   
    int validity=0;  
    int i = 0;
    int res=solve(i,days,cost,validity);  

    return res;
}

int memoizationSolve(int n, vector<int> days, vector<int> cost, int validity,vector<int> &memo)
{
    if(n>=days.size())
    {
        return 0;
    }

    if(validity >= days[n])
    {
        return solve(n+1,days,cost,validity,memo);
    }
    else if(memo[n]!=-1)
    {
        return memo[n];//it represents the minimum cost for holidays of n days of our choice 
    }
    else
    {
        //option 1: 1 day pass
        int pass1 = cost[0] + solve(n+1,days,cost,days[n]+0,memo);
    
        //option 2: 7 days pass
        int pass7 = cost[1] + solve(n+1,days,cost,days[n]+6,memo);
    
        //option 3: 30 days pass 
        int pass30 = cost[2] + solve(n+1,days,cost,days[n]+29,memo);

        memo[n] = min(pass1, min(pass7, pass30));
    }

    return memo[n];
} 
int memoization(int n, vector<int> days, vector<int> cost)
{   
    int validity=0;  
    int i=0;
    vector<int> memo(n+1,-1);

    int res=solve(i,days,cost,validity,memo);  

    return res;
}

int tabulationSolve(){

}
int tabulation(){
    
}

int main(){

    return 0;
}