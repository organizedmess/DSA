#include <bits/stdc++.h> 
using namespace std;

int recursion(vector<int> &num,int tar,vector<int> &memo)
{
    if(tar==0)
        return 1;
    

    if(tar<0)
        return 0;
    

    if(memo[tar]!=-1)
        return memo[tar];
    

    int ways = 0;
    for (int i=0; i<num.size(); i++)
    {
      ways += recursion(num,tar-num[i],memo);
    }

    memo[tar] = ways;

    return memo[tar];
}

int tabulation(vector<int> &num,int target,vector<int> &memo)
{
    vector<int> tab(target+1,0);

    tab[0]=1;

    for(int i=1;i<=target; i++)
    {
        for(int j=0;j<num.size();j++)
        {   
            if(i >= num[j])
            tab[i] += tab[i - num[j]];
        }
    }
    return tab[target];
}

int main(){
    system("cls");
    int num;
    int tar;
    vector<int> memo(tar+1,-1);
    int ans = recursion(num,tar,memo);
    
    return ans;
}