#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>
using namespace std;
#define N 8

void printPath(int board[N][N]){
    cout<<"Path is:\n";
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++)
            cout<<" "<<setw(2)<<board[i][j]<<" \n"[j == 7];
    }
}
bool isSafe(int x, int y, int board[N][N]){
    return (x >= 0 && x < 8 && y >= 0 && y < 8 && board[x][y] == -1);
}
bool solveKTUtil(int x, int y, int moveNum, int next_x[N], int next_y[N], int board[N][N]){
    //cout<<"Inside solveUTil\n";
    //last cell
    if(moveNum == 64)
        return true;
    //cout<<"Board["<<x<<"]["<<y<<"] = "<<board[x][y]<<"\n";
    //printPath(board);
    //check for next possible move
    for(int i=0; i<N; i++){
        int new_x = x + next_x[i];
        int new_y = y + next_y[i];

        if(isSafe(new_x, new_y, board)){ //cout<<"Inside If isSafe\n";
            //proceed
            board[new_x][new_y] = moveNum;
            //see if current route gives a possible solution
            if(solveKTUtil(new_x, new_y, moveNum + 1, next_x, next_y, board))
                return true;
            else{//cout<<"Inside backTrack\n";
                //backtrack
                board[new_x][new_y] = -1;
            }
        }
    }
    //if none of the further states are possible then
    return false;
}

void solveKT(){
    //make chess board, valid moves of knight
    int board[8][8];
    memset(board, -1, sizeof(board));

    //the x-y vertices are as per gaming conventions
    int next_x[N] = { 2, 1, -1, -2, -2, -1, 1, 2 };//{2, 2, -2, -2, -1, 1, -1, 1};
    int next_y[N] = { 1, 2, 2, 1, -1, -2, -2, -1 };//{-1, 1, -1, 1, 2, 2, -2, -2};

    //knight is at 0,0;
    board[0][0] = 0;
    int moveNum = 0;

    //find a possible path
    if(!solveKTUtil(0, 0, 1, next_x, next_y, board)){
        cout<<"Path not possible";
    }
    else
        printPath(board);
}

int main(){
    solveKT();
    return 0;
}
