#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LISLength(int v[], int n){
    int len[n];
    for(int k=0; k<n; k++){
        len[k] = 1;
        for(int i=0; i<k; i++){
            if(v[i] < v[k])
                len[k] = max(len[k], len[i] + 1);
        }
    }
    return len[n-1];
}
int main(){
    int v[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(v)/sizeof(v[0]);

    cout << "Length of Longest Increasing Subsequence is "
            << LISLength(v, n);
    return 0;
}
