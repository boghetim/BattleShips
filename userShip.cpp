#include "userShip.h"
#include <iostream>

using namespace std;

userShip::userShip() //oop: 2 parameterized van maken
{

}

userShip::~userShip()
{

}

void userShip::setName(string name)
{
    this->name=name;    //oop:8
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


