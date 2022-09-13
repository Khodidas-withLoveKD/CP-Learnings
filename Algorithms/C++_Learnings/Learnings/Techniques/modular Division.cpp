#include <iostream>
#include <stdint.h>
#include <cmath>
using namespace std;

int main(){
    uint64_t a,b,c,ans,m;
    cout<<"sizeof(ulli) = "<<sizeof(uint64_t)<<"\n";

    a = 145785635595363569532135132;
    b = 3151635135413512165131321321;
    c = 999874455222222200651351351;
    m = 1000000007;
    ans = a*b*c;
    cout<<"a*b*c = "<<ans<<"\n";
    ans = (a*b*c)%m;
    cout<<"(a*b*c)%m = "<<ans<<"\n";
    ans = ((((a%m)*b)%m)*c)%m;
    cout<<"((((a%m)*b)%m)*c)%m = "<<ans<<"\n";
}
