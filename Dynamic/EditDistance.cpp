#include<bits/stdc++.h>
using namespace std;

    int memoization(string &word1, string &word2, int i, int j, vector<vector<int> > &memo)
    {
        if(i == word1.length())
            return word2.length() - j;

        if(j == word2.length())
            return word1.length() - i;

        if(memo[i][j] != -1){
            return memo[i][j];
        }

        int ans = 0;
        if(word1[i] == word2[j])
        {
            return memoization(word1, word2, i+1, j+1, memo);
        }
        else
        {
            int insertAns = 1 + memoization(word1, word2, i, j+1, memo);
            int DeleteAns = 1 + memoization(word1, word2, i+1, j, memo);
            int replaceAns = 1 + memoization(word1, word2, i+1, j+1, memo);

            ans = min({insertAns, DeleteAns, replaceAns});
        } 
        return memo[i][j] = ans;
    }

    int tabulation(string word1, string word2)
    {
        vector<vector<int> > tab(word1.size()+1, vector<int> (word2.size()+1, 0));

        for(int x=0; x<word2.length(); x++)
        {
            tab[word1.length()][x] = word2.length() - x;
        }

        for(int x=0; x<word1.length(); x++)
        {
            tab[x][word2.length()] = word1.length() - x;
        }

        for(int i=word1.size()-1; i>=0; i--)
        {
            for(int j=word2.size()-1; j>=0; j--)
            {
                int ans = 0;
                if(word1[i] == word2[j])
                {
                    tab[i][j] = tab[i+1][j+1];
                }
                else
                {
                    int insertAns = 1 + tab[i][j+1];
                    int DeleteAns = 1 + tab[i+1][j];
                    int replaceAns = 1 + tab[i+1][j+1];

                    ans = min({insertAns, DeleteAns, replaceAns});
                    
                    tab[i][j] = ans;
                }
            }
        }
        return tab[0][0];
    }

    int main(){

    }