#include<bits/stdc++.h>
using namespace std;

// Brute force approach
int solve(vector<int>& nums, int index, int diff)
    {
        if(index<0)
            return 0;

        int ans = 0;
        for(int j=index-1; j>=0; j--){  
            if(nums[index] - nums[j] == diff)
            {
                ans = max(ans, 1 + solve(nums, j, diff));
            }
        }
        return ans;//This represents the size of this ap
    }
int longestArithSeqLength(vector<int>& nums)
{
    if(nums.size() <= 2)
        return nums.size();

    int sizeOfAp = 0; 
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            int diff = nums[j] - nums[i];
            sizeOfAp = max(sizeOfAp, 2 + solve(nums, i, diff));
        }
    }
    return sizeOfAp;
}


//memoization
int memoizationSolve(vector<int>& nums, int index, int diff,vector<unordered_map<int,int> > &memo)
{
    if(index<0)
        return 0;

    if(memo[index].count(diff))
        return memo[index][diff];
        
    int ans = 0;

    for(int j=index-1; j>=0; j--)
    {  
        if(nums[index]-nums[j] == diff)
        ans = max(ans, 1 + memoizationSolve(nums, j, diff, memo));
    }
    return memo[index][diff] = ans;//This represents the size of this arithmetic progression
}
int memoiazation(vector<int>& nums)
{
    int n = nums.size();
    if(nums.size() <= 2)
        return nums.size();

    vector<unordered_map<int, int>> memo(n+1);

    int sizeOfAp = 0; 
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            int diff = nums[j] - nums[i];
            sizeOfAp = max(sizeOfAp, 2 + memoizationSolve(nums, i, diff, memo));
        }
    }
    return sizeOfAp;
}


//tabulation
int tabulation(vector<int>& nums)
{
    int n = nums.size();
    if(nums.size() <= 2)
        return nums.size();

    int ans = 0;
    unordered_map<int, int> tab[n+1];

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            int diff = nums[i] - nums[j];
            int cnt = 1;// size of the ap as of now because of 'i'

            if(tab[j].count(diff))
                cnt = tab[j][diff];// checking if we have this 
                                      //answer already stored in the 'tab' array

            tab[i][diff] = 1 + cnt;// 1 is for 'j' we already had i but now we also have 'j' 
            ans = max(ans, tab[i][diff]);
        }
    }
    return ans;
}

int main(){

}
