#include<bits/stdc++.h>
using namespace std;

int memoization(string &text1, string &text2, int i, int j, vector<vector<int> > &memo)
    {
        if(i==text1.size() || j==text2.size())
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];

        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + memoization(text1, text2, i+1, j+1, memo);
        }
        else
        {
            ans = max(memoization(text1, text2, i+1, j, memo), memoization(text1, text2, i, j+1, memo));
        }

        return memo[i][j] = ans;
    }

int tabulation(string text1, string text2)
    {
        vector<vector<int> > tab(text1.size()+1, vector<int> (text2.size()+1, 0));
        int n1 = text1.size()-1;
        int n2 = text2.size()-1;
        
        for(int i=n1; i>=0; i--)
        {
            for(int j=n2; j>=0; j--)
            {
                int ans = 0;
                if(text1[i] == text2[j]){
                    ans = 1 + tab[i+1][j+1];
                }
                else
                {                          
                    ans = max(tab[i+1][j] , tab[i][j+1]);
                }
                tab[i][j] = ans;
            }
        }
        return tab[0][0]; 
    }

int main()
{
    vector<vector<int> > memo(text1.size()+1, vector<int> (text2.size()+1, -1));
    // return recursion(text1, text2, 0, 0, memo);   
    return tabulation(text1, text2); 
}