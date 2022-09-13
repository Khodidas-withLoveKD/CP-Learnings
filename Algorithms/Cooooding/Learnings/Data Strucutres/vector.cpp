#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp(a,b) make_pair(a,b)

using namespace std;
int key_index;

bool finder( vector<pair <int, int> > &element){

//    return key_index == element.first;
}

/*bool key( vector <pair> > &element){
    return element == key_index;
}
*/
int main()
{

    key_index=3;
    vector<int> vc;
    vc.pb(10);
    vc.pb(20);
    cout<<"vc.at(1)"<<vc.at(1)<<"\n";

    //--------REMOVING AN ELEMENT FORM VECTOR PAIR---------
    vector <pair <int, int> > vect;

    for(int i=0, j=10; i<5; j--, i++)
        vect.pb(mp(i,j));

    for(int i=0; i< vect.size();i++){
        cout<<"vect["<<i<<"] = "<<vect[i].first<<','<<vect[i].second<<endl;
    }

    //vect.erase(find(vect.begin(),vect.end(),finder));
    //finding element
    for(int i=0; i< vect.size();i++){
        if(vect[i].first == key_index)
            vect.erase(vect.begin()+i);
    }
    for(int i=0; i< vect.size();i++){
        cout<<"vect["<<i<<"] = "<<vect[i].first<<','<<vect[i].second<<endl;
    }
}
