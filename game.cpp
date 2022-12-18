#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

#include "game.h"

#include "fastenemy.h"
#include "slowenemy.h"
#include "userShip.h"

using namespace std;

/*
 * the game itself where the controls will be used to move the user ship and shoot missiles
 * also the enemy will apear after some control ticks depend on the difficulty
 *
 *
*/





game::game() //algemeen:2, 4
{
/*
 * start coordinates for users ship on 16 and 30 to be on the bottom middle of the game area
*/
int yCoordinatesUsership=16;
int xCoordinatesUsership=30;
int tempCoordinates=30;
char controlUsership;

int yCoordinatesSlowEnemy=0;
int yCoordinatesFastEnemy=0;
int xCoordinatesSlowEnemy=0;
int xCoordinatesFastEnemy=0;
int controlEnemy = 0;
/*
 * random number from 1-60 to spawn the enemyships
*/
srand (time(NULL));
xCoordinatesSlowEnemy=rand() % 59+1;
xCoordinatesFastEnemy=rand() % 59+1;

/*
 * prints before the equal game starts
 */
    cout <<"  _     _  _______  ___      _______  _______  __   __  _______  "<< endl;
    cout <<" | | _ | ||       ||   |    |       ||       ||  |_|  ||       | "<< endl;
    cout <<" | || || ||    ___||   |    |       ||   _   ||       ||    ___| "<< endl;
    cout <<" |       ||   |___ |   |    |       ||  | |  ||       ||   |___  "<< endl;
    cout <<" |       ||    ___||   |___ |      _||  |_|  ||       ||    ___| "<< endl;
    cout <<" |   _   ||   |___ |       ||     |_ |       || ||_|| ||   |___  "<< endl;
    cout <<" |__| |__||_______||_______||_______||_______||_|   |_||_______| "<< endl;


    cout <<"  _______  ___      _______  __   __  _______  ______   "<< endl;
    cout <<" |       ||   |    |   _   ||  | |  ||       ||    _ |  "<< endl;
    cout <<" |    _  ||   |    |  |_|  ||  |_|  ||    ___||   | ||  "<< endl;
    cout <<" |   |_| ||   |    |       ||       ||   |___ |   |_||_ "<< endl;
    cout <<" |    ___||   |___ |       ||_     _||    ___||    __  |"<< endl;
    cout <<" |   |    |       ||   _   |  |   |  |   |___ |   |  | |"<< endl;
    cout <<" |___|    |_______||__| |__|  |___|  |_______||___|  |_|"<< endl;
/*
 * set/get name for user ship and difficulty enemy ships before the aqual game starts
 * and filling the double vector and starting the game
*/
    setShips();
    getShips();
    map();
    ModifyMap(yCoordinatesUsership,xCoordinatesUsership);

//----------------------------------Game Start-----------------------------------------------------------------

    for(;;)
    {
 /*
  * printing of the usership to new coordinates (left of right)
  * 'q' for left en 'd' for right for the "azerty" users
  * spacebar to shoot from the usership
*/
        controlUsership=getch();
        if (controlUsership == 'q' && xCoordinatesUsership >1)
        {
            tempCoordinates=xCoordinatesUsership;
            xCoordinatesUsership=tempCoordinates-1;
            gameArea[yCoordinatesUsership][tempCoordinates]=' ';
            ModifyMap(yCoordinatesUsership,xCoordinatesUsership);
        }
        if (controlUsership == 'd' && xCoordinatesUsership <60)
        {
            tempCoordinates=xCoordinatesUsership;
            xCoordinatesUsership=tempCoordinates+1;
            gameArea[yCoordinatesUsership][tempCoordinates]=' ';
            ModifyMap(yCoordinatesUsership,xCoordinatesUsership);
        }
        if (controlUsership == 32)    //spacebar press
        {
            for (int var = 1; var < 16; ++var)
            {
                gameArea[yCoordinatesUsership-var][xCoordinatesUsership]='*';
                ModifyMap(yCoordinatesUsership,xCoordinatesUsership);
                gameArea[yCoordinatesUsership-var][xCoordinatesUsership]=' ';
                ModifyMap(yCoordinatesUsership,xCoordinatesUsership);
/*
 * if the position of the missile is the same as the enemyship the place of the enemy ship will be cleared on the game area
 * also the start position will be reset and will be random.
*/
                if (yCoordinatesUsership-var == yCoordinatesSlowEnemy && xCoordinatesUsership == xCoordinatesSlowEnemy)
                {
                    gameArea[yCoordinatesSlowEnemy][xCoordinatesSlowEnemy]=' ';
                    yCoordinatesSlowEnemy=0;
                    xCoordinatesSlowEnemy= rand() % 59+1;
                }
                if (yCoordinatesUsership-var == yCoordinatesFastEnemy && xCoordinatesUsership == xCoordinatesFastEnemy)
                {
                    gameArea[yCoordinatesSlowEnemy][xCoordinatesFastEnemy]=' ';
                    yCoordinatesFastEnemy=0;
                    xCoordinatesFastEnemy= rand() % 59+1;
                }
            }
        }

/*
 * depent on the input of the user was at the beginning of the game the enemyships will be commoing down fast or slower
*/
        if (slow.getDiff() ==1)
        {
            if (controlEnemy >15)
            {
                gameArea[yCoordinatesSlowEnemy][xCoordinatesSlowEnemy]=' ';
                gameArea[yCoordinatesFastEnemy][xCoordinatesFastEnemy]=' ';
                yCoordinatesSlowEnemy= yCoordinatesSlowEnemy+1;
                yCoordinatesFastEnemy=yCoordinatesFastEnemy+2;
                gameArea[yCoordinatesSlowEnemy][xCoordinatesSlowEnemy]='V';
                gameArea[yCoordinatesFastEnemy][xCoordinatesFastEnemy]='Y';

                controlEnemy=0;
            }
        }
        if (fast.getDiff() ==2)
        {
            if (controlEnemy >10)
            {
                gameArea[yCoordinatesSlowEnemy][xCoordinatesSlowEnemy]=' ';
                gameArea[yCoordinatesFastEnemy][xCoordinatesFastEnemy]=' ';
                yCoordinatesSlowEnemy= yCoordinatesSlowEnemy+1;
                yCoordinatesFastEnemy=yCoordinatesFastEnemy+2;
                gameArea[yCoordinatesSlowEnemy][xCoordinatesSlowEnemy]='V';
                gameArea[yCoordinatesFastEnemy][xCoordinatesFastEnemy]='Y';

                controlEnemy=0;
            }
        }
        ++controlEnemy;

/*
 * if enemyship hits 16 (last line) game ends
 * and loop will exit
*/
        if (yCoordinatesFastEnemy==16 || yCoordinatesSlowEnemy==16)
        {
            break;
        }

    }
        shipName.death();

}


/*
 * filling the double vector game area where the game will be played on
*/

void game::map(void)
{

     gameArea=
     {
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'},
        {'|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '|'}
    };
}


/*
 * clearing the old game area and printing the a fresh one with the new coordinates for the ship and the missiles
*/

void game::ModifyMap(int yCoordinatesUsership, int xCoordinatesUsership)
{
    char testship='^';
    gameArea[yCoordinatesUsership][xCoordinatesUsership]=testship;
    system("CLS");


    for(unsigned int y_as=0; y_as < 17; y_as++)
    {
        for(unsigned int x_as=0; x_as < gameArea[y_as].size(); x_as++)
        {
            cout<<gameArea[y_as][x_as];
        }
        cout<<endl;
    }

}


/*
 * filling in the setters of the ship and difficulty on the game
*/

void game::setShips()
{
    string tempName;
    int enemyType=5;

    cout<<" INSTRUCTIONS "<< endl;
    cout<<"--------------- "<< endl;
    cout<<" 'q' for left"<< endl;
    cout<<" 'd' for right"<< endl;
    cout<<"""spacebar"" to shoot "<< endl;cout<< endl;


    cout << "Hello Player, what is your battleships name?" << endl;
    cin >> tempName;cout << endl;

    shipName.setName(tempName);

    while(enemyType !=1 && enemyType !=2 )
    {
        cout << "what type of enemy do you want ? press '1' for slow and '2' for fast "<< endl;
        cin >> enemyType;

        if (enemyType ==1)
        {
            slow.setDiff(enemyType);
        }
        if (enemyType ==2)
        {
            fast.setDiff(enemyType);
        }
    }
}


/*
 * Printing out the input on the user
*/

void game::getShips()
{
    cout << endl << "battleships name: " << shipName.getName()  << endl;

    if (fast.getDiff() == 2)
    {
        cout << "difficulty level: " << fast.getDiff() << " Be prepared" << endl;
    }

    if (slow.getDiff() == 1)
    {
        cout << "difficulty level: " << slow.getDiff() << " Relax and enjoy" << endl;
    }


    sleep(4); //sleep for 3sec before the game starts (because the terminal will be cleared)
}


