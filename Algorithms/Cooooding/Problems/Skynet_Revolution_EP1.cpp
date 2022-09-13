#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <iterator>

using namespace std;

class Graph
{
    int v,e;
    list<int> *adj,gate,*child;

    public:

        Graph(int v, int e);
        void addEdge(int v, int w);
        void delEdge(int v, int w);
        void BFS(int s,int *node1, int *node2);
        void addGateway(int v);
};

Graph::Graph(int v,int e){
    this->v = v;
    this->e = e;
    adj = new list<int> [v];
    child = new list<int> [v];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
   adj[w].push_back(v); //making it undirected graph
   //child[w].push_back(v); //adding child
}

void Graph::delEdge(int v,int w){
    adj[v].remove(w);
    adj[w].remove(v);
    //child[w].remove(v); //removing child
}

void Graph::addGateway(int v){
    gate.push_back(v);
    //adding children
    cout<<"inside Gateway"<<endl;
    list<int> :: iterator itc;
    for( itc = adj[v].begin(); itc != adj[v].end(); itc++){
            cout<<"inside GATEWWAY FOR"<<endl;
            cout<<"ITC = "<<*itc<<endl;
        child[v].push_back(*itc);
    cout<<"PUSHED"<<endl;
    }

}

void Graph::BFS(int s, int *node1, int *node2){

    //bool *visited = new bool[v];
    cout<<"inside BFS"<<endl;

    list <int> :: iterator skynet,gateway,itc;

    //if adjacent to skynet there is gateway
    for( skynet = adj[s].begin(); skynet != adj[s].end(); skynet++){
        for( gateway = gate.begin(); gateway != gate.end(); gateway++){
            cout<<"skynet = "<<*skynet<<" gateway = "<<*gateway<<endl;
            if( *skynet == *gateway){
                *node1 = *skynet;
                *node2 = *gateway;
                child[*gateway].remove(*node1);
                return ;
            }
        }
    }

    //else terminate one of the link to gateway
    for( gateway = gate.begin(); gateway != gate.end(); gateway++){
        if(!child[*gateway].empty()){
            cout<<"node1 = "<<*node1<<" gateway = "<<*gateway<<endl;
            *node1 = *child[*gateway].begin();
            *node2 = *gateway;
            child[*gateway].remove(*node1);
            return ;
        }
    }


    /*for(int i=0; i<v; i++)
        visited[i]=false;

    visited[s]=true;

    queue <int> q;
    q.push(s);

    while(!q.empty()){
        int po=q.front();
        q.pop();
        list <int> :: iterator it;

        for(it = adj[po].begin(); it != adj[po].end(); it++){
            if(!visited[*it]){
                visited[*it]=true;
               list<int> :: iterator itg;
                for( itg = gate.begin(); itg!= gate.end(); itg++){

                        if(*itg == *it){
                            *node1 = po;
                            *node2 = *it;
                            return ;
                        }
                    }
                q.push(*it);
            }
        }
    }*/

}
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    Graph g(N,E);
    for (int i = 0; i < L; i++) {
        cout<<"inside LLLLLLL"<<endl;

        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        g.addEdge(N1,N2);

    }
    for (int i = 0; i < E; i++) {
        cout<<"inside EEEEEE"<<endl;

        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        g.addGateway(EI);
    }

    // game loop
    while (1) {
        cout<<"inside While"<<endl;

        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        int node1,node2;
        g.BFS(SI,&node1, &node2);
        g.delEdge(node1,node2);
        cout << node1<< " " << node2<< endl;
    }
}


