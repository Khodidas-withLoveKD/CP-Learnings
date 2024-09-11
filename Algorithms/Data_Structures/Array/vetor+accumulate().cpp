#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    vector<int> vect;
    for(int i = 1; i<11; i++)
        vect.push_back(i);
    int high = 11, low = 1;
    cout<<"sum from "<<low+1<<" to "<<high-1<<" = "<<accumulate(vect.begin() + low, vect.begin() + high, 0);
}
