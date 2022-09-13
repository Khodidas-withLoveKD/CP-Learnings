#include <iostream>
//#include <chrono>
using namespace std;
//using namespace std::chrono;
int main()
{
    int test,x,y,g,r;
    //char light='g';

    cin>>test;

    for(int t=0;t<test;t++)
    {
        cin>>x>>g>>y>>r; cin.ignore();

        x=x%(g+y+r);

        if(x<g)
            cout<<"GREEN"<<endl;
        else if(x<g+y)
            cout<<"YELLOW"<<endl;
        else
            cout<<"RED"<<endl;
    }
         //auto start = high_resolution_clock::now();

  /*       auto stop = high_resolution_clock::now();
         auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
*/


}
