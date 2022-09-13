#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

char current,ans[1500];
vector<int> S,E,CS,CE,JS,JE;
int j=0,test_counter=1;

bool check_jane(int i)
{
    /*cout<<"-------Jane----"<<endl;
    for(int z=0;z<JS.size();z++)
        cout<<"JS["<<z<<"]="<<JS[z]<<" JE["<<z<<"]="<<JE[z]<<endl;
	*/for(int z=0;z<JS.size();z++){
        if(E[i]<=JS[z] || S[i]>=JE[z])//(S[i]<JS[z] && E[i]<=JS[z]) || (S[i]>=JE[z] && E[i]>JE[z]))
            continue;
        else
            return false;
    }
	return true;
}
bool check_cameron(int i)
{
    /*cout<<"-------Cameron----"<<endl;
    for(int z=0;z<CS.size();z++)
        cout<<"CS["<<z<<"]="<<CS[z]<<" CE["<<z<<"]="<<CE[z]<<endl;
	*/for(int z=0;z<CS.size();z++){
		if(E[i]<=CS[z] || S[i]>=CE[z])//(S[i]<CS[z] && E[i]<=CS[z]) || (S[i]>=CE[z] && E[i]>CE[z]))
			continue;
        else
            return false;
	}
	return true;
}
void assign(char ch,int i)
{	
	if(ch=='C'){
		CS.push_back(S[i]);
		CE.push_back(E[i]);
	}
	else if(ch=='J'){
		JS.push_back(S[i]);
		JE.push_back(E[i]);
	}
	current=ch;
	ans[j++]=current;
}
int main()
{
	/*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif*/

    int test,N,s,e;

	cin>>test;
    while(test--){
    	cin>>N;
    	memset(ans,'\0',sizeof(ans));
    	CS.clear();
    	CE.clear();
    	JS.clear();
    	JE.clear();
    	S.clear();
    	E.clear();
    	j=0;
    	current='C';
    	ans[j++]=current;

    	for(int i=0;i<N;i++){
    		cin>>s>>e; cin.ignore();
    		S.push_back(s);
    		E.push_back(e);	
    	}
    	CS.push_back(S[0]);CE.push_back(E[0]);

    	for(int i=1;i<S.size();i++){
    		//Assigning Cameron
    		if(check_cameron(i)){
                //cout<<"Cameron="<<check_cameron(i)<<endl;
    			assign('C',i);
            }
    		else if(check_jane(i)){
    			//cout<<"JANE="<<check_jane(i)<<endl;
                assign('J',i);
            }
    		else{
    			memset(ans,'\0',sizeof(ans));
    			ans[0]='I';ans[1]='M';ans[2]='P';ans[3]='O';ans[4]='S';ans[5]='S';ans[6]='I';ans[7]='B';ans[8]='L';ans[9]='E';
    			break;
    		}
    	}


  	  	cout<<"Case #"<<test_counter++<<": "<<ans<<endl;
    }
}