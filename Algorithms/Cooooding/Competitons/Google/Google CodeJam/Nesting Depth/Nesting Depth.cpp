#include <string.h>
#include <iostream>
#include <cmath>

using namespace std;

string S;
char Sd[1000];
int lp_count,rp_count,prev_digit,j;

int to_int(char c)
{//cout<<"TO_INT"<<endl;
	int num = (int)c - '0';
	return num;
}
char to_char(int i)
{//cout<<"TOCHAR"<<endl;
	char c=(char)( i +'0');
	return c; 
}
void lp(int np)
{//cout<<"LP"<<endl;
	while(np--){
		Sd[j++]='(';
	}
}
void rp(int np)
{//cout<<"RP"<<endl;
	while(np--){
		Sd[j++]=')';
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

	int test,num,np,test_counter=1;

	cin>>test; cin.ignore();

	while(test--){
	    
	    lp_count=0,rp_count=0,prev_digit=0,j=0;
		getline(cin, S);
		memset(Sd,'\0',sizeof(Sd));

		for(int i=0; i<S.length();i++){
			num=to_int(S[i]);
			np=abs(num-prev_digit);
			//cout<<"FOR"<<endl;

			if(num>prev_digit){
				//cout<<"IF"<<endl;
				lp(np);
				Sd[j++]=to_char(num);
				lp_count+=np;
				rp_count=-lp_count;
				prev_digit=num;
			}
			else if(num<prev_digit){
				//cout<<"ELSE IF"<<endl;
				rp(np);
				Sd[j++]=to_char(num);
				lp_count-=np;
				rp_count+=np;
				prev_digit=num;
			}
			else if(num==prev_digit){
				//cout<<"ELSE"<<endl;
				Sd[j++]=to_char(num);
			}
		}
		while(rp_count!=0){
			//cout<<"WHILE"<<endl;
			Sd[j++]=')';
			rp_count++;
		}

		cout<<"Case #"<<test_counter++<<": "<<Sd<<endl;
	
    }

}