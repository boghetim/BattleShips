#ifndef USERSHIP_H
#define USERSHIP_H
#include <string.h>
#include <iostream>


using namespace std;

class userShip
{
public:
    userShip();
    ~userShip();

    void setName(string newName);
    string getName(void);

    void death();
    void battleship();

private:
    string name;
};

#endif // USERSHIP_H
