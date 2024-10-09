#include<bits/stdc++.h>
using namespace std;

int Memoization(vector<int>& satisfaction, int ptr,int time, vector<vector<int> > &memo)
{
    if(ptr == satisfaction.size())
        return 0;

    if(memo[ptr][time] != -1){
        return memo[ptr][time];
    }

    int include = time*satisfaction[ptr] + Memoization(satisfaction, ptr+1, time+1,memo);

    int exclude = Memoization(satisfaction, ptr+1, time,memo);

    memo[ptr][time] = max(include, exclude);
    
    return memo[ptr][time];
}
int tabulation(vector<int>& satisfaction,int n)
{
        vector<vector<int> > tab(n+1, vector<int> (n+1,0));
        
        for(int ptr=n-1;ptr>=0;ptr--)
        {
            for(int time=ptr; time>=0; time--)
            {
                int include = (time+1)*satisfaction[ptr] + tab[ptr+1][time+1];
                int exclude = tab[ptr+1][time];
                tab[ptr][time] = max(include, exclude);  
            }
        }
        return tab[0][0]; 
}
int spaceOptimization(vector<int>& satisfaction,int n)
{
    vector<int> curr(n+1,0);
    vector<int> next(n+1,0);

        for(int ptr=n-1;ptr>=0;ptr--)
        {
            for(int time=ptr; time>=0; time--)
            {
                int include = (time+1)*satisfaction[ptr] + next[time+1];
                int exclude = next[time];
                curr[time] = max(include, exclude);  
            }
            next = curr;
        }
        return next[0]; 
}

int main(){
        system("cls");
        vector<int>& satisfaction;
        sort(satisfaction.begin(),satisfaction.end());//very important
        int n = satisfaction.size();

        vector<vector<int> > memo(n+1, vector<int> (n+1, -1));

        int result = recursion(satisfaction, 0, 1,memo);  
        return result;

    return 0;
}