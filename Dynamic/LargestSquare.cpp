#include<bits/stdc++.h>
using namespace std;

int rec(vector<vector<int>> &mat, int i,int j,int &maxi, vector<vector<int>> &dp)
{
    if( i>=mat.size() || j>=mat[0].size() )
    {
        return 0; 
    }    
        
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
        
    int right= rec(mat,i, j+1,maxi,dp);
    int down = rec(mat,i+1,j,maxi,dp);
    int diagonal = rec(mat,i+1,j+1,maxi,dp);
        
        
    if(mat[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(down, diagonal));// becoz minimum would be common in all the sides
        maxi =  max(maxi ,dp[i][j]);//comparing with the current max sqaure's side
        return dp[i][j];//returning ans becoz that is the lenght of the square we found down there
                    // wherever this value is returned they are expecting the size of square down here
    }
    else
    {
        return 0;
    }
        
}

int Tabulation(int n,int m, vector<vector<int>> &mat,int &maxi)
{
       
        vector<vector<int>> tab(n+1, vector<int>(m+1,0));
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=m-1;j>=0;j--)
            {   
                if(mat[i][j]==1)
                {
                    int ans =  1 + min( {tab[i+1][j], tab[i][j+1], tab[i+1][j+1]} );       
                    tab[i][j] = ans;
                    maxi = max(maxi ,ans);
                }
                else
                {
                    tab[i][j] = 0;
                }
            }
                    
        }
        return tab[0][0];
    }

int spaceOptimizedTabulation(int n,int m, vector<vector<int>> &mat,int &maxi)
{
        // vector<vector<int>> tab(n+1, vector<int>(m+1,0));
        vector<int> next(m+1,0);
        vector<int> curr(m+1,0);
        
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {   
            if(mat[i][j] == 1)
            {
                int ans =  1 + min( {next[j], curr[j+1], next[j+1]} );       
                curr[j] = ans;
                maxi = max(maxi ,ans);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return curr[0];
}
    
int main()
{
    system("cls");

    return 0;
}