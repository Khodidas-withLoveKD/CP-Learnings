#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <queue>
#define pb(a) push_back(a)

using namespace std;

class Graph{

    list<int> *adj;
    vector<int> degree;

public:
    int V;
    Graph(int V);
    void addEdge(int s, int d);
    int rootOfMinimumHeightTree();
};

Graph :: Graph(int V){

    this->V = V;
    adj = new list<int> [V];

    for(int i=0; i < V; i++)
        degree.pb(0);
}
void Graph :: addEdge(int s, int d){
    adj[s].pb(d);
    adj[d].pb(s);
    degree[s]++;
    degree[d]++;
}
int Graph :: rootOfMinimumHeightTree(){

    queue <int> q;
    int po;

    for(int i=0; i < degree.size(); i++)
        if(degree[i] == 1)
            q.push(i);

    if( V%2 == 0)
        V++;

    //cout<<"Inside function\nV = "<<V<<endl;
    while(V > 2){

        list<int> :: iterator nv;
        V--;
        po = q.front();
        q.pop();

        degree[po]--;
        nv = adj[po].begin();
        degree[*nv]--;

        cout<<"NV = " <<*nv<<endl;
        if(degree[*nv] == 1)
            q.push(*nv);
    }
    while(!q.empty()){
        cout<<"\nNode = "<< q.front();
        q.pop();
    }
    return 5;
}
int main()
{
    /*int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int A;
        int B;
        cin >> A >> B; cin.ignore();
    }
    */
    Graph g(6);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(5, 4);
    int k = g.rootOfMinimumHeightTree();

}
