#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, stack<int> &st, unordered_map<int,list<int>> &adj)
{
	visited[node] = 1;

	for(auto i: adj[node]){
		if(visited[i]==0)
			dfs(i,visited,st,adj);
	}
	st.push(node);	
}

void revDfs(int node,vector<bool> &visited,unordered_map<int,list<int>> &transpose)
{
	visited[node]=1;

	for(auto i:transpose[node])
	{
		if(visited[i]==0)
		{
			revDfs(i,visited,transpose);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{   
    // STEP 1 : FIND TOPOLOGICAL SORT
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}


	stack<int> st;
	vector<bool> visited(v,0);

	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			dfs(i,visited,st,adj);
		}
	}

	//by now stack st has toposort of the given graph
	// now we create transpose
    //STEP 2: CREATE A TRANSPOSE GRAPH
	unordered_map<int,list<int>> transpose;

	for(int i=0;i<v;i++)
	{	
		visited[i] = 0;//rebooting the visited array for further use
		for(auto nbr: adj[i])
		{
			transpose[nbr].push_back(i);
		}
	}
	//dfs call using the transpose 

    // STEP 3: CALL THE DFS FUNCTION ON THIS TRANSPOSE GRAPH
	int count = 0;
	while(!st.empty())
	{
		int top = st.top();//stack contains topological sort 
		st.pop();
		
		if(!visited[top])//every time we find an unvisited 'i' it is the 
		{//start of a component
			count++;
			revDfs(top,visited,transpose);
		}
	}
	
	return count;	
}

int main(){

    stronglyConnectedComponents();

    return 0;
}