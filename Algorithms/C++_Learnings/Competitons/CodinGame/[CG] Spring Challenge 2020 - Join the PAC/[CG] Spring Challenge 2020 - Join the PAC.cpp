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
- [DONE] Remove the marked pellet from vector
-It is not good idea to remove pellet from vector because if one pac is closer to
 it still other pac has also that pellet as closest then there may be case that
 the closest one will not get chance to eat it
- Collision?
 */
int width; // size of the grid
int height; // top left corner is (x=0, y=0)
vector<string> row;
vector< pair<int,int> > bigPellet,smallPellet,pac;
int targetX,targetY,currentX,currentY,midX,midY;
string pacCommand;
int temp=0;

int findDist(int coordinate, int mid, int range){

    if(coordinate >= mid)
        return (range - coordinate -1);        //It seems like it should be range - coordinate + 1 but let's keep it this way for now;

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
    if(y >= midY){
        distY += findDist(currentY, midY, height);
        distY += findDist(pelletY, midY, height);
    }
    else
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
            if(bigPellet[i].first == targetX){
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
            if(smallPellet[i].first == targetX){
                mark=i;
                break;
            }
    smallPellet.erase(smallPellet.begin() + mark);
    }
    temp++;
}
void findTargetCoordinates(int &targetX,int &targetY,int &currentX,int &currentY){


    findClosestPellet(currentX,currentY, targetX, targetY); //pelletX,pelletY);

}
int main()
{
    cin >> width >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string inp;
        getline(cin, inp); // one line of the grid: space " " is floor, pound "#" is wall
        row.pb(inp);
    }
    midX = ceil((float)width/2);
    midY = ceil((float)height/2);
    // game loop
    while (1) {

        bigPellet.clear();
        smallPellet.clear();
        pac.clear();
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
            string typeId; // unused in wood leagues
            int speedTurnsLeft; // unused in wood leagues
            int abilityCooldown; // unused in wood leagues
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown; cin.ignore();
            //need to keep track of pacId as well along with their x and y;
            //let us assume pac number starts from 0;
            if(mine == true){
                pac.pb(mp(x,y));
            }
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
            currentX = pac[i].first;
            currentY = pac[i].second;
            findTargetCoordinates(targetX, targetY, currentX, currentY);

            pacCommand += "MOVE ";
            pacCommand += to_string(i);
            pacCommand += ' ';
            pacCommand += to_string(targetX);
            pacCommand += ' ';
            pacCommand += to_string(targetY);

            if(i < pac.size() - 1)
                pacCommand += "|";
        }

        cout<<pacCommand<<endl;

    }
}
