#include <iostream>
#include <string>
using namespace std;

int main(){
    string str1, str2, temp;

    str1 = "My name is KKDD";
    str2 = "Geeks For Geeks";
    int found;

    found = str1.find("name");
    cout<<"found for \"name\" in str1 = "<<found<<"\n";
    temp = str1.substr(found+1);
    cout<<"The substring is = "<<temp<<"\n";

    found = str2.find('x');
    cout<<"found for 'x' in str2 = "<<found<<"\n";
}
