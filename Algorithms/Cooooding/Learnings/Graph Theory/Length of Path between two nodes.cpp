#include <iostream>
#include <iterator>
#include <queue>
#include <algorithm>
#include <list>
#include <cstring>
#define pb(a) push_back(a)

using namespace std;

class Graph{

    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int s, int d);
    void BFS(int s);
};

Graph :: Graph(int V){

    this->V = V;
    adj = new list<int> [V];
}

void Graph :: addEdge(int s, int d){

    adj[s].pb(d);
    adj[d].pb(s);
}

void Graph :: BFS(int s){

    int dis[V];
    memset(dis,-1,sizeof(dis));

    queue<int> q;

    dis[s] = 0;
    q.push(s);

    while(!q.empty()){

        int node = q.front();
        q.pop();

        list<int> :: iterator it;

        for(it = adj[node].begin(); it != adj[node].end(); it++){

           if(dis[*it] == -1){

                q.push(*it);
                dis[*it] = dis[node] + 1;
           }

        }
    }
    //All nodes traversed, now finding the max dist
    int maxDis = 0;
    for(int i = 0; i<V; i++){
        if(dis[i]>maxDis)
            maxDis = dis[i];
    }
    cout<<"MAx dist = "<<maxDis<<endl;
}

int main()
{
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 9);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);

    g.BFS(5);
}
