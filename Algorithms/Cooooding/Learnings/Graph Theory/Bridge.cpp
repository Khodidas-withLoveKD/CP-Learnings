#include <iostream>
#include <list>
#include <cstring>

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define NIL -1

using namespace std;

class Graph{
    int V;
    list<int>* adj;
    void bridgeUtil(int u, bool visited[], int parent[], int discTime[], int low[]);
public:
    Graph(int V);
    void addEdge(int s, int d);
    void findBridge();
};

Graph :: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int s, int d){
    adj[s].pb(d);
    adj[d].pb(s);
}
void Graph :: bridgeUtil(int u, bool visited[], int parent[], int discTime[], int low[]){
    static int time = 0;
    visited[u] = true;
    discTime[u] = low[u] = ++time;
    list<int> :: iterator it;
    for(it = adj[u].begin(); it != adj[u].end(); it++){
        int v = *it;
        if(!visited[v]){
            parent[v] = u;
            bridgeUtil(v, visited, parent, discTime, low);
            low[u] = min(low[u],low[v]);

            // it is a bridge when
            if(low[v] > discTime[u])
                cout<<u<<" - "<<v<<endl;
        }
        else if(v != parent[u])
            low[u] = min(low[u], discTime[v]);
    }

}
void Graph :: findBridge(){
    bool *visited = new bool[V];
    int *parent = new int[V];
    int *discTime = new int[V];
    int *low = new int[V];

    //initialize them
    memset(visited, false, V*sizeof(visited));
    memset(parent, NIL, V*sizeof(parent));

    FOR(i, 0, V)
        if(visited[i] == false)
            bridgeUtil(i, visited, parent, discTime, low);
}
int main(){
    // Create graphs given in above diagrams
    cout << "\nBridges in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.findBridge();

    cout << "\nBridges in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.findBridge();

    cout << "\nBridges in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.findBridge();

    cout << "\nBridges in fourth graph \n";
    Graph g4(2);
    g4.addEdge(0,1);
    g4.findBridge();
    return 0;
}
