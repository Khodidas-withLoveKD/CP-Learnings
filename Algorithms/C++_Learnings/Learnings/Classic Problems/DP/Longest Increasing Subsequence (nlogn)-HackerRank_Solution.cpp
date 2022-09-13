#include <bits/stdc++.h>

const int N = 1000111;
const int INF = 1<<30;
int m[N];
int a[N];
using namespace std;
int main() {
    int a[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = sizeof(a)/sizeof(a[0]);
    //scanf("%d", &n);
    /*for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        m[i + 1] = INF;
    }
    */

    for(int i = 0; i < n; i++)
        m[i + 1] = INF;
    for (int i = 0; i < n; i++) {
        int lo = 0, hi = n;
        while (hi - lo > 1) {
            int md = lo + hi >> 1;
            (m[md] < a[i] ? lo : hi) = md;
        }
        m[hi] = a[i];
        cout<<"m["<<hi<<"] = "<<m[hi]<<"\n";
    }

    cout<<"M array:\n";
    for(int i=0; i<n; i++)
        cout<<"m["<<i<<"] = "<<m[i]<<"\n";
    int ans = 0;
    while (ans < n && m[ans + 1] < INF) ans++;
    printf("%d\n", ans);
}
