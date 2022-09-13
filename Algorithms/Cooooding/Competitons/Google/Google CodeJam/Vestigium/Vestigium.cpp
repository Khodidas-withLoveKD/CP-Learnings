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
	/*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif*/

    int test,N,val,trace=0,row_count=0,col_count=0,test_counter=1;

    cin>>test;
    while(test--){
    	cin>>N;
    	vector< vector<int> > vect;
    	trace=0,row_count=0,col_count=0;
    	//reset(N);

    	for(int i=0;i<N;i++){
    		vector<int> row;
    		counter.push_back(0);
    		for(int j=0;j<N;j++){
    			cin>>val;
    			row.push_back(val);
    		}

    		vect.push_back(row);
   		 }
   		 ///calculating trace;
    for(int i=0;i<N;i++)
    		trace+=vect[i][i];

	    	//calculating row count
	    for(int i=0;i<N;i++){
	    	for(int j=0;j<N;j++){
	    		counter[vect[i][j]-1]++;
	    		if(counter[vect[i][j]-1]>1){
	    			row_count++;
	    			break;
	    		}
	    	}
	    	reset(N);
	    }

	    //calculating col count
	    for(int i=0;i<N;i++){
	    	for(int j=0;j<N;j++){
	    		counter[vect[j][i]-1]++;
	    		if(counter[vect[j][i]-1]>1){
	    			col_count++;
	    			break;
	    		}
	    	}
	    	reset(N);
	    }

	    cout<<"Case #"<<test_counter++<<": "<<trace<<" "<<row_count<<" "<<col_count<<endl;
    }
}