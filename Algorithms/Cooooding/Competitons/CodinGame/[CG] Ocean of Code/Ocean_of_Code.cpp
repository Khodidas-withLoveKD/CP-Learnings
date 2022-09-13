#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
enum direction{N=1,S,E,W};
int width;
int height;
int myId;
int x;
int y;
int myLife;
int oppLife;
int torpedoCooldown;
int sonarCooldown;
int silenceCooldown;
int mineCooldown;
string line[15],myline[15];
string sonarResult;
string opponentOrders;

int start_x,start_y;
int oppSector;
int firex,firey;
int torpedocount;
bool start_flag=false;
char oppDirection,oppTorpedoX,oppTorpedoY;
direction dir;

bool north()
{
    cout<<"INSIDE NORTH"<<endl;
    if(y>0)
        if(y==3 || myline[y-1][x]=='#' || myline[y-1][x]=='x'){
        cout<<"IF"<<endl;

        return false;
    }

    else
        {
            y=y-1;
            myline[y][x]='#';
            cout<<"MOVE N TORPEDO"<<endl;
            torpedocount++;
            return true;
        }
    else{
            cout<<"INSIde ELSE"<<endl;
            return false;
        }
}
bool south()
{
    cout<<"INSIDE SOUTH"<<endl;

    if(y==11 || myline[y+1][x]=='#' || myline[y+1][x]=='x')
        return false;
    else
        {
            y=y+1;
            myline[y][x]='#';
            cout<<"MOVE S TORPEDO"<<endl;
            torpedocount++;
            return true;
        }
}
bool east()
{
    cout<<"INSIDE EAST"<<endl;

    if(x==11 || myline[y][x+1]=='#' || myline[y][x+1]=='x')
        return false;
    else
        {
            x=x+1;
            myline[y][x]='#';
            cout<<"MOVE E TORPEDO"<<endl;
            torpedocount++;
            return true;
        }
}
bool west()
{
    cout<<"INSIDE WEST"<<endl;

    if(x==3 || myline[y][x-1]=='#' || myline[y][x-1]=='x')
        return false;
    else
        {
            x=x-1;
            myline[y][x]='#';
            cout<<"MOVE W TORPEDO"<<endl;
            torpedocount++;
            return true;
        }
}
void surface()
{
    for(int i=0;i<height;i++)
            myline[i]=line[i];

    cout<<"SURFACE"<<endl;
}
void move_torpedo(char c)
{
    if(c=='N')
        dir=N;
    else if(c=='S')
        dir=S;
    else if(c=='E')
        dir=E;
    else if(c=='W')
        dir=W;
    switch(dir)
    {
        case 1:
                if(north());
                else if(south());
                else if(west());
                else if(east());
                else
                    surface();
                break;
        case 2:
                if(south());
                else if(north());
                else if(east());
                else if(west());
                else
                    surface();
                break;
        case 3:
                if(east());
                else if(west());
                else if(south());
                else if(north());
                else
                    surface();
                break;
        case 4:
                if(west());
                else if(east());
                else if(north());
                else if(south());
                else
                    surface();
                break;
    }


}
void fire_torpedo(int firey, int firex)
{
    cout<<"TORPEDO "<<firey<<" "<<firex<<endl;
    torpedocount=0;
}
void my_move(char oppDirection)
{
    if(oppDirection=='N')
    {
        if(y==3)
        {
            if(torpedocount>=3)
             {
                firey=y-2;
                firex=x;
                fire_torpedo(firey,firex);
             }
            else
                move_torpedo('S');
        }
        else
            move_torpedo('N');
    }
    else if(oppDirection=='S')
    {
        if(y=11)
        {
            if(torpedocount>=3)
            {
                firey=y+2;
                firex=x;
                fire_torpedo(firey,firex);
            }
            else
                move_torpedo('N');
        }
        else
            move_torpedo('S');
    }
   else if(oppDirection=='E')
    {
        if(x==11)
        {
            if(torpedocount>=3)
            {
                firey=y;
                firex=x+2;
                fire_torpedo(firey,firex);
            }
            else
                move_torpedo('W');

        }
        else
            move_torpedo('E');
    }
    else if(oppDirection=='W')
    {
        if(x==3)
        {
         if(torpedocount>=3)
            {
                firey=y;
                firex=x-2;
                fire_torpedo(firey,firex);
            }
            else
                move_torpedo('E');
        }
        else
            move_torpedo('W');
    }
}
void trace_opponent_actions()
{
    if(opponentOrders[0]=='N' && opponentOrders[1]=='A'){
        cout<<"NA malyu"<<endl;
        move_torpedo('N');
    }
    else
        for(int i=0;i<opponentOrders.length();i++)
        {   //tracing opponent cordinates;
            if(opponentOrders[i]=='M')
                {
                    i=i+5;
                    oppDirection=opponentOrders[i];
                    my_move(oppDirection);
                    break;
                }
            //tracing if he fired torpedo
            else if(opponentOrders[i]=='T')
                {
                    i=i+8;
                    oppTorpedoX=opponentOrders[i];
                    i=i+2;
                    oppTorpedoY=opponentOrders[i];
                    break;
                }
            //checking if the opponent surfaced
            else if(opponentOrders[i]=='S')
                {
                    i=i+8;
                    oppSector= opponentOrders[i] - '0';
                    cout<<"Inside Surface"<<endl;
                }
        }
}
void check_start()
{
    for(int i=start_y;i<height;i++)
        for(int j=start_x;j<width;j++)
        {
            if(myline[i][j]=='.')
                {
                    cout<<i<<" "<<j<<endl;
                    start_flag=true;
                    return;
                }
        }
}
int main()
{
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    cin >> width >> height >> myId; cin.ignore();
    cout<<"width="<<width<<endl;
    cout<<"height="<<height<<endl;
    cout<<"myID="<<myId<<endl;
    for (int i = 0; i < height; i++) {
        getline(cin, line[i]);
        myline[i]=line[i];
    }

    /*for (int i = 0; i < height; i++)
        {
            for(int j=0;j<width;j++)
            cout<<myline[i][j]<<" ";
        cout<<endl;
        }*/

    //Planning where to start;
    if(myId==0)
        {
            int lowest=0,range=15;
            start_x=lowest + rand()%range;
            start_y=lowest + rand()%range;
             cout<<"----------------------"<<endl;
            check_start();

            if(start_flag==false)
            {
                start_x=0;start_y=0;
                check_start();
            }
        }

    // game loop
        int t=4;
        while (t--) {

        cout<<"Inside gameLoop"<<endl;
        //cin >> x >> y >> myLife >> oppLife >> torpedoCooldown >> sonarCooldown >> silenceCooldown >> mineCooldown; cin.ignore();
        //cin >> sonarResult; cin.ignore();
        cout<<"Give Opponent Oreder: ";
        getline(cin, opponentOrders);

        cout<<opponentOrders<<endl;
        trace_opponent_actions();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
    }
}
