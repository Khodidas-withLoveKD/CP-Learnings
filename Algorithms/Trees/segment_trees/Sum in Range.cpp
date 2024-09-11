#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void showTree(int *st, int tree_size){
    for(int i=0; i<tree_size; i++)
        cout<<"ST["<<i<<"] = "<<st[i]<<"\n";
}
int getMid(int l, int r){
    return l + (r-l)/2;
}
void updateValueUtil(int *st, int ss, int se, int si, int index, int diff){
    //base case: if the index lies out of range of segment
    if(index < ss || index > se)
        return;

    //else update node and its children
    st[si] = st[si] + diff;
    if(ss != se){    //not a leaf node
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, si*2+1, index, diff);
        updateValueUtil(st, mid+1, se, si*2+2, index, diff);
    }
}
void updateValue(int *st, int arr[], int n, int index, int new_val){

    //if erroneous index
    if(index < 0 || index > n-1){
        cout<<"Index out of Bounds. Update not Possible";
        return;
    }
    //else update in array
    int diff = new_val - arr[index];
    arr[index] = new_val;

    //update in Segment tree
    updateValueUtil(st, 0, n-1, 0, index, diff);
}
int getSumUtil(int *st, int ss, int se, int si, int qs, int qe){

    //if segment is out of range of qs and qe return 0;
    if(ss > qe || se < qs)
        return 0;

    //if segment totally lies inside the given range take it
    if(ss >= qs && se <= qe)
        return st[si];

    //else if segment lies in part of it then add accordingly
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, si*2 + 1, qs, qe) +
            getSumUtil(st, mid+1, se, si*2+2, qs, qe);
}
int getSum(int *st, int n, int qs, int qe){
    //check fro erroneous index
    if(qs < 0 || qe > n-1 || qs > qe){
        cout<<"Query Index out of bound. Some not Possible";
        return -1;
    }
    return getSumUtil(st, 0, n-1, 0, qs, qe);
}
int constructUtil(int *st, int ss, int se, int si, int arr[]){

    //if the range has just one element than place the element
    //as it is in segment
    if(ss == se){
        st[si] =  arr[ss];
        return st[si];
    }

    //else recur in left and right subtree to construct ST
    int mid = getMid(ss, se);
    st[si] = constructUtil(st, ss, mid, si*2+1, arr) +
             constructUtil (st, mid+1, se, si*2+2, arr);
    return st[si];
}
int * constructST(int arr[], int n){
    int h = ceil(log2(n));

    int tree_size = 2*pow(2, h) - 1;
    //pointer to segment tree
    int *st = new int[tree_size]; cout<<"n = "<<n<<"\nh = "<<h<<"\ntreeSize = "<<tree_size;

    //Construct Segment Tree using recursion
    constructUtil(st, 0, n-1, 0, arr);

    cout<<"\nSegment Tree:\n";
    showTree(st, tree_size);
    return st;
}
int main(){
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    //construct Segment Tree from given array
    int *st = constructST(arr,n);

    //find Sum of given query
    // from i=1 to 4
    cout<<"\nSum for i = 1 to 4 is: "<<getSum(st, n, 1, 4);

    //update arr[2] = 10
    updateValue(st, arr, n, 2, 10);

    cout<<"\nSum after UPDATE\nfor i = 1 to 4 is: "<<getSum(st, n, 1, 4);
    return 0;
}
