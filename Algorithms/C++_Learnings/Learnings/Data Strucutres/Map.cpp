#include <iostream>
#include <map>
#include <iterator>

using namespace std;

void showMap(map <int,int> m)
{
    map<int,int> :: iterator it;
    for(it = m.begin(); it != m.end() ; it++)
        cout<<it->first<<','<<it->second<<endl;
}

int main()
{
    map <int, int> m;

    for(int i=1,j=20; i <= 5 ;i++,j--){
        m.insert({ i,j });
    }
    //m.insert({ 2,22 }); //Same key value not allowed
    showMap(m);

    //map <int, int> m2(m.begin(),m.end());
    //cout<<"Map 2\n";
    //showMap(m2);

    //m.erase(m.begin(),m.find(3));
    //m.erase(4);
   // map<int,int> :: iterator it = m.find(4);
    m.insert({8,80});
    cout<<"\n-------\n";
    showMap(m);
    if(m.count(8))
        cout<<"Key = 8 is present\n";
    else
        cout<<"Key = 8 is NOT present\n";

    cout<<"\n";
    m[10] = 10;
    showMap(m);
    cout<<"\n m[9] = "<<m[9];
    showMap(m);




}
