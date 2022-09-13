#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;

ll divisors(ll n) {
    ll count = 0;
    ll div = 0;
    
    if(n%2 != 0)
        return 0;

    //in case the number is even
    for(ll i=1; i<ceil(sqrt(n)); i++){
        if(n%i == 0 && i != n){
            if(n/i == i){
                if(i%2 == 0)
                    count++;
            }
            else{
                if(i%2 == 0)
                    count++;
                if((n/i)%2 == 0)
                    count++;
            }
        }
    }
    return count;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    cin.ignore();
    //cout<<"t = "<<t<<endl;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

        ll result = divisors(n);

        cout << result << "\n";
    }

    //fout.close();

    return 0;
}
