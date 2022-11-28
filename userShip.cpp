#include "userShip.h"
#include <iostream>

using namespace std;

userShip::userShip()
{

}

userShip::~userShip()
{

}

void userShip::setName(string newName)
{
    name = newName;
}

string userShip::getName()
{
    return name;
}





void userShip::death()
{
    cout <<"  _______  _______  __   __  _______    _______  __   __  _______  ______ "<< endl;
    cout <<" |       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  "<< endl;
    cout <<" |    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  "<< endl;
    cout <<" |   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_   "<< endl;
    cout <<" |   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |  "<< endl;
    cout <<" |   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |  "<< endl;
    cout <<" |_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|  "<< endl;


}


void userShip::battleship()
{
 cout <<" ^  "<< endl;
 cout <<"| |  "<< endl;
 cout <<"/ \\  "<< endl;
}
