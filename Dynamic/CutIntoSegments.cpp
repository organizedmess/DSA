#include<bits/stdc++.h>
#include<algorithm>
#include<limits.h>
using namespace std;

int memoizationSolve(int n,int x,int y,int z,vector<int> &memo)
{
	if(n==0){
		return 0;
	}
	if(n<0){
		return INT_MIN;  
		
	}
	
	if(memo[n]!=-1){
		return memo[n];
	}

	int ansx = solve(n-x,x,y,z,memo) + 1;
	int ansy = solve(n-y,x,y,z,memo) + 1;
	int ansz = solve(n-z,x,y,z,memo) + 1;

    int ans = max({ansx, ansy, ansz});
    memo[n]=ans;

	return memo[n];	
}
int memoization(int n, int x, int y, int z)
{	
	int count=0; 
	vector<int> memo(n+1,-1);
	int res = solve(n,x,y,z,memo);

	if(res<0)
	{
		return 0;
	}
	else
	{
		return res;
	}
}

int tabulation(int n, int x, int y, int z,vector<int> tab)
{
    tab[0]=0;

    for (int i = 1; i <= n; i++)
    {
		if(i-x >= 0)
        tab[i] = max(tab[i],tab[i-x]+1);

		if(i-y >= 0)
        tab[i] = max(tab[i],tab[i-y]+1);

		if(i-z >= 0)
        tab[i] = max(tab[i],tab[i-z]+1);

    }

    if(tab[n] < 0) return 0;
	else return tab[n];
}   

int main(){
    vector<int> tab(n+1,INT_MIN);
    tabulation();
    return 0;
}