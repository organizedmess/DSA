#include<bits/stdc++.h>
//we are using kahn's algo here 

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges)
{
    unordered_map<int,list<int>> adj;
    
    
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
    
        adj[u].push_back(v);
    }

    vector<int> indegree(n+1);
    for(auto i: adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;//indegree vector stores the indegree of all the nodes
        }
    }
    int count = 0;
    queue<int> q;
    //all the elements with '0' indegree are being pushed first
    for(int i=1;i<=n;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    //routine BFS with indegree
    while(!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        count++;//this is the only difference between kahn algo and this code
        
        for(auto i: adj[frontNode])
        {
            indegree[i]--;//the adjacent elements will have their degree reduced by 1
            if(indegree[i]==0)
            {//if any adjacent node's degree becomes 0
                q.push(i);
            }
        }
    }
    if(count == n)//the no. of elements in a topological sort is similare to no. of vertices present 
    {
        return false;//since count == n, hence topological sort worked ensuring us that there is no cycle in this graph 
    }
    else
    {
        return true;// there was no correct topological sort for this graph hence proving that there is a cycle present 
    }

}

int main(){
    detectCycleInDirectedGraph();

    return 0;
}