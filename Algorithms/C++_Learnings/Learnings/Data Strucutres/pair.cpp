#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

using namespace std;
int key_index;
bool sortbysec( const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first>b.first;
}

bool key( pair<int, int> &element)
{
    return element.first == key_index;
}
int main()
{
    /*pair <string, int> p;
    pair <string, int> p2 ("KD",2);
    p= make_pair("KIRU", 1);

    cout<<"First = " <<p.first<<" Second = "<<p.second<<endl;
    cout<<"First = " <<p2.first<<" Second = "<<p2.second<<endl;
    */
    /*vector <pair <int, int> > vect;
    vect.pb(mp(1,10));
    vect.push_back(make_pair(2,20));

    for(int i=0;i<vect.size();i++)
        cout<<vect[i].first<< " "<<vect[i].second;
    */

    vector <pair <int, int> > vect;

    for(int j=1,i=20;j<=5; j++, i--)
        vect.pb(mp(j,i));

    cout<< "Before Sort\n";
    for (int i=0;i<vect.size();i++)
        cout<<vect[i].first<<" "<<vect[i].second<<endl;

    sort(vect.begin(),vect.end(),sortbysec);

    cout<< "After Sort\n";
    for (int i=0;i<vect.size();i++)
        cout<<vect[i].first<<" "<<vect[i].second<<endl;

        //vector <int> vect;
    /*for(int i=1;i<10;i++)
        vect.pb(i);*/

    vector< pair <int,int> > :: iterator it;
    key_index=3;
    it = find_if( vect.begin(), vect.end(), key);
    if(it != vect.end()){
        cout<<"element found at "<<it - vect.begin() <<"\n element is = "<< vect[it - vect.begin()].first <<endl;
    }
    else
        cout<<"Element not found \n";
}
