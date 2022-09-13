#include <vector>
#include <iostream>
#include <algorithm>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define FOR(i,a,b) for(int i=a; i<b; i++)
using namespace std;

int main(){

    vector< pair< int, pair<int, int> > > vect;

    vect.pb(mp(10,mp(0,1)));
    vect.pb(mp(2,mp(20,1)));
    vect.pb(mp(3,mp(10,1)));
    vect.pb(mp(14,mp(1,1)));

    cout<<"----BEFORE-----\n";
    FOR(i,0,vect.size())
        cout<<"dist = "<<vect[i].first<<" | (X,Y) = "<<vect[i].second.first<<','<<vect[i].second.second<<endl;

    sort(vect.begin(),vect.end());

    cout<<"----AFTER-----\n";
    FOR(i,0,vect.size())
        cout<<"dist = "<<vect[i].first<<" | (X,Y) = "<<vect[i].second.first<<','<<vect[i].second.second<<endl;
}
