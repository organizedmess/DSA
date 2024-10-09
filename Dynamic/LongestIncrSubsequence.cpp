#include<iostream>
#include<vector>
using namespace std;

int memoizationSolve(vector<int> &nums, int prev, int curr, vector<vector<int>> &memo)
{
    if(curr == nums.size())
        return 0;

    if(memo[curr][prev+1] != -1)
        return memo[curr][prev+1];
    
    int include = 0;
    int exclude = 0;
    
    if(prev == -1 || nums[prev] < nums[curr])//-1 becoz then it means that we are talking 
                                            //about the first element which must enter in 'include' at least once 
        include = 1 + memoizationSolve(nums, curr, curr+1, memo);
    
    exclude = memoizationSolve(nums, prev, curr+1, memo);

    memo[curr][prev+1] = max(include, exclude);
    return memo[curr][prev+1];
}
int memoization(vector<int>& nums) 
{   
    int n = nums.size();
    vector<vector<int>> memo(n,vector<int>(n+1,-1));
    return memoizationSolve(nums, -1, 0, memo);
}

int tabulation(vector<int> &nums, int n)
{
    vector<vector<int>> tab(n+1,vector<int> (n+1,0));

    for(int curr= n-1; curr >= 0; curr--)
    {
       for(int prev = curr-1; prev>=-1; prev--)
       {
            int include = 0;
            int exclude = 0;
        
            if(prev == -1 || nums[prev] < nums[curr])
            {
                include = 1 + tab[curr+1][curr+1];
            } 

            exclude = tab[curr+1][prev+1];
            tab[curr][prev+1] = max(include, exclude);
            
        }
    }
    
    return tab[0][0];
}

int SpaceOptimized(vector<int> &nums, int n)
{
    // vector<vector<int>> tab(n+1,vector<int> (n+1,0));
    vector<int> prevRow(n+1,0);
    vector<int> currRow(n+1,0);

    for(int curr= n-1; curr >= 0; curr--)
    {
       for(int prev = curr-1; prev>=-1; prev--)
       {
            int include = 0;
            int exclude = 0;
        
            if(prev == -1 || nums[prev] < nums[curr])
            {
                include = 1 + currRow[curr+1];
            } 

            exclude = currRow[prev+1];
            prevRow[prev+1] = max(include, exclude);
            
        }
        currRow = prevRow;
    }
    
    return currRow[0];
}

int BinarySearch(int n, vector<int> &nums)// binary search becoz of 'lower_bound' 
{
    
    if(n==0) // when the size of the vector is 0
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
        }
        else{
            //this will find us the index of the number which is just bigger than nums[i] inside 
            // ans.begin() to ans.end()

            //lower bound gives us the element's numeric value        // we are subtracting to find the index 
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin() ;
            ans[index] = nums[i];
        }
    }
    return ans.size();   
}

int main()
{
    system("cls");


}