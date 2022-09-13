#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

/*void show(vector< vector <string> > v)
{
    //vector <vector <string> > :: iterator it;

    for( int i=0; i<v.size();i++){
        for(int j=0;j<v[i].size(); j++)//it =v.begin(); it != v.end(); it++)
            cout<<v[i][j];

        cout<<endl;
    }
}*/
int main()
{
    string ans="";

   int n1=20999,n2=2;

   ans += "Move ";
   ans += to_string(n1);
   ans += ' ';
   ans += n2 + '0';
   cout<<ans<<endl;
   ans += ans;
   cout<<ans<<endl;
   /*
   vector < vector <string> > vect;
    int n=3,k,i=0;
    string str;

    while(n--){
        k=4;
        vector <string> vc;
        while(k--){
        cout<<"string"<<n<<','<<k<<" = ";
        cin>>str;
        vc.push_back(str);
        }
    vect.push_back(vc);
    }
    cout<<"---BEFORE------\n";
    show(vect);
    for(int i=0;i<3;i++)
        sort(vect[i].begin()+1,vect[i].end());
    cout<<"-----MIDDLE----"<<endl;
    show(vect);
    sort(vect.begin(),vect.end());
    cout<<"-----AFTER---\n";
    show(vect);
    */
    /*string str,str1,str2;

    str1='K';
    str2=" I love you";

    str=" HAse Lyo";
    str1+=str2;
    cout<<"Str1 = "<<str1<<endl;

    str.append(str1);
    cout<<"Str = "<<str<<endl;
    */
}
