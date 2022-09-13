#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main()
 {

        double h=180,s1=10,s2=10,m1=180,m2=170,pxm,pxf;//,pmx[5],pfx[5],pi1,pi2;
    pxm = ( 1/(sqrt(2*(22/7)*s1) )) * exp( (-1/(2*s1) ) * pow( (h - m1),2) );
    cout<<"SQRT part = "<<sqrt(2*M_PI*s1);
    cout<<"\nfirst part = "<<(1/(sqrt(2*(22/7)*s1)));
    cout<<"\nEXP part = "<<exp( (-1/(2*s1) ) * pow( (h - m1),2) );
    cout<<"\nPXM = "<<pxm<<endl;
    pxf = ( 1/(sqrt(2*(22/7)*s2) )) * exp( (-1/(2*s2 )) * pow( (h- m2),2) );
    cout<<"\nPXF = "<<pxf<<endl;
    cout<<"\n-----------------\n";
}
