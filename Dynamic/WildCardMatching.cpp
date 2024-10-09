#include<bits/stdc++.h>
using namespace std;

bool memoizationSolve(string &s, string &p, int i, int j, vector<vector<int>> &memo)
{

        if(i < 0 && j < 0)
        {
            return true;
        }
        if(i >= 0 && j < 0)//pattern ended but string didn't
        {
            return false;
        }

        if(i < 0 && j >= 0)//string ended but pattern didn't
        {
            for(int k=0; k<=j; k++)
            {
                if(p[k] != '*')//we cant delete characters so if the residual character is not '*'
                {             //then we are certain that the string wont match
                    return false;
                }
            }
            return true;
        }

        if(memo[i][j] != -1)
        {
            return memo[i][j];
        }

        if(s[i] == p[j] || p[j] == '?')
        {
            return memo[i][j] = memoizationSolve(s, p, i-1, j-1, memo);
        }
        else if(p[j] == '*')
        {
            return memo[i][j] = (memoizationSolve(s, p, i, j-1, memo) || memoizationSolve(s, p, i-1, j, memo));
        }
        else
        {
            return memo[i][j] = false;
        }
}
bool memoization(string s, string p)
    {   
        vector<vector<int> > memo(s.length()+1, vector<int> (p.length()+1, -1));

        return memoizationSolve(s, p, s.length(), p.length(), memo);
    }

bool tabulation(string &s, string &p)
    {
        vector<vector<int> > tab(s.length()+1, vector<int> (p.length()+1, 0));//becz we access 'i-1', 'j-1' thats why we converted it to 1 based indexing 
        tab[0][0] = true;
    
        for(int j=1; j<=p.length(); j++)
        {   
            bool flag = true;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*')// all the blocks without '*' will be marked false
                {
                    flag = false;
                    break;
                }
            }
            tab[0][j] = flag;// string ended but pattern didn't
        }

        for(int i=1; i<=s.length(); i++)
        {
            for(int j=1; j<=p.length(); j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    tab[i][j] = tab[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    tab[i][j] = ( tab[i][j-1] || tab[i-1][j] );
                }
                else
                {
                    tab[i][j] = false;
                }
            }
        }
        return tab[s.length()][p.length()];
    }

int main(){

    return 0;
}