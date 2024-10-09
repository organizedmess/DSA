#include<bits/stdc++.h>
#include<algorithm>
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s,
                         int t)
{
  unordered_map<int, list<int>> adj;

  for (int i = 0; i < edges.size(); i++)
  {
	int u = edges[i].first;
	int v = edges[i].second;
  
	adj[u].push_back(v);
	adj[v].push_back(u);
  }

	vector<bool> visited(n+1);//n+1 fixed the runtime error
	vector<int> parentof(n+1);

	queue<int> q;
	q.push(s);
	parentof[s] = -1;
	visited[s] = 1;
    
    // filling parentof vector
	while(!q.empty())
	{
		int frontNode = q.front();
		q.pop();
		
		for(auto i : adj[frontNode])
		{	
			if(visited[i] == 0)
			{		
				q.push(i);
				visited[i] = 1;
				parentof[i] = frontNode;
			}	
		}
	}

    //now traversing through parentof array
	vector<int> ans;
	int currNode = t;
	ans.push_back(t);
	while(currNode != s)
	{
		currNode = parentof[currNode];
		ans.push_back(currNode);
	}

    // reversing the ans
	reverse(ans.begin(), ans.end());
	
	return ans;


}