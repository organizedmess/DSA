#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T> 

class graph{
    public:
    unordered_map<T ,list<T> > adj;

    void addEdge(T u,T v,bool direction){
        //direction = 0 : undirected
        //directoin = 1 : directed

        //Create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
        
    }
    void printList(){
        for(auto i: adj){
            cout<<i.first<<" -> ";
            for(auto j: i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main(){
    system("cls");
    int e;
    cout<<"enter the number of edges"<<endl;
    cin>>e;

    int ve;
    cout<<"enter the number of vertices"<<endl;
    cin>>ve;

    graph<int> g;

    for(int i = 0; i < e; i++)
    {
        int u,v;//value of vertices
        cin>> u >> v;
        //undirected
        g.addEdge(u, v, 0);
    }

    g.printList();
    
    return 0;
}