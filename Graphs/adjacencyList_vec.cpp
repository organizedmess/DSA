#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> Adjacencymatrix(int n, int m, vector<vector<int>> & edges)
{
    vector<int> ans[n];//this means an array of n vectors
    
    for(int i=0;i<m;i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        
        ans[u].push_back(v); 
        ans[v].push_back(u); 
    }

    vector<vector<int> > adj(n);

    for(int i=0;i<n;i++)
    {
        adj[i].push_back(i); 

        for(int j=0;j<ans[i].size();j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main()
{   

    return 0;
}
