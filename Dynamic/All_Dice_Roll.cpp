#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(int n,int k,int target,vector<vector<int> > &memo)
{
    if(n==0 && target!=0){
        return 0;
    }
    if(target<0){
        return 0;
    }
    if(target==0 && n!=0){
        return 0;
    }
    if(target==0 && n==0){
        return 1;
    }
        
    if(memo[n][target]!=-1)
        return memo[n][target];

    int count = 0;
    for(int i=1;i<=k;i++)
    {
        count = (count%mod + memoizationSolve(n-1, k, target-i,memo)%mod)%mod;
    }

    return memo[n][target] = count;

}
int memoization(int n, int k, int target)
{   
    vector<vector<int> > memo(n+1,vector<int> (target+1,-1));

    return memoizationSolve(n,k,target,memo);
}

int tabulation(int n, int k,int target)
{
    vector<vector<int> > tab(n+1, vector<int> (target+1,0));//0 here handles all the 'if' conditions of 
                                                           // the recursicve solution
    tab[0][0] = 1;

    for (int dice = 1; dice <= n; dice++)
    {
        for (int tar = 1; tar <= target; tar++)
        {
            int count = 0;
            for(int i=1;i<=k;i++)
            {
                if(tar - i >= 0)
                    count = (count%mod + tab[dice-1][tar-i]%mod)%mod;
            }
            tab[dice][tar]=count;
        }
    }

    return tab[n][target];
}
    
int spaceOptimization(int n, int k, int target)
{
    // vector<vector<int> > tab(n+1, vector<int> (target+1,0));//0 here handles all the 'if' conditions of 
                                                           // the recursicve solution
    vector<int> prev(target+1, 0); 
    vector<int> curr(target+1, 0);

    prev[0] = 1;

    for (int dice = 1; dice <= n; dice++)
    {
        for (int tar = 1; tar <= target; tar++)
        {
            int count = 0;
            for(int i=1;i<=k;i++)
            {
                if(tar - i >= 0)
                    count = (count%mod + prev[tar-i]%mod)%mod;
            }
            curr[tar]=count;
        }
        prev = curr;
    }

    return curr[target];
}

int main(){

}