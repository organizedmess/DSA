#include<bits/stdtr1c++.h>
using namespace std;


 int solve(string &s, string &rev, int i, int j, vector<vector<int> > &memo)
    {
        if(s.length() == i || rev.length() == j){
            return 0;
        }

        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }

        int ans= 0;
        if(s[i] == rev[j]){
            ans = 1 + solve(s, rev, i+1, j+1, memo);
        }
        else
        {
            ans = max(solve(s, rev, i+1,j, memo), solve(s, rev, i, j+1, memo));
            memo[i][j] = ans ;
        }
        return ans;
    }

    int longestPalindromeSubseq(string s)
    {
        string rev = s;

        vector<vector<int> > memo(s.length()+1, vector<int> (s.length() + 1, -1));
        reverse(rev.begin(), rev.end());

        return solve(s, rev, 0, 0, memo);
    }
    
int main(){

}