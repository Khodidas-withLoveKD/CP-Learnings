#include <iostream>
#include <iterator>
#include <list>

using namespace std;

class Graph{

    int v;
    list<int> *adj;
    bool *visited;

    void DFStill(int v, bool visited[]);

public:
    Graph(int v);
    void addEdge(int s, int d);
    void DFS();
};

Graph::Graph(int v){

    this->v = v;
    adj = new list<int> [v];
    visited = new bool [v];
}

void Graph::addEdge(int s, int d){
    adj[s].push_back(d);
}

void Graph::DFStill (int v, bool visited[]){

    visited[v] = true;
    cout<< v<< " ";

    list<int> :: iterator it;

    for(it = adj[v].begin(); it != adj[v].end() ; it++){ cout<<"*it = "<<*it<<" | it = "<<&it<<"\n";
        if(!visited[*it])
            DFStill(*it, visited);
    }
}

void Graph:: DFS(){

    for(int i=0; i<v; i++)
        visited[i] = false;
    for(int i=0; i<v; i++)
     if(visited[i] == false)
        DFStill(i , visited);
}
int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 4);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS();
}
