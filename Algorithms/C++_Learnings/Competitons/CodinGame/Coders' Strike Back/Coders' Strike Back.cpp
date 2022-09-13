#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
/*TODO
*if distance between me and enemy is X then reduce thrust to Y so that collison do not occurs also take care at the angle at which to do so
as well as the distance from checkpoint to do so
* If enemy is near collide with it itentionally (near checkpoint) so as to throw him out of the checkpoint radius (helpful when speed distractor bots will be available)
*/
int getThrust( int angle, int distance){

    int diff=0, angleDiff = (6/9)*angle;
    if(distance <= 2000){
        diff = 100 - distance/21;
        angleDiff = (8/9)*angle;
    }
    return 100 - angleDiff - diff;
}

int findDist(int x, int y, int targetX, int targetY){

    return sqrt(pow(x - targetX,2) + pow(y - targetY,2));
}

void hitEnemy(int &targetX, int &targetY, int dist, int opponentX, int opponentY){
    targetX = opponentX;
    targetY = opponentY;
}
int main()
{

    bool boostUsed = false;
    // game loop
    while (1) {
        int x, y;
        string thrust;
        int nextCheckpointX; // x position of the next check point
        int nextCheckpointY; // y position of the next check point
        int nextCheckpointDist; // distance to the next checkpoint
        int nextCheckpointAngle; // angle between your pod orientation and the direction of the next checkpoint
        cin >> x >> y >> nextCheckpointX >> nextCheckpointY >> nextCheckpointDist >> nextCheckpointAngle; cin.ignore();
        int opponentX;
        int opponentY;
        cin >> opponentX >> opponentY; cin.ignore();
        int enemyDist, angleBet, distBet, targetX = nextCheckpointX, targetY = nextCheckpointY;

        enemyDist = findDist(opponentX, opponentY, nextCheckpointX, nextCheckpointY);
        distBet = findDist(opponentX, opponentY, x, y);
        angleBet = abs(atan((double)enemyDist/(double)distBet)*180/M_PI);

        if(nextCheckpointAngle < -90 || nextCheckpointAngle > 90)
            thrust = "0";
        else if(distBet < 1000 && (angleBet > 60 && angleBet < 110) )
            hitEnemy(targetX, targetY, distBet, opponentX, opponentY);
        else
            thrust = to_string(getThrust(abs(nextCheckpointAngle), nextCheckpointDist));

        if(!boostUsed && nextCheckpointAngle == 0 && nextCheckpointDist >= 3000){
            thrust = "BOOST";
            boostUsed = true;
        }
        cout << targetX << " " << targetY <<" "<< thrust << endl;
    }
}