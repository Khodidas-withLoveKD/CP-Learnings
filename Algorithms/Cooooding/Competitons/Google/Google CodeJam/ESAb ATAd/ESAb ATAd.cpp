#include <vector>
#include <iostream>

using namespace std;

vector<int> counter;

void reset(int N)
{
	for(int i=0;i<N;i++)
		counter[i]=0;
}

int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    int test,B;

    cin>>test>>B; cin.ignore();
    while(test--){
    	

	    cout<<"Case #"<<test_counter++<<": "<<trace<<" "<<row_count<<" "<<col_count<<endl;
    }
}