#include<bits/stdc++.h>
using namespace std;

static bool comp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1]; // sort in descending order based on height
    }
    return a[0] < b[0]; // sort in ascending order based on width
}

int BinarySearch_LCI(int n, vector<vector<int>> &nums)// binary search becoz of 'lower_bound' 
{
    
    if(n==0) // when the size of the vector is 0
        return 0;

    vector<int> ans;
    ans.push_back(nums[0][1]);

    for (int i = 1; i < n; i++)
    {
        if(nums[i][1] > ans.back())
        {
            ans.push_back(nums[i][1]);
        }
        else
        {
            int index=lower_bound(ans.begin(),ans.end(),nums[i][1])-ans.begin() ;
            ans[index]=nums[i][1];
        }
    }
    return ans.size();   
}
int maxEnvelopes(vector<vector<int>>& envelopes)
{
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(),comp);
    return BinarySearch_LCI(n, envelopes);
}

int main()
{
    maxEnvelopes();
}