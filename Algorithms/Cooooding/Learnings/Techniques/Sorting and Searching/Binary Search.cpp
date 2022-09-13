#include <iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int key = 3;

    //binary search 1;
    int l=0, r = sizeof(arr)/sizeof(arr[0]) - 1;
    int iterations = 0;
    int m = l + (r - l)/2;
    while(arr[m] != key){
        iterations++;
        if(arr[m] < key)
            l = m;
        else if(arr[m] > key)
            r = m;
        m = l +(r-l)/2;
    }
    cout<<"m = "<<m<<" and arr[m] = "<<arr[m]<<" iterations = "<<iterations<<"\n";
    iterations = 0;
    while(r - l > 1){
        iterations++;
        if(arr[m] <= key)
            l = m;
        else if(arr[m] > key)
            r = m;
        m = l +(r-l)/2;
    }
    cout<<"m = "<<m<<" and arr[m] = "<<arr[m]<<" iterations = "<<iterations<<"\n";

}
