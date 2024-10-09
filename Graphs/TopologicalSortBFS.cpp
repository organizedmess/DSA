#include <bits/stdc++.h> 
//KAHN ALGORITHM
vector<int> topologicalSortBFS(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int,list<int>> adj;
    
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
    
        adj[u].push_back(v);// creating adjacency list
    }

    vector<int> indegree(v);
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;// creating the indegree vector
        }
    }
    
    queue<int> q;
    //all the elements with '0' indegree are being pushed first
    for(int i=0;i<v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    //routine BFS with indegree
    vector<int> ans(v);
    int index =0;
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        ans[index++] = frontNode;
        
        for(auto i: adj[frontNode])
        {
            indegree[i]--;//the adjacent elements will have their degree reduced by 1
            if(indegree[i]==0)
            {//if any adjacent node's degree becomes 0
                q.push(i);
            }
        }
    }
    return ans;
}

int main(){

    topologicalSortBFS();
    return 0;
}