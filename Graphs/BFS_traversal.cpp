#include <bits/stdc++.h> 

void prepareAdjucency(unordered_map<int,set<int>> &adj, vector<pair<int,int>> &edges)
{   
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }

}

void prepareBfs(unordered_map<int,bool> &visited, unordered_map<int, set<int> >adj,vector<int> &result,int node)
{   
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        result.push_back(frontnode);

        for(auto i: adj[frontnode])
        {//we are sending the nodes one by one so that if there are disconnected
        //nodes they are also considered 
          if(visited[i] == 0)
          {
            q.push(i);
            visited[i] = 1;
          } 
          
        }

    }

}

vector<int> BFS(int vertex, vector<pair<int,int>> edges)
{   
    unordered_map<int,set<int>> adj;
    vector<int> result;
    unordered_map<int,bool> visited;

    prepareAdjucency(adj,edges);

    for(int i=0;i<vertex;i++)
    {
        if(visited[i] == 0)
            {
                prepareBfs(visited,adj,result,i);
            }          
    }
    return result;

}

int main(){
    int vertex;
    vector<pair<int,int>> edges;

    BFS(v,edges);
    return 0;
}