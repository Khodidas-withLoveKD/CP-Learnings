#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

void addEdge(vector<int> adj[], int s, int d){
    adj[s].pb(d);
}
void DFSUtil(int s, vector<int> adj[], vector<bool> &visited){
    visited[s] = true;

    cout<<s<<" ";
    for(int i=0; i<adj[s].size(); i++)
        if(visited[adj[s][i]] == false)
            DFSUtil(adj[s][i], adj, visited);

}
void DFS(vector<int> adj[], int V, int s){
    vector<bool> visited(V, false);

    DFSUtil(s, adj, visited);
    //for(int i=0; i<V; i++)
        //if()
}
int main(){
    int V = 5, s = 0;
    vector<int> adj[5];

    //adding edges
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS(adj, V, s);
}
