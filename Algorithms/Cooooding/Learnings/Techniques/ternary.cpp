#include <iostream>

using namespace std;

int main()
{
    int ans=0,n=10;

    (n>5&&ans==1)? (n=5,ans--) : (ans++,n++);

    cout<<n<<"  "<<ans;
}
