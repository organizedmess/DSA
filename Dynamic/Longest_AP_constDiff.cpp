#include<iostream> 
using namespace std;

int longestSubsequence(vector<int>& arr, int difference)
    {   
        unordered_map<int, int> dp;//
        int ans = 0;//length

        for(int i=0; i<arr.size(); i++)
        {
            int temp = arr[i] - difference;//'temp' is the previous element that of ap
            int tempAns = 0;//this represents the size of the ap until 

            // check if temp exists in the array
            // if it does save it in the 'tempAns'
            if(dp.count(temp))
                tempAns = dp[temp];

            dp[arr[i]] = 1 + tempAns;// '1' for the length for the current element + tempAns for all the previous elements that
                                    // exists of that ap

            ans = max(ans, dp[arr[i]]);//ans compares and saves the max length of ap so far
        }

        return ans;
    }


int main()
{
    longestSubsequence(arr, diff);

}