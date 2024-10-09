#include<iostream>
using namespace std;

bool memoizationSolve(vector<int> &nums, int target, int ptr, vector<vector<int>> &memo)
{
    if(ptr >= nums.size()){
        return false;
    }
    if(target < 0){
        return false;
    }
    if(target == 0){
        return true;
    }

    if(memo[target][ptr] != -1){
        return memo[target][ptr];
    }

    int incl = memoizationSolve(nums, target-nums[ptr], ptr+1, memo);
    int excl = memoizationSolve(nums, target, ptr+1, memo);

    memo[target][ptr] = incl or excl;

    return memo[target][ptr];
}
bool memoization(vector<int>& nums)
{   
    int sum = 0;
    for(auto i: nums){
        sum += i;
    }

    if(sum%2 != 0)//checking if the sum is odd
        return false;
    
    sum = sum/2;
    vector<vector<int>> memo(sum+1,vector<int> (nums.size()+1,-1));

    return memoizationSolve(nums, sum, 0, memo);
}

bool tabulation(vector<int> &nums,int target)
{   
    int n = nums.size();
    vector<vector<bool> > tab(target+1, vector<bool> (n+1, 0));

    for(int index=0; index<=n; index++)
    {                       //irrespective of what index you are at
        tab[0][index] = true;  // if the target becomes 0 then flag that cell as true
    }

    for(int i=1; i<=target; i++)
    {
        for(int ptr=n-1; ptr>=0; ptr--)
        {
            bool incl = 0;
            if(i>=nums[ptr])
            {
                incl = tab[i-nums[ptr]][ptr+1];
            }
            bool excl = tab[i][ptr+1];

            tab[i][ptr] = incl or excl;
        }
    }
    return tab[target][0];
}

int main(){

    return 0;
}