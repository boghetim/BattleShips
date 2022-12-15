#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

#include <iostream>
#include <string>

using namespace std;

class enemyShip
{
public:
    enemyShip(){};
    enemyShip(string name);  //oop:2  (1/2)
    virtual ~enemyShip(){}; //oop:4 (1/2)
    virtual void Mode(void)=0; //oop: 10

    void setDiff(int newDiff);
    int getDiff(void);

protected:
    int difficulty;
private:
    string name;
};

#endif // ENEMYSHIP_H

