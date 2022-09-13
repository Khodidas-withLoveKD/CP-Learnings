#include <iostream>
#include <cmath>
using namespace std;

double h[5],pm[5],pf[5],s1=7.07343,s2=7.72372,m1=176.541,m2=168.147,pxm[5],pxf[5],pmx[5],pfx[5],pi1,pi2,new_m1=0,new_m2=0,new_v1=0,new_v2=0,sum_m=0,sum_f=0;;

void newMean(){

    new_m1 = 0;
    new_m2 = 0;
    for(int i=0; i<5; i++){
        new_m1 += h[i]*pmx[i];
        new_m2 += h[i]*pfx[i];
    }
    new_m1 = new_m1/sum_m;
    new_m2 = new_m2/sum_f;
}

void newVariance(){

    new_v1 = 0;
    new_v2 = 0;
    for(int i=0; i<5; i++){
        new_v1 += pmx[i]*pow((h[i] - new_m1),2);
        new_v2 += pfx[i]*pow((h[i] - new_m2),2);
    }
    new_v1 = new_v1/sum_m;
    new_v2 = new_v2/sum_f;
}

void calPmx(int i){

    pmx[i] = (pxm[i]*pm[i])/( (pxm[i]*pm[i]) + (pxf[i]*pf[i]));
    cout<<"pmx["<<i<<"] = "<<pmx[i]<<endl;
    sum_m += pmx[i];

    pfx[i] = 1 - pmx[i];
    sum_f += pfx[i];
    cout<<"pfx["<<i<<"] = "<<pfx[i]<<endl;
    cout<<"\n-----------------\n";
}

void calPxm(int i){

    pxm[i] = ( 1/(sqrt(2*M_PI*s1) )) * exp( (-1/(2*s1) ) * pow( (h[i] - m1),2) );
    cout<<"PXM["<<i<<"] = "<<pxm[i]<<endl;
    pxf[i] = ( 1/(sqrt(2*M_PI*s2) )) * exp( (-1/(2*s2 )) * pow( (h[i] - m2),2) );
    cout<<"PXF["<<i<<"] = "<<pxf[i]<<endl;
    cout<<"\n-----------------\n";
}

void displayValues(){

    for(int i=0; i < 5; i++){
        cout<<"height Prob = ";
        cout<<h[i]<<" , "<<pm[i]<<endl;
    }
}

int main(){

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    for(int i=0; i < 5; i++){
        //cout<<"height Prob = ";
        cin>>h[i]>>pm[i]; cin.ignore();
        pf[i] = 1 - pm[i];
    }
    //cout<<"-----------------\n";
    //displayValues();
    //cout<<"\n-----------------\n";

    s1 = pow(s1,2);
    s2 = pow(s2,2);
    sum_f=0;
    sum_m=0;
    for(int i=0; i < 5; i++){
        calPxm(i);
        calPmx(i);
    }
    cout<<"\n-----------UPDATED values ---------\n";
    pi1 = sum_m/5;
    cout<<"\npi1 = "<<pi1<<endl;
    pi2 = 1 - pi1;
    cout<<"pi2 = "<<pi2<<endl;

    newMean();
    cout<<"new_m1 = "<<new_m1<<endl;
    cout<<"new_m2 = "<<new_m2<<endl;
    newVariance();
    cout<<"new_v1 = "<<new_v1<<endl;
    cout<<"new_v1_sqrt = "<<sqrt(new_v1)<<endl;
    cout<<"new_v2 = "<<new_v2<<endl;
    cout<<"new_v2_sqrt = "<<sqrt(new_v2)<<endl;
}
