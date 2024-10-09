#include <bits/stdc++.h> 

void solve(int node, vector<bool>&visited, unordered_map<int,list<int>> &adj
            ,stack<int> &s)
{
    visited[node] = 1;

    for(auto i: adj[node])
    {
        if(visited[i] == 0)
        {
            solve(i,visited,adj,s);
        }   
    }
    s.push(node);//as this is the last process 
                // the last number will be the first one to get inside
                //so by the end the numbers will get pushed in the reverse order
                //of them getting called 
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int,list<int>> adj;
    
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
    
        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> s;

    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {   
            solve(i,visited, adj, s);
        }
    }
    
    vector<int> ans;
    //reversing
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){

    system("cls");
    topologicalSort();
    return 0;
}
