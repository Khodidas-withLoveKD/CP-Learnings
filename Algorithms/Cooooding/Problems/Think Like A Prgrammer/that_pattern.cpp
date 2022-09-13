#include <iostream>

using namespace std;

int main(){

    int num;
    cout<<"Enter no. of most stars: ";
    cin>>num;

    int noOfStars, noOfSpace, noOfStars2, spaceInBetween, totalColumns;
    totalColumns = 2*(num + num - 1);

    for(int i = 0; i < num; i++){
        noOfSpace = i % num;
        noOfStars = i+1;
        noOfStars2 = noOfStars;
        spaceInBetween = totalColumns - 2*(noOfSpace + noOfStars);

        while(noOfSpace--)
            cout<<" ";

        while(noOfStars--)
            cout<<"#";

        while(spaceInBetween--)
            cout<<" ";

        while(noOfStars2--)
            cout<<"#";

        cout<<endl;
    }

    for(int i = num-1; i >= 0; i--){
        noOfSpace = i % num;
        noOfStars = i+1;
        noOfStars2 = noOfStars;
        spaceInBetween = totalColumns - 2*(noOfSpace + noOfStars);

        while(noOfSpace--)
            cout<<" ";

        while(noOfStars--)
            cout<<"#";

        while(spaceInBetween--)
            cout<<" ";

        while(noOfStars2--)
            cout<<"#";

        cout<<endl;
    }

}

