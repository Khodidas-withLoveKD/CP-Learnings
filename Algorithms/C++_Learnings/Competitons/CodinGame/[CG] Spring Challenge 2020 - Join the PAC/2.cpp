#include <bits/stdc++.h>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;

/**
 * Grab the pellets as fast as you can!
 **/
 /*
 Note:
 - Still need to improve a lot because it is not eating the nearest pellet first

-It is not good idea to remove pellet from vector because if one pac is closer to
 it still other pac has also that pellet as closest then there may be case that
 the closest one will not get chance to eat it
- Collision?

-[DONE] Making mistake in same row and same col because if same y then they are in same row
and vice versa
-[DONE] Remove the marked pellet from vector
 */
int width; // size of the grid
int height; // top left corner is (x=0, y=0)
vector<string> grid;
vector< pair<int,int> > bigPellet,smallPellet;
vector <pair< int, pair<string, pair<int, int> > > > pac,oppPac;
vector <int> coolDown,speedTurns;
int targetX,targetY,currentX,currentY,midX;
string pacCommand,currentType,enemyType;
int temp=0;

int findDist(int coordinate, int mid, int range){

    if(coordinate >= mid)
        return (range - coordinate - 1);

    return coordinate;
}
void minDistance(int pelletX, int pelletY, int currentX, int CurrentY, int &minDist, int &targetX, int &targetY){

    int dist, distX, distY,x,y;

    distX = 0;
    distY = 0;
    //finding distance
    //check if the pacman and pellet lie on the same half of grid
    x = abs(currentX - pelletX);
    //cout<<" X = "<<x<<" MidX = "<<midX<<" | ";//<<" DistY = "<<distY<<" Dist = "<<dist<<" | ";
    if(x >= midX){
        distX += findDist(currentX, midX, width);
        distX += findDist(pelletX, midX, width);
        //cout<<"Inside IF ";
    }
    else
        distX += x;

    if(x > minDist)
        return ;

    y = abs(currentY - pelletY);
    /*if(y >= midY){
        distY += findDist(currentY, midY, height);
        distY += findDist(pelletY, midY, height);
    }
    else*/
        distY += y;
    if(y > minDist)
        return ;

    dist = distX + distY;
    //cout<<" DistX = "<<distX<<" DistY = "<<distY<<" Dist = "<<dist<<" | ";
    //finding min dist;
    if(dist < minDist){
        minDist = dist;
        targetX = pelletX;
        targetY = pelletY;
    }

}
void findClosestPellet(int &currentX, int &currentY, int &targetX, int &targetY){

    int pelletX,pelletY,minDist = 10000;
    bool flag;

    if(bigPellet.size() != 0){
        for(int i=0; i < bigPellet.size(); i++){
            flag = false;
            pelletX = bigPellet[i].first;
            pelletY = bigPellet[i].second;

            minDistance(pelletX, pelletY, currentX, currentY, minDist, targetX, targetY);
            //cout<<"PAC = "<<temp<<" targetX = "<<targetX<<" ,targetY = "<<targetY<<" || ";
            }
        int mark;
        for(int i=0; i < bigPellet.size(); i++)
            if(bigPellet[i].first == targetX && bigPellet[i].second == targetY){
                mark=i;
                break;
            }
    bigPellet.erase(bigPellet.begin() + mark);
    }
    else{
        for(int i=0; i<smallPellet.size(); i++){
            flag = false;
            pelletX = smallPellet[i].first;
            pelletY = smallPellet[i].second;

            minDistance(pelletX, pelletY, currentX, currentY, minDist, targetX, targetY);
        }
        int mark;
        for(int i=0; i < smallPellet.size(); i++)
            if(smallPellet[i].first == targetX && smallPellet[i].second == targetY){
                mark=i;
                break;
            }
    smallPellet.erase(smallPellet.begin() + mark);
    }
    //temp++;
}
bool canIDefeatHim(string currentType, string enemyType ){
    if((currentType == "ROCK" && enemyType == "SCISSORS") || (currentType == "SCISSORS" && enemyType == "PAPER") || (currentType == "PAPER" && enemyType == "ROCK") )
        return true;
    else
        return false;
}
bool inSameCol(int pacX, int &oppX, int &oppY, string &enemyType, int &enemyPacId){

    if(!oppPac.empty())
    for(int i=0; i < oppPac.size(); i++)
        if(oppPac[i].second.second.first == pacX){
            oppX = oppPac[i].second.second.first;
            oppY = oppPac[i].second.second.second;
            enemyType = oppPac[i].second.first;
            enemyPacId = oppPac[i].first;
            return true;
        }
        //cout<<"sameCOL = FALSE | ";
    return false;
}
bool inSameRow(int pacY, int &oppX, int &oppY, string &enemyType, int &enemyPacId){

    if(!oppPac.empty())
    for(int i=0; i < oppPac.size(); i++)
        if(oppPac[i].second.second.second == pacY){
            oppY = oppPac[i].second.second.second;
            oppX = oppPac[i].second.second.first;
            enemyType = oppPac[i].second.first;
            enemyPacId = oppPac[i].first;
            return true;
        }
       // cout<<"sameROW = FALSE | ";
    return false;
}
void speedUp(int myPacId, string &pacCommand){

    pacCommand += "SPEED ";
    pacCommand += to_string(myPacId);
}
void Switch(int myPacId, string enemyType, string &pacCommand){

    pacCommand += "SWITCH ";
    pacCommand += to_string(myPacId);
    pacCommand += ' ';

    if(enemyType == "ROCK")
        pacCommand += "PAPER";
    else if(enemyType == "PAPER")
        pacCommand += "SCISSORS";
    else
        pacCommand += "ROCK";
}
void simplyMove(int myPacId, int targetX, int taregetY, string &pacCommand){

    pacCommand += "MOVE ";
    pacCommand += to_string(myPacId);
    pacCommand += ' ';
    pacCommand += to_string(targetX);
    pacCommand += ' ';
    pacCommand += to_string(targetY);
}
void takeAction(int &currentX, int &currentY, string &currentType, int &targetX, int &targetY,int &myPacId, string &enemyType, string &pacCommand){

    int oppX,oppY,dist=0,tempi,enemyPacId;

    //enemy available in vision? and how far?

    //if I have ability then all these matters
   // if(temp++ > 1 )
       // cout<<"... MyPAcID = "<<myPacId<<" --> ";
       // cout<<" aboiltyCoolddown = "<<coolDown[myPacId]<<"| ";

    //if enemy is in line of sight then move towards it (without using any ability)
    /*if(inSameCol(currentX, oppX, oppY, enemyType, enemyPacId) || inSameRow(currentY, oppX, oppY, enemyType, enemyPacId)){

           if(inSameCol(currentX, oppX, oppY, enemyType, enemyPacId))
                tempi = abs(currentY - oppY);
            else{
                tempi = abs(currentX - oppX);
                //cout<<" tempi = "<<tempi<<'|';
                //cout<<" sameROW == TRUE | ";
                if(tempi >= midX){
                    dist += findDist(currentX, midX, width);
                    //cout<<"dist = "<<dist<<'|';
                    dist += findDist(oppX, midX, width);
                    //cout<<"dist = "<<dist<<'|';
                    //cout<<"Inside IF ";
                }
                else
                    dist += tempi;
            }

            if(myPacId < pac.size() - 1)
                pacCommand += "|";
            return ;
            }

        }
    */
    if(!coolDown[myPacId]){
    //checking horizontally
        if(inSameCol(currentX, oppX, oppY, enemyType, enemyPacId)){
            //if in same row how far
            tempi = abs(currentY - oppY);
            //cout<<" sameCOL = TRUE | ";
            dist += tempi;

            if(dist <= 2){
                //if my type is able to beat enemy then SPEED
                if(canIDefeatHim(currentType, enemyType))
                    speedUp(myPacId, pacCommand);
                //If I get beaten by enemy then SWITCH
                else
                    Switch(myPacId, enemyType, pacCommand);
            }
            //simply move
            else{
              //  cout<<"SIMPLY MOVE | ";
                //findClosestPellet(currentX,currentY, targetX, targetY);
                targetX = oppX;
                targetY = oppY;
                simplyMove(myPacId, targetX, targetY, pacCommand);
            }
        }
        //checking vertically
        else if(inSameRow(currentY, oppX, oppY, enemyType, enemyPacId)){
            //if in same row how far
            tempi = abs(currentX - oppX);
            //cout<<" tempi = "<<tempi<<'|';
            //cout<<" sameROW == TRUE | ";
            if(tempi >= midX){
                dist += findDist(currentX, midX, width);
                //cout<<"dist = "<<dist<<'|';
                dist += findDist(oppX, midX, width);
                //cout<<"dist = "<<dist<<'|';
                //cout<<"Inside IF ";
            }
            else
                dist += tempi;
            //cout<<"dist = "<<dist<<'|';
            if(dist <= 2){
                //if my type is able to beat enemy then SPEED
                if(canIDefeatHim(currentType, enemyType))
                    speedUp(myPacId, pacCommand);
                //If I get beaten by enemy then SWITCH
                else
                    Switch(myPacId, enemyType, pacCommand);
            }
            //simply move
            else{
                //cout<<"SIMPLY MOVE | ";
                //findClosestPellet(currentX,currentY, targetX, targetY);
                targetX = oppX;
                targetY = oppY;
                simplyMove(myPacId, targetX, targetY, pacCommand);
            }
        }
        else
            speedUp(myPacId, pacCommand);

            /*findClosestPellet(currentX,currentY, targetX, targetY);
            pacCommand += "MOVE ";
            pacCommand += to_string(myPacId);
            pacCommand += ' ';
            pacCommand += to_string(targetX);
            pacCommand += ' ';
            pacCommand += to_string(targetY);
            */

    }
    //if I dont have ability but my enemy is in sight then move towards that enemy to kill it
    else if(coolDown[myPacId]){

        if((inSameCol(currentX, oppX, oppY, enemyType, enemyPacId) || inSameRow(currentY, oppX, oppY, enemyType, enemyPacId)) && canIDefeatHim(currentType, enemyType)){
            targetX = oppX;
            targetY = oppY;

            if(coolDown[myPacId] < dist){
                if(dist <= 2){
                    //if my type is able to beat enemy then SPEED
                    if(canIDefeatHim(currentType, enemyType))
                        speedUp(myPacId, pacCommand);
                    //If I get beaten by enemy then SWITCH
                    else
                        Switch(myPacId, enemyType, pacCommand);
                        //switch and then try to kill enemy
                    // cout<<" SWITCHING | ";
                }
        }
        else if(!((inSameCol(currentX, oppX, oppY, enemyType, enemyPacId) || inSameRow(currentY, oppX, oppY, enemyType, enemyPacId)) && canIDefeatHim(currentType, enemyType))){

            dist = 6;
            if(inSameCol(currentX, oppX, oppY, enemyType, enemyPacId)){
                targetY = (currentY + dist) % height;
                targetX = currentX;
            }
            else if(inSameRow(currentY, oppX, oppY, enemyType, enemyPacId)){
                targetX = (currentX + dist) % width;
                targetY = currentY;
            }
        }
        else
            findClosestPellet(currentX,currentY, targetX, targetY);

         simplyMove(myPacId, targetX, targetY, pacCommand);
    }
    }

    if(myPacId < pac.size() - 1)
        pacCommand += "|";

}
void findTargetCoordinates(int &targetX,int &targetY,int &currentX,int &currentY, string &currentType, string &enemyType, int &myPacId, string &pacCommand){

    /*Actions to be performed

    1. Follow Enemy - Speedup || simply follow
    2. SpeedUp towards a pellet
    3. Runaway from a pellet if you don't have ability to switch
    4. Else simply move towards a super pellet/ Pellet
    */

    //let's select what to do
    takeAction(currentX, currentY, currentType,targetX, targetY, myPacId, enemyType, pacCommand);

}
int main()
{
    cin >> width >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string inp;
        getline(cin, inp); // one line of the grid: space " " is floor, hash "#" is wall
        grid.pb(inp);
    }
    midX = ceil((float)width/2);
   //midY = ceil((float)height/2);
    // game loop
    while (1) {

        bigPellet.clear();
        smallPellet.clear();
        pac.clear();
        oppPac.clear();
        coolDown.clear();
        speedTurns.clear();

        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore; cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount; cin.ignore();
        for (int i = 0; i < visiblePacCount; i++) {
            int pacId; // pac number (unique within a team)
            bool mine; // true if this pac is yours
            int x; // position in the grid
            int y; // position in the grid
            string typeId; // ROCK || PAPER || SCISSORS
            int speedTurnsLeft; // turns left until the effect fades
            int abilityCooldown; // Turns left until you can use any ability
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();

            //need to keep track of pacId as well along with their x and y;
            //let us assume pac number starts from 0; Yes, it works
            if(mine == true){
                pac.pb(mp(pacId, mp( typeId, mp(x,y))));
                coolDown.pb(abilityCooldown);
                speedTurns.pb(speedTurnsLeft);
            }
            else
                oppPac.pb(mp(pacId,mp( typeId, mp(x,y))));
        }
        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount; cin.ignore();

        for (int i = 0; i < visiblePelletCount; i++) {
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value; cin.ignore();
            if(value == 10)
                bigPellet.pb(mp(x,y));
            else
                smallPellet.pb(mp(x,y));
        }

        pacCommand ="";
        for(int i=0; i < pac.size(); i++){
            currentX = pac[i].second.second.first;
            currentY = pac[i].second.second.second;
            currentType = pac[i].second.first;
            int myPacId = pac[i].first;

            findTargetCoordinates(targetX, targetY, currentX, currentY, currentType, enemyType, myPacId, pacCommand);
        }

        cout<<pacCommand<<endl;

    }
}

