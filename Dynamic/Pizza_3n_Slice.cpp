#include<bits/stdc++.h>
using namespace std;


int memoizationSolve(vector<int> &slices, int endIndex, int index, int size, vector<vector<int> > &memo)
{
    if( size == 0 || index > endIndex )
        return 0;
    
    if(memo[index][size] != -1)
        return memo[index][size];
    
    int include = slices[index] + memoizationSolve(slices, endIndex, index+2, size-1, memo);

    int exclude = memoizationSolve(slices, endIndex, index+1, size, memo);

    memo[index][size] = max(include, exclude);

    return memo[index][size];
}   
int memoization(vector<int>& slices)
{   
    int k= slices.size(); 
    vector<vector<int> > memo1(k+1,vector<int> (k,-1));
    int ans1= memoizationSolve(slices, k-2, 0, k/3,memo1);

    vector<vector<int> > memo2(k+1,vector<int> (k,-1));
    int ans2= memoizationSolve(slices, k-1, 1, k/3,memo2);

    return max(ans1, ans2);

}

int tabulation(vector<int>& slices){

    int n = slices.size();
    vector<vector<int> > tab1(n+2, vector<int>(n+2, 0));

    for(int i=n-2; i>=0; i--)
    {
        for(int size=1; size<=n/3; size++)
        {
            int include = slices[i] + tab1[i+2][size-1];
            int exclude = tab1[i+1][size];
            tab1[i][size] = max(include, exclude);
        }
    }

    vector<vector<int> > tab2(n+2, vector<int>(n+2, 0));

    for(int i=n-1; i>=1; i--)
    {
        for(int size=1; size<=n/3; size++)
        {
            int include = slices[i] + tab2[i+2][size-1];
            int exclude = tab2[i+1][size];
            tab2[i][size] = max(include, exclude);
        }
    }

    return max(tab1[0][n/3],tab2[1][n/3]);
}

int spaceOptimization(vector<int>& slices){

    int n = slices.size();
    
    //case 1
    vector<int> prev1(n+2,0);
    vector<int> curr1(n+2,0);//represents the case where we dont eat
    vector<int> next1(n+2,0);//represents the case where we do eat

    for(int i=n-2; i>=0; i--)
    {
        for(int size=1; size<=n/3; size++)
        {
            int include = slices[i] + next1[size-1];
            int exclude = curr1[size];
            prev1[size] = max(include, exclude);
        }
        next1=curr1;
        curr1=prev1;
    }

    //case 2
    vector<int> prev2(n+2,0);
    vector<int> curr2(n+2,0);
    vector<int> next2(n+2,0);


    for(int i=n-1; i>=1; i--)
    {
        for(int size=1; size<=n/3; size++)
        {
            int include = slices[i] + next2[size-1];
            int exclude = curr2[size];
            prev2[size] = max(include, exclude);
        }
        next2=curr2;
        curr2=prev2;
    }

    return max(curr1[n/3],curr2[n/3]);
}

int main()
{
    
}