#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#define pb push_back
using namespace std;

int main(){
    unordered_map <string, vector<string> > umap;
    umap["K"].pb("Khodidas");
    umap["K"].pb("POOJa");

    unordered_map <string, vector<string> > :: iterator it;
    for(it = umap.begin(); it != umap.end(); it++)
        cout<<"1 = "<<it->second[0];
}
