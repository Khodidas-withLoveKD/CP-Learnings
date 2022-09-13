#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main(){

    vector<int> vect(101);
    iota(vect.begin(), vect.end(), 0);

    for(int n : vect)
        cout<<n<<" ";
}
