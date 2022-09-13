#include <bits/stdc++.h>
#define ll long long

using namespace std;

//make stack of pair <int,string>

string appender;
void showStack ( stack <pair<ll,string> > stacker)
{
    pair<ll ,string> p;

    while(!stacker.empty()){
        p=stacker.top();
        cout<<"-----------\n"<<p.first<<','<<p.second<<endl;
        stacker.pop();
    }
}
void solve( ll n, string st)
{
    appender="";
    cout<<"N = "<<n<<" St = "<<st<<endl;
    for(int i=0;i<n; i++)  
        appender += st;
    cout<<"Appender = "<<appender<<endl;
}

int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    int test;
    ll D,N,val,caser=1;

    cin>>test;
    while(test--){
        
        stack <pair<ll,string> > st;

        appender = "";
        ll prev_counter=0,counter=0;
        pair<ll, string> p;
        //stack <string> s;
        ll num=1,row=1,col=1;
        string temp="",str;
        cin>>str;

        for(int i=0; i < str.length();i++){
            if(str[i] >= '2' && str[i] <= '9'){
                if(temp == "" && counter == 0){//counter != 0 && str[i+2] >= '2' && str[i+2] <= '9'){// && temp != "")
                    num = str[i] - '0';
                    st.push(make_pair(num,temp));
                cout<<"first if Pushed "<<num<<','<<temp<<endl;
                }
                //temp="";
                num = str[i] - '0';
                continue;
            }
            else if(str[i] == '('){
                counter++;
                temp="";
                //st.push(make_pair(num,temp));
                continue;
                }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                if(counter != 0)
                    temp += str[i];
                else{
                    if(!st.empty()){
                        p=st.top();
                        p.second.append(1,str[i]);
                        st.pop();
                        st.push(make_pair(p.first,p.second));
                cout<<"A IF FIRST Pushed "<<p.first<<','<<p.second<<endl;
                    }
                    else{
                        string psec = "";
                        psec += str[i];
                        st.push(make_pair(1,psec));
                         cout<<"A ELSE Pushed "<<'1'<<','<<psec<<endl;
                    }
                }
                if(str[i+1] >= '2' && str[i+1] <='9')
                   st.push(make_pair(num,temp)); 
                continue;
            }
            else if(str[i] == ')' ){
                counter--;
                solve(num,temp);
                p=st.top();
                cout<<"-------BEFORE------\n";showStack(st);
                //cout<<"--------\n"<<"Counter = "<<counter<<endl<<"TOP\nFirst = "<<p.first<<"  Second = "<<p.second<<endl;
                p.second.append(appender);
                st.pop();
                st.push(make_pair(p.first,p.second));
                cout<<"-------After------\n";showStack(st);
                //cout<<"First = "<<p.first<<"  Second = "<<p.second<<endl; 
                temp="";
                num=1;
            }
        }

        p=st.top();
        solve(p.first,p.second);
        //p.second.append(appender);

        cout<<"Case #"<<caser++<<": "<<appender<<endl;
    }
}
