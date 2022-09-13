#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findPile(int arr[], int l, int r, int key){
    int m;
    while(r - l > 1){
        m = l +(r-l)/2;
        if(arr[m] < key)
            l = m;
        else if(arr[m] >= key)
            r = m;
    }
    return r;
}

void LISLengthAndPattern(int v[], int n){
    //base case, n=0;
    if(n == 0)
        return;

    int smallestInPile[n], piles=1;   //pile defines the no. of piles created
    smallestInPile[0] = v[0];   //first pile has the first card
    for(size_t i=1; i<n; i++){

        //the new smallest element
        if(v[i] < smallestInPile[0])
            smallestInPile[0] = v[i];

        //new pile
        else if(v[i] > smallestInPile[piles-1])
            smallestInPile[piles++] = v[i];

        //if v[i] is somewhere in between add it in a proper pile (using binary search)
        else
            smallestInPile[findPile(smallestInPile, -1, piles-1, v[i])] = v[i];
        cout<<"m["<<piles<<"] = "<<smallestInPile[piles-1]<<"\n";
    }
    cout<<"------------------------------------\n";
    for(int i=0; i<n; i++)
        cout<<"m["<<i<<"] = "<<smallestInPile[i]<<"\n";
    cout << "Length of Longest Increasing Subsequence is "<<piles<<"\n";
    cout <<"LIS is: ";
    for(int i=0; i<piles; i++)
        cout<<smallestInPile[i]<<" ";
}
int main(){
    int v[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(v)/sizeof(v[0]);
    LISLengthAndPattern(v, n);
    return 0;
}


