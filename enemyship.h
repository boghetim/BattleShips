#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <iostream>
#include <string>

using namespace std;

class enemyShip //base class
{
public:
    enemyShip();
    virtual ~enemyShip(){};
    virtual void Mode(void)=0; //member function with virtual function (hard/easy mode)

    void setDiff(int newDiff);
    int getDiff(void);

protected:
    int difficulty;
};

#endif // ENEMYSHIP_H
