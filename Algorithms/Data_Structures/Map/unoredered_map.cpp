#include <iostream>
#include <unordered_map>
#include <iterator>
#include <string>

using namespace std;

void showMap( unordered_map<string, int> umap)
{
    unordered_map<string,int> :: iterator it;
    cout<<"---------\n";
    for(it = umap.begin(); it != umap.end(); it++)
        cout<<it->first<<'='<<it->second<<endl;
}

int main()
{
    //Unordered_map Not supported HERE
    unordered_map<string, int> umap;
    string str;
    int n=5;

    while(n--){
        cout<<"Enter fruit: ";
        cin>>str;

        if(umap.find(str) == umap.end())
            umap.insert(make_pair(str,1));
        else
            umap[str]++;

        showMap(umap);
    }
}
