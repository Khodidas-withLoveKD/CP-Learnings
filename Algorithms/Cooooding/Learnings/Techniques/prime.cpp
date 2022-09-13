#include <iostream>
#include <cmath>

using namespace std;

bool prime(int num){

    if(num != 2 && num % 2 == 0)
        return false;

    for(int j=3; j<=sqrt(num); j=j+2){
        if(num % j == 0)
            return false;
    }
    return true;
}

int main()
{
    int counter=0;
    for(int i=2; i<=1000; i++)
        if(prime(i)){
            cout<<i<<' ';
            counter++;
        }

    cout<<"No. of primes = "<<counter;
}
