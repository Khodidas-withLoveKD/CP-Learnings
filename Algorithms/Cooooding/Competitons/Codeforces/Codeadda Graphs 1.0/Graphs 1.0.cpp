#include <bits/stdc++.h>
#define ll long long
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define FOR(i,a,b) for(int i=a;i<b; i++)

using namespace std;

class Graph{

  int v;
  list<int> *adj;
  bool *visited;

public: 
  Graph(int v);
  void addEdge(int n, int m);
  void traverse(int n);
};

Graph::Graph(int v){

  this->v=v;
  adj = new list<int> [v];
  visited = new bool [v];
}

void Graph::addEdge(int n, int m){

  adj[n].pb(m);
}
void Graph::traverse(int s){

  bool flag=true;
  int counter;
   
   list<int> :: iterator a,b,c;

   FOR(i,s,v){

    for(b = adj[i].begin(); b != adj[i].end(); b++){ 
        for( c = adj[*b].begin(); c != adj[*b].end(); c++){
          counter=0; 
          for( a = adj[i].begin(); a != adj[i].end(); a++){ cout<<"\n---------------------\nB = "<<*b+1<<endl;  cout<<"c = "<<*c+1<<endl;cout<<"A = "<<*a+1<<endl;
            if(*a == *c){
              flag=true;
              counter++;
              cout<<"BREAK"<<endl;
              break;
            }
          }
          if(counter == 0 && a == adj[i].end()){
            flag=false;
            cout<<"NO"<<endl;
            return ;
          }
        }
    }
   }

   if(flag == true)
      cout<<"YES"<<endl;
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif 

    ll n,m,val1,val2;
    cin>>n>>m; cin.ignore();

    Graph g(n);
    vector <int> vect;

    for(int i=0 ; i<m ;i++){
      cin>>val1>>val2; cin.ignore();
      val1--;
      val2--;

      g.addEdge(val1,val2);
    }

      g.traverse(0);
}
