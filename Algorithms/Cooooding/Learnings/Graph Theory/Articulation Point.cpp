#include <iostream>
#include <list>
#define NIL -1
#define pb(a) push_back(a)

using namespace std;

class Graph{
    int V;
    list<int>* adj;
    void APUtil(int u, bool visited[], int parent[], int discTime[], int low[], bool ap[]);
public:
    Graph(int V);
    void addEdge(int s, int d);
    void findAP();
};

Graph :: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int s, int d){
    adj[s].pb(d);
    adj[d].pb(s);
}

void Graph :: APUtil(int u, bool visited[], int parent[], int discTime[], int low[], bool ap[]){

    //timer
    static int time = 0;
    //mark the visited as true
    visited[u] = true;
    int children = 0;
    //mark the discovery time
    discTime[u] = low[u] = ++time;

    list<int> :: iterator it;
    for(it = adj[u].begin(); it != adj[u].end(); it++){
        int v = *it;    //v is the adjacent vertex of u

        if(!visited[v]){
            parent[v] = u;
            children++;
            APUtil(v, visited, parent, discTime ,low, ap);

            //check if the subtree of v has a connection
            //to any of the ancestors of u
            //in other words, checking if there is a
            //shorter path to reach that subtree vertex
            //than current path
            low[u] = min(low[u], low[v]);

            //u is an articulation point in(any one of) the following cases

            //1. if parent of u is NIL and has at least 2 children
            if(parent[u] == NIL && children > 1)
                ap[u] = true;

            //2. if parent is not NIL and subtree of v has
            //a conection to ancestor of u
            //in other words, v is farther than u and
            //the shortest distance to v is via u
            else if(parent[u] != NIL && low[v] >= discTime[u])
                ap[u] = true;
        }
        //to prevent backtracking to parent node
        else if (v != parent[u]){
            //check if u is reachable via v in shorter time
            low[u] = min(low[u], discTime[v]);
        }
    }
}
void Graph :: findAP(){
    bool *visited = new bool[V];
    int *parent = new int[V];
    int *discTime = new int[V];
    //low[v] represents the earliest visited vertex reachable from subtree of v
    int *low = new int[V];
    bool *ap = new bool[V];

    //initialize all of them
    for(int i = 0; i < V; i++){
        visited[i] = false;
        parent[i] = NIL;
        ap[i] = false;
    }
    //in case the graph is diconnected check for every Vertex
    for(int i=0; i < V; i++)
        if(visited[i] == false)
            APUtil(i, visited, parent, discTime, low, ap);

    for(int i=0; i < V; i++)
        if(ap[i] == true)
            cout<<i<<' ';

}
int main(){
    cout << "\nArticulation points in first graph \n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.findAP();

    cout << "\n\nArticulation points in second graph \n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.findAP();

    cout << "\n\nArticulation points in third graph \n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.findAP();
}
