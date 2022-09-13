#include <iostream>
#include <iterator>
#include <list>
#include <queue>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;

public:

    Graph(int v);
    void addEdge(int v, int w);
    void BFS(int v);

};

Graph::Graph(int v){

    this->v=v;
    adj = new list<int> [v];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    bool *visited=new bool[v];

    for(int i=0;i<v;i++){
        visited[i]=false;
        cout<<"V = "<<v<<endl;
    }

    visited[s]=true;
    //trying to remmove 2,3;
    //adj[2].remove(3);
    queue <int> q;
    q.push(s);

    while(!q.empty()){

        int po=q.front();
        q.pop();
        cout<<po<<" ";

        list<int> :: iterator it;

        for(it = adj[po].begin(); it != adj[po].end(); it++){
            if(!visited[*it]){
                visited[*it]=true;
                q.push(*it);
            }
        }

    }

}
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
