#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

#include "game.h"

#include "fastenemy.h"
#include "slowenemy.h"
#include "userShip.h"

using namespace std;

game::game()
{
/*
 * start coordinates for users ship
*/
int yCoordinates=16;
int xCoordinates=30;
int tempCoordinates=30;
int movementEnemySlow=0;
int movementEnemyFast=0;
char arrow;

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
 * set/get name for user ship
 * set/get difficulty enemy ships
*/
    setShips();
    getShips();
/*
 * filling in gameArea
 * starting user ship on 15-30 location on the map
*/
    map();
    ModifyMap(yCoordinates,xCoordinates);

//----------------------------------Game Start-----------------------------------------------------------------

int controlEnemy = 0;

    for(;;)  //kan boolen van gemaakt worden
    {
 /*
  * printing of the usership to new coordinates (left of right)
  * 'q' for left en 'd' for right for the "azerty" users
  * spacebar to shoot from the usership
*/
        usleep(30000);
        arrow=getch();
        if (arrow == 'q' && xCoordinates >1)
        {
            tempCoordinates=xCoordinates;
            xCoordinates=tempCoordinates-1;
            gameArea[yCoordinates][tempCoordinates]=' ';
            ModifyMap(yCoordinates,xCoordinates);
        }
        if (arrow == 'd' && xCoordinates <60)
        {
            tempCoordinates=xCoordinates;
            xCoordinates=tempCoordinates+1;
            gameArea[yCoordinates][tempCoordinates]=' ';
            ModifyMap(yCoordinates,xCoordinates);
        }
        if (arrow == 32)    //spacebar press
        {
            for (int var = 1; var < 16; ++var)
            {
             gameArea[yCoordinates-var][xCoordinates]='*';
             ModifyMap(yCoordinates,xCoordinates);
             gameArea[yCoordinates-var][xCoordinates]=' ';
             ModifyMap(yCoordinates,xCoordinates);
             if (yCoordinates == movementEnemyFast)
             {
//-------------to do ------- een waarde mss boolen gebruiken voor enemy ship te resetten
             }
            }
        }
/*
 * Slow enemy -> 'V'
 * Fast enemy -> 'Y'
*/      if (controlEnemy >10)
        {
//-------------to do ------- kijken naar 'Mode' voor een van de 2 op te roepen
        gameArea[movementEnemySlow][xCoordinates]=' ';
        gameArea[movementEnemyFast][xCoordinates]=' ';
        movementEnemySlow++;
        movementEnemyFast=movementEnemyFast+2;
        gameArea[movementEnemySlow][xCoordinates]='V';
        gameArea[movementEnemyFast][xCoordinates]='Y';
/* -------------to do -------
        if (waarde regel 94 = true)
        {
          movementEnemyFast=0;
          x waarde voor enemy= random getal      //reset plaats
        }

  */

 /*  -------------to do -------

   hoe X as random maken en tot hij dood is?
   - vaste aantal enemys maken vb 5 waarvan 5 variable maken die heel de tijd gereset worden bij door gaat (regel 110)?

   */
        controlEnemy=0;
        }
        ++controlEnemy;
/*
 * if enemyship hits 15 (last line) game ends
 * and loop will exit
*/
        if (movementEnemyFast==16)
        {
            break;
            cout << "exit" <<endl;
        }

    }
        cout << "exit 2" <<endl;

}



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

void game::ModifyMap(int yCoordinates, int xCoordinates)
{
    char testship='^';
    gameArea[yCoordinates][xCoordinates]=testship;
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

void game::setShips()
{
    string tempName;
    int enemyType=5;

    cout << "Hello Player, what is your battleships name?" << endl;
    cin >> tempName;

    shipName.setName(tempName);

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

void game::getShips()
{

    cout << endl << "battleships name: " << shipName.getName()  << endl;

    if (fast.getDiff() == 2)
    {
        cout << endl << "difficulty level: " << fast.getDiff() << " Be prepared" << endl;
    }

    if (slow.getDiff() == 1)
    {
        cout << endl << "difficulty level: " << slow.getDiff() << " Relax and enjoy" << endl;
    }
    sleep(3);
}


