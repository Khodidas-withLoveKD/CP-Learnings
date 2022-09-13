#include <iostream>

using namespace std;

int main()
{
    static int n = 8;
    cout<<n-2<<endl;
    n = n -2;
    if (n != 0)
        main();
    return 0;
}
