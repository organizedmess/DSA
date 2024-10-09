#include <bits/stdc++.h> 

vector<int> dijkstra_using_set(vector<vector<int>> &vec, int v, int edges, int source){
    
    unordered_map<int,list<pair<int,int>> > adj;

    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wgt = vec[i][2];

        adj[u].push_back({v,wgt});
        adj[v].push_back({u,wgt});
    } 

    // creating distance vector and a set
    vector<int> dist(v,INT_MAX);
    set<pair<int,int>> st;// first int: wgt of the edge , second int: destination node  
    dist[source] = 0;
    st.insert(make_pair(0,source));//inserting the source and the distance from itself into the set

    while(!st.empty()){
        auto top = *(st.begin());// node with minimum distance from current node

        int nodeDist = top.first;//distance
        int topNode = top.second;// node it reaches

        st.erase(st.begin());// remove topNode

        for(auto nbr_top_node: adj[topNode])// i is not 'set' hence i.first and i.second represents different things
        {
            if(nbr_top_node.second + nodeDist < dist[nbr_top_node.first])// 
            {
                auto record = st.find(make_pair(dist[nbr_top_node.first], nbr_top_node.first)); // if the node is already present in the set then we need to remove it and insert the updated distance 
                if(record != st.end())//if not found set returns a pointer to st.end()
                    st.erase(record);
                
                dist[nbr_top_node.first] = nbr_top_node.second + nodeDist;
                st.insert(make_pair(dist[nbr_top_node.first], nbr_top_node.first));
            }
        }

    }

    return dist;
}

vector<int> dijkstra_using_pq(vector<vector<int>> &vec, int v, int edges, int source){
    unordered_map<int,list<pair<int, int>> > adj;
    // creating adjacency list
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int wgt = vec[i][2];

        adj[u].push_back({v,wgt});
        adj[v].push_back({u,wgt});
    }

    vector<int> dist(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, source});// distance is written first because we want priority queue to sort on distance's basis

    while(!pq.empty()){
        pair<int, int> topp = pq.top();
        int curr_dist = topp.first;
        int node     = topp.second;

        for(auto &it: adj[node]){
            int nbr = it.first;
            int edge_wgt = it.second;
            
            if(egde_wgt + curr_dist < dist[nbr]){
                dist[nbr] = edge_wgt + curr_dist;
                pq.push({dist[nbr], nbr});                
            }
        }
    }
    return dist;
}

int main(){
    dijkstra();
    return 0;
}
