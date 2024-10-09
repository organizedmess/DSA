#include<bits/stdc++.h>
using namespace std;

int recursion(int n,vector<int> &nums)
{   //we are going from right to left in the vector
    if(n==0)
        return nums[0];

    if(n<0)
        return 0;
                             
    int inclusion = recursion(n-2 ,nums) + nums[n];//we go two spaces left
    int exclusion = recursion(n-1 ,nums);//we go only one space left 

    int ans = max(inclusion, exclusion);

    return ans; 
}

int memoization(int n,vector<int> &nums,vector<int> &memo)
{
    if(n==0)
        return nums[0];
    
    if(n<0)
        return 0;

    if(memo[n] != -1)
        return memo[n];

    int inclusion = memoization(n-2,nums,memo) + nums[n];
    int exclusion = memoization(n-1,nums,memo);

    int ans = max(inclusion ,exclusion);

    memo[n] = ans;

    return memo[n];
}

int tabulation(vector<int> nums,vector<int> tab){
    int n = nums.size();

    tab[0]=nums[0];
    if(nums[0] > nums[1])
        tab[1] = tab[0];
    else
        tab[1] = nums[1];

    for(int i=2;i<n;i++)
    {
        tab[i] = max(tab[i-2]+nums[i], tab[i-1]);
    }
    return tab[n-1];
}

int spaceOptimization(vector<int> nums){
    int n = nums.size();

    int prev2=nums[0];
    int prev1;
    if(nums[0] > nums[1])
        prev1 = nums[0];
    else
        prev1 = nums[1];
    
    int curr;
    for(int i=2;i<n;i++)
    {
        curr = max(prev2+nums[i], prev1);
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{   
    system("cls");
    int n=9;

    vector<int> v={1,2,3,1,3,5,8,1,9}; 
    cout<<recursion(n,v)<<endl;
 
    vector<int> memo(n+1,-1);
    cout<<memoization(n,v,memo)<<endl;

    vector<int> tab(n+1,-1);
    cout<<tabulation(v,tab)<<endl;

    cout<<spaceOptimization(v);


    return 0;
}