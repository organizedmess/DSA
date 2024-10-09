#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(vector<int> &arr, map<pair<int,int>,int>&maxi, int left, int right, vector<vector<int> > &memo)
{
    if(left == right)
        return 0;
    
    if(memo[left][right] != -1){
        return memo[left][right];
    }

    int ans = INT_MAX;
    for(int k=left; k<right; k++)
    {
        ans = min(ans, maxi[{left, k}]*maxi[{k+1, right}] + memoizationSolve(arr, maxi, left, k, memo) + memoizationSolve(arr, maxi, k+1, right, memo));
    }
    return memo[left][right] = ans;
}
int memoization(vector<int>& arr)
{
    map< pair<int, int>, int> maxi;

    vector<vector<int> > memo(arr.size()+1, vector<int> (arr.size()+1, -1));

    for(int i=0; i<arr.size(); i++)
    {
        maxi[{i, i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++)
        {
            maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }
    return memoizationSolve(arr, maxi, 0, arr.size()-1, memo); 
}

int main()
{

}