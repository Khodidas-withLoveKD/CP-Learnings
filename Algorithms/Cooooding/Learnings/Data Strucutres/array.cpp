#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[] ={1,2,3,4,5,6,7,8,9};

    auto it = find(arr, arr+9, 6);
    cout<<"6 loacted at index = "<<distance(arr, it);
}
