#include <iostream>
#include <string.h>

#include "game.h"

#include "fastenemy.h"
#include "slowenemy.h"
#include "userShip.h"

using namespace std;

game::game()
{
    cout <<"  _     _  _______  ___      _______  _______  __   __  _______    _______  ___      _______  __   __  _______  ______   "<< endl;
    cout <<" | | _ | ||       ||   |    |       ||       ||  |_|  ||       |  |       ||   |    |   _   ||  | |  ||       ||    _ |  "<< endl;
    cout <<" | || || ||    ___||   |    |       ||   _   ||       ||    ___|  |    _  ||   |    |  |_|  ||  |_|  ||    ___||   | ||  "<< endl;
    cout <<" |       ||   |___ |   |    |       ||  | |  ||       ||   |___   |   |_| ||   |    |       ||       ||   |___ |   |_||_ "<< endl;
    cout <<" |       ||    ___||   |___ |      _||  |_|  ||       ||    ___|  |    ___||   |___ |       ||_     _||    ___||    __  |"<< endl;
    cout <<" |   _   ||   |___ |       ||     |_ |       || ||_|| ||   |___   |   |    |       ||   _   |  |   |  |   |___ |   |  | |"<< endl;
    cout <<" |__| |__||_______||_______||_______||_______||_|   |_||_______|  |___|    |_______||__| |__|  |___|  |_______||___|  |_|"<< endl;
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

}


