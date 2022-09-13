#include <iostream>
#include <set>
#include <utility>
#include <string.h>
#include <algorithm>
#include <stack>
#include <float.h>
#include <cmath>
#define mp(a,b) make_pair(a,b)
using namespace std;

typedef pair <int,int> Pair;
typedef pair <double, pair<int,int> > DPair;
#define ROW 9
#define COL 10

struct cell{

    int parent_i, parent_j;
    double f,g,h;
};

bool isValid(int row, int col){
    //cout<<"inside isVALID\n";
    return ((row >= 0 && row<ROW) && ( col >= 0 && col < COL));
}

bool isUnblocked(int grid[][COL], int row, int col){

    return grid[row][col] == 1 ;
}

bool isDestination(int row, int col, Pair dest){
    //cout<<"inside isDESTINATION\n";
    return (row == dest.first && col == dest.second);
}

void tracePath(cell cellDetails[][COL], int row, int col){
    
    int temp_row,temp_col;
    stack<Pair> Path;
    //cout<<"Inside TracePAth\n";
    while(!(cellDetails[row][col].parent_i == row && cellDetails[row][col].parent_j == col)){
        //cout<<"Inside TracePAth WHILE\n";
        Path.push(mp(row,col));
        temp_row = cellDetails[row][col].parent_i;
        temp_col = cellDetails[row][col].parent_j;
        row = temp_row;
        col = temp_col;
    }
    Path.push(mp(row,col));

    cout<<"The Path is:\n";
    while(!Path.empty()){

        Pair p = Path.top();
        Path.pop();
        cout<<'['<<p.first<<','<<p.second<<']'<<" -> ";
    }
}

double calculateHValue(int row, int col, Pair dest){

    //Taking Euclidean Distance here
    return (double)sqrt((row - dest.first)*(row - dest.first)
                        + (col - dest.second)*(col - dest.second));
}
void AStarSearch( int grid[][COL], Pair src, Pair dest){
    
    int row = src.first;
    int col = src.second;
    if(!isValid(row,col) || !isValid(dest.first, dest.second)){
        cout<<"Source or Dest Cell not Valid";
        return ;
    }

    if(!isUnblocked(grid, row,col) || !isUnblocked(grid, dest.first, dest.second)){
        cout<<"The cell is Blocked. INVALID source or Destination chosen";
        return ;
    }

    if(isDestination(src.first, src.second, dest)){
        cout<<"The Cell is already the Destination";
        return ;
    }
    
    cell cellDetails[ROW][COL];

    //initializing them
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++){

            cellDetails[i][j].f = FLT_MAX;
            cellDetails[i][j].g = FLT_MAX;
            cellDetails[i][j].h = FLT_MAX;
            cellDetails[i][j].parent_i = -1;
            cellDetails[i][j].parent_j = -1;
        }
    //initializing lists
    set<DPair> openList;
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    //initializing source
    cellDetails[row][col].parent_i = row;
    cellDetails[row][col].parent_j = col;
    cellDetails[row][col].f = 0;
    cellDetails[row][col].g = 0;
    cellDetails[row][col].h = 0;
    openList.insert(mp(0, mp(row, col)));

    while(!openList.empty()){

        DPair currentPair = *openList.begin();
        openList.erase(openList.begin());
        row = currentPair.second.first;
        col = currentPair.second.second;
        closedList[row][col] = true;
        double fNew, gNew, hNew;
        
        //cout<<"ROW = "<<row<<" | COL = "<<col<<endl;
        //go for each successor

        //For north (N) successor
        if(isValid(row-1, col)){
        //cout<<"Inise N | ROW = "<<row-1<<" | COL = "<<col<<endl;
            if(isDestination(row-1, col, dest)){
                cout<<"Destination Found\n";
                cellDetails[row-1][col].parent_i = row;
                cellDetails[row-1][col].parent_j = col;
                tracePath(cellDetails, row-1, col);
                return ;
            }
            else if( isUnblocked(grid,row-1, col) && closedList[row-1][col] == false){
                //cout<<"Inside ELSE IF\n";
                //cout<<" isUnlbakcoked = "<<isUnblocked(grid,row-1, col)<<endl;
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row-1, col, dest);
                fNew = gNew + hNew;
               // cout<<"Value = "<<cellDetails[row-1][col].f<<endl;
                //cout<<"fNEW = "<<fNew<<endl;
                if(cellDetails[row-1][col].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
                    //cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row-1, col)));
                    cellDetails[row-1][col].f = fNew;
                    cellDetails[row-1][col].g = gNew;
                    cellDetails[row-1][col].h = hNew;
                    cellDetails[row-1][col].parent_i = row;
                    cellDetails[row-1][col].parent_j = col;
                }
            }
        }

        //For South(S) successor
        if(isValid(row+1, col)){
            //cout<<"Inise S | ROW = "<<row+1<<" | COL = "<<col<<endl;
            if(isDestination(row+1, col, dest)){
                cout<<"Destination Found\n";
                cellDetails[row+1][col].parent_i = row;
                cellDetails[row+1][col].parent_j = col;
                tracePath(cellDetails, row+1, col);
                return ;
            }
            else if( isUnblocked(grid,row+1, col) && closedList[row+1][col] == false){//cout<<"Inside ELSE IF\n";
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row+1, col, dest);
                fNew = gNew + hNew;
                if(cellDetails[row+1][col].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
//cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row+1, col)));
                    cellDetails[row+1][col].f = fNew;
                    cellDetails[row+1][col].g = gNew;
                    cellDetails[row+1][col].h = hNew;
                    cellDetails[row+1][col].parent_i = row;
                    cellDetails[row+1][col].parent_j = col;
                }
            }
        }

        //For East(E) successor
        if(isValid(row, col+1)){
//cout<<"Inise E | ROW = "<<row<<" | COL = "<<col+1<<endl;
            if(isDestination(row, col+1, dest)){
                cout<<"Destination Found\n";
                cellDetails[row][col+1].parent_i = row;
                cellDetails[row][col+1].parent_j = col;
                tracePath(cellDetails, row, col+1);
                return ;
            }
            else if( isUnblocked(grid,row, col+1) && closedList[row][col+1] == false){///cout<<"Inside ELSE IF\n";
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row, col+1, dest);
                fNew = gNew + hNew;
                if(cellDetails[row][col+1].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
//cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row, col+1)));
                    cellDetails[row][col+1].f = fNew;
                    cellDetails[row][col+1].g = gNew;
                    cellDetails[row][col+1].h = hNew;
                    cellDetails[row][col+1].parent_i = row;
                    cellDetails[row][col+1].parent_j = col;
                }
            }
        }
        //For West(W) successor
        if(isValid(row, col-1)){
            //cout<<"Inise W | ROW = "<<row<<" | COL = "<<col-1<<endl;
            if(isDestination(row, col-1, dest)){
                cout<<"Destination Found\n";
                cellDetails[row][col-1].parent_i = row;
                cellDetails[row][col-1].parent_j = col;
                tracePath(cellDetails, row, col-1);
                return ;
            }
            else if( isUnblocked(grid,row, col-1) && closedList[row+1][col-1] == false){//cout<<"Inside ELSE IF\n";
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row, col-1, dest);
                fNew = gNew + hNew;
                if(cellDetails[row][col-1].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
//cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row, col-1)));
                    cellDetails[row][col-1].f = fNew;
                    cellDetails[row][col-1].g = gNew;
                    cellDetails[row][col-1].h = hNew;
                    cellDetails[row][col-1].parent_i = row;
                    cellDetails[row][col-1].parent_j = col;
                }
            }
        }
        //For (NE) successor
        if(isValid(row-1, col+1)){
            //cout<<"Inise NE | ROW = "<<row-1<<" | COL = "<<col+1<<endl;
            if(isDestination(row-1, col+1, dest)){
                cout<<"Destination Found\n";
                cellDetails[row-1][col+1].parent_i = row;
                cellDetails[row-1][col+1].parent_j = col;
                tracePath(cellDetails, row-1, col+1);
                return ;
            }
            else if( isUnblocked(grid,row-1, col+1) && closedList[row-1][col+1] == false){//cout<<"Inside ELSE IF\n";
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row-1, col+1, dest);
                fNew = gNew + hNew;
                if(cellDetails[row-1][col+1].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
//cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row-1, col+1)));
                    cellDetails[row-1][col+1].f = fNew;
                    cellDetails[row-1][col+1].g = gNew;
                    cellDetails[row-1][col+1].h = hNew;
                    cellDetails[row-1][col+1].parent_i = row;
                    cellDetails[row-1][col+1].parent_j = col;
                }
            }
        }
        //For (NW) successor
        if(isValid(row-1, col-1)){
            //cout<<"Inise NW | ROW = "<<row-1<<" | COL = "<<col-1<<endl;
            if(isDestination(row-1, col-1, dest)){
                cout<<"Destination Found\n";
                cellDetails[row-1][col-1].parent_i = row;
                cellDetails[row-1][col-1].parent_j = col;
                tracePath(cellDetails, row-1, col-1);
                return ;
            }
            else if( isUnblocked(grid,row-1, col-1) && closedList[row-1][col-1] == false){//cout<<"Inside ELSE IF\n";
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row-1, col-1, dest);
                fNew = gNew + hNew;
                if(cellDetails[row-1][col-1].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
//cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row-1, col-1)));
                    cellDetails[row-1][col-1].f = fNew;
                    cellDetails[row-1][col-1].g = gNew;
                    cellDetails[row-1][col-1].h = hNew;
                    cellDetails[row-1][col-1].parent_i = row;
                    cellDetails[row-1][col-1].parent_j = col;
                }
            }
        }
        //For (SE) successor
        if(isValid(row+1, col+1)){
//cout<<"Inise SE | ROW = "<<row+1<<" | COL = "<<col+1<<endl;
            if(isDestination(row+1, col+1, dest)){
                cout<<"Destination Found\n";
                cellDetails[row+1][col+1].parent_i = row;
                cellDetails[row+1][col+1].parent_j = col;
                tracePath(cellDetails, row+1, col+1);
                return ;
            }
            else if( isUnblocked(grid,row+1, col+1) && closedList[row+1][col+1] == false){//cout<<"Inside ELSE IF\n";
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row+1, col+1, dest);
                fNew = gNew + hNew;
                if(cellDetails[row+1][col+1].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
//cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row+1, col+1)));
                    cellDetails[row+1][col+1].f = fNew;
                    cellDetails[row+1][col+1].g = gNew;
                    cellDetails[row+1][col+1].h = hNew;
                    cellDetails[row+1][col+1].parent_i = row;
                    cellDetails[row+1][col+1].parent_j = col;
                }
            }
        }
         //For (SW) successor
        if(isValid(row+1, col-1)){
//cout<<"Inise SW | ROW = "<<row+1<<" | COL = "<<col-1<<endl;
            if(isDestination(row+1, col-1, dest)){
                cout<<"Destination Found\n";
                cellDetails[row+1][col-1].parent_i = row;
                cellDetails[row+1][col-1].parent_j = col;
                tracePath(cellDetails, row+1, col-1);
                return ;
            }
            else if( isUnblocked(grid,row+1, col-1) && closedList[row+1][col-1] == false){//cout<<"Inside ELSE IF\n";
                gNew = cellDetails[row][col].g + 1;
                hNew = calculateHValue(row+1, col-1, dest);
                fNew = gNew + hNew;
                if(cellDetails[row+1][col-1].f > fNew){  //not keeping the cellDetails[row+1][col].f == FLT_MAX
//cout<<"Inside INSIDER IF\n";
                    openList.insert(mp(fNew, mp(row+1, col-1)));
                    cellDetails[row+1][col-1].f = fNew;
                    cellDetails[row+1][col-1].g = gNew;
                    cellDetails[row+1][col-1].h = hNew;
                    cellDetails[row+1][col-1].parent_i = row;
                    cellDetails[row+1][col-1].parent_j = col;
                }
            }
        }
    }
    cout<<"\n\nUnable to find Path !!!";

}
int main(){

    /* Description of the Grid-
     1--> The cell is not blocked
     0--> The cell is blocked    */
    int grid[ROW][COL] =
    {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
    };

    Pair src = mp(8,0);
    Pair dest = mp(0,0);

    //Calling A* search
    AStarSearch(grid, src, dest);
}
