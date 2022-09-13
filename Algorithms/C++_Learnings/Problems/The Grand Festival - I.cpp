
#include <iostream>
#include <vector>
#include <algorithm> 
#define pb push_back
using namespace std;
int N,R, x; 
int temp = 0,total = 0;

void findRestDay(int perIndex, vector<int> &dayTotal, const vector<int> days, int minSkips, int maxSkips, vector<bool> isSkipped){

    int tempTotal, index, bestIndex = perIndex - 1, noOfSkips = 0;
    total += days[perIndex] - temp;
    if(minSkips == 0){
        dayTotal[perIndex] = total;
        return ;
    }
    
    while(noOfSkips <= minSkips){
        //one by one skip one day and check which is the best
        //start from current day till limit
        noOfSkips++;
        index = bestIndex + 1;
        for(int i=index; i<=(R+1) && i<N; i++){
            tempTotal = total;
            if(isSkipped[i])
                continue;
            tempTotal -= days[i];
            if(tempTotal > dayTotal[index]){    //if new total greater than current update it
                dayTotal[index] = tempTotal;
                bestIndex = i;
            }
            if( i+1 < N && dayTotal[i] > dayTotal[i+1])     //optimal substructure
                break;      //no need to check further
        }
        isSkipped[bestIndex] = true;
    }
    noOfSkips--;
    bestIndex = perIndex - 1;
    //checking a little further
    while(noOfSkips <= maxSkips){
        noOfSkips++;
        index = bestIndex + 1;
        for(int i=index; i<=(R+1) && i<N; i++){
            tempTotal = total;
            if(isSkipped[i])
                continue;
            tempTotal -= days[i];
            if(tempTotal > dayTotal[index]){    //if new total greater than current update it
                dayTotal[index] = tempTotal;
                bestIndex = i;
            }
            if( i+1 < N && dayTotal[i] > dayTotal[i+1])     //optimal substructure
                break;      //no need to check further
        }
        if(bestIndex < N && bestIndex >= 0) isSkipped[bestIndex] = true;
    }
}
int main(){
    cin>>N; cin.ignore();
    cin>>R; cin.ignore();
    vector<int> days, dayTotal(N, 0);
    vector<bool> isSkipped(N, false);
    int total = 0, tempTotal= 0, limit = R+1;

    while(cin>>x){
        days.pb(x);
        tempTotal += x;
    }

    for(int i=N-1; i >= 0; i--){
        int noOfDays = N - i;
        int minNoOfSkips = noOfDays/(R+1);      //one day in a group of R+1 days must be skipped
        int maxNoOfSkips = 2*minNoOfSkips;      //atleast one day

        findRestDay(i, dayTotal, days, minNoOfSkips, maxNoOfSkips, isSkipped);
    }
    cout << dayTotal[0] << endl;
}	
/*------------------------------------------------------------------------*/
int temp = 0, newTotal;
	if( dayTotal[daySkipped] >=  tempTotal - days[daySkipped])  	
        return dayTotal[daySkipped];    
    else {
	    
        for(int i = 0; i<=R && (daySkipped  + i) < N; i++){
            if(i == 0 || limit == 0 ){   //Rest on the same day
                newTotal = tempTotal - days[daySkipped];
                limit = R+1;
            }
            else
                newTotal = tempTotal;   //resting on other days
            temp = max(temp, findRestDay(newTotal, daySkipped + i, dayTotal, days, limit--));
        }
        dayTotal[daySkipped] = tempTotal - days[daySkipped];
        temp = max(temp, dayTotal[daySkipped]);
        //cout<<" MAX["<<daySkipped]
        }
    return temp;