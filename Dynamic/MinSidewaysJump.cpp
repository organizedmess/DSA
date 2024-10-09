#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int Memoization(vector<int> &obstacles, int currPos, int currLane, vector<vector<int> > &memo)
{   
    int n = obstacles.size()-1;
    if(currPos == n)
    {
        return 0;
    }
    if(memo[currPos][currLane] != -1){
        return memo[currPos][currLane];
    }
    if(obstacles[currPos+1] != currLane)//obstacle does not lie in our current path so we go straight forward
    {
        return Memoization(obstacles, currPos+1, currLane, memo);
    }
    else//there is an obstacle in our current path, hence we jump
    {   
        int mini = INT_MAX;
        for(int i=1; i<=3; i++)
        {
            if(currLane != i && obstacles[currPos] != i)//avoiding jumping to path we are already at 
            {   
                mini = min(mini, 1 + Memoization(obstacles, currPos, i, memo));
            }
        }
        memo[currPos][currLane] = mini;
        return memo[currPos][currLane];
    }
}

int tabulation(vector<int>& obstacles,int n)
{
    vector<vector<int> > tab(4, vector<int> (n+1,INT_MAX));

    tab[0][n] = 0;
    tab[1][n] = 0;
    tab[2][n] = 0;
    tab[3][n] = 0;

    for(int j=n-1; j>=0; j--)//position
    {
        for(int i=1; i<=3; i++)//lane
        {
            if(obstacles[j+1] != i)
            {
                tab[i][j] = tab[i][j+1];
            }
            else
            {
                int jump = INT_MAX;
                for(int k=1;k<=3;k++)//lane 
                {
                    if(obstacles[j] != k && k != i)
                        jump = min(jump, 1 + tab[k][j+1]);//important to know why we put j+1 instead of j
                    
                }
                tab[i][j] = jump;
            }
        }
    }

    return min({ tab[1][0] + 1, tab[2][0], tab[3][0] + 1 });
}

int spaceOptimization(vector<int> &obstacles,int n)
{
    
    vector<int> curr(4,INT_MAX);
    vector<int> next(4,INT_MAX);

    next[0][n] = 0;
    next[1][n] = 0;
    next[2][n] = 0;
    next[3][n] = 0;

    for(int j=n-1; j>=0; j--)//position
    {
        for(int i=1; i<=3; i++)//lane
        {
            if(obstacles[j+1] != i)
            {
                curr[i] = next[i];
            }
            else
            {
                int jump = INT_MAX;
                for(int k=1;k<=3;k++)//lane 
                {
                    if(obstacles[j] != k && k != i)
                        jump = min(jump, 1 + next[k]);//important to know why we put j+1 instead of j
                    
                }
                curr[i] = jump;
            }
        }
        next = curr;
    }

    return min({ next[1] + 1, next[2], next[3] + 1 });
}

int main() 
{   
    vector<int>& obstacles;
    int n = obstacles.size()-1;
    vector<vector<int> > memo(n, vector<int> (4,-1));
    cout<<Memoization(obstacles, 0, 2, memo);

    return 0;
}
