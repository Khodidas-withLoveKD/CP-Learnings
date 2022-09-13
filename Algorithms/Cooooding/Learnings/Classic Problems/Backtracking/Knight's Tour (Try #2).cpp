#include <bits/stdc++.h>
#define N 8
using namespace std;

void printPath(int board[N][N]){
    cout<<"Path is:\n";
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout<<" "<<setw(2)<<board[i][j]<<" \n"[j == 7];
        //cout<<"\n";
    }
}
bool isSafe(int x, int y, int board[N][N]){
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}
bool solveKTUtil(int x, int y, int moveNum, int xMove[N], int yMove[N], int board[N][N]){
    if(moveNum == N*N)
        return true;

    for(int i=0; i<N; i++){
        int next_x = x + xMove[i];
        int next_y = y + yMove[i];

        if(isSafe(next_x, next_y, board)){
            board[next_x][next_y] = moveNum;
            if(solveKTUtil(next_x, next_y, moveNum+1, xMove, yMove, board))
                return true;
            else
                //backtrack
                board[next_x][next_y] = -1;
        }
    }
    return false;
}
void solveKT(){
    int board[N][N];
    memset(board, -1, sizeof(board));

    int xMove[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMove[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int moveNum = 0;
	board[0][0] = 0;

	if(solveKTUtil(0, 0, moveNum+1, xMove, yMove, board))
        printPath(board);
    else
        cout<<"No Path";
}

int main(){
    solveKT();
    return 0;
}
