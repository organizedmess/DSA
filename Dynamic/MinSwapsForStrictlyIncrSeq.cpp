#include<bits/stdc++.h>
using namespace std;

int memoizationSolve(vector<int>& nums1, vector<int>& nums2, int ptr, bool swapped, vector<vector<int> > &memo)
{
    if(ptr == nums1.size())
        return 0;

    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
        
    int prev1 = nums1[ptr - 1];
    int prev2 = nums2[ptr - 1];

    if(swapped==true)
        swap(prev1, prev2);
        

    if(memo[ptr][swapped] != -1)
        return memo[ptr][swapped];
        
        //no swap 
    if(nums1[ptr] > prev1 && nums2[ptr] > prev2)
        ans1 = memoizationSolve(nums1, nums2, ptr+1, 0, memo);
        

        //swap
    if(nums1[ptr] > prev2 && nums2[ptr] > prev1)
        ans2 = 1 + memoizationSolve(nums1, nums2, ptr+1, 1, memo);
        

    return memo[ptr][swapped] = min(ans1, ans2);

}
int memoization(vector<int>& nums1, vector<int>& nums2)
{   
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);

    int n = nums1.size();
    vector<vector<int> > memo(n+1, vector<int> (2,-1));

    return memoizationSolve(nums1, nums2, 1, 0, memo);
}

int tabulation(vector<int>& nums1, vector<int>& nums2, int n)
{
    vector<vector<int> > tab(n+1, vector<int> (2, 0));

    tab[n-1][0] = 0;
    tab[n-1][1] = 1;

    for(int ptr=n-1; ptr>=1; ptr--)
    {
        for(int b=0; b<2; b++)
        {
            int ans1 = INT_MAX;
            int ans2 = INT_MAX;
                    
            int prev1 = nums1[ptr - 1];
            int prev2 = nums2[ptr - 1];

            if(b==true)
                swap(prev1, prev2);
                    
            //no swap 
            if(nums1[ptr] > prev1 && nums2[ptr] > prev2)
                ans1 = tab[ptr+1][0];
                    

            //swap
            if(nums1[ptr] > prev2 && nums2[ptr] > prev1)
                ans2 = 1 + tab[ptr+1][1];

            tab[ptr][b] = min(ans1, ans2);
        }
    }
    return tab[1][0];// '1' because nums1[0] == -1, 
                    //  '0' because our '1' index wont swap becoz '0' index is -1
}

int optimized(vector<int>& nums1, vector<int>& nums2, int n)
{
    // vector<vector<int> > tab(n+1, vector<int> (2, 0));
    int noSwap = 0;
    int Swap=0;

    int currNoSwap = 0;
    int currSwap = 0;

    for(int ptr=n-1; ptr>=1; ptr--)
    {
        for(int b=0; b<2; b++)
        {
            int ans1 = INT_MAX;
            int ans2 = INT_MAX;
                    
            int prev1 = nums1[ptr - 1];
            int prev2 = nums2[ptr - 1];

            if(b==1)
                swap(prev1, prev2);
                    
            //no swap 
            if(nums1[ptr] > prev1 && nums2[ptr] > prev2)
                ans1 = noSwap; 
                    

            //swap
            if(nums1[ptr] > prev2 && nums2[ptr] > prev1)
                ans2 = 1 + Swap;

            int ans = min(ans1, ans2);

            if(b==1)
            {
                currSwap = ans;
            }
            else
            {
                currNoSwap = ans;
            }
        }
        Swap = currSwap;
        noSwap = currNoSwap;
    }
    return min(Swap, noSwap);
}

int main()
{

   
}