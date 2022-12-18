#ifndef USERSHIP_H
#define USERSHIP_H
#include <string.h>
#include <iostream>


using namespace std;

class userShip
{
public:
    userShip();
    ~userShip(); //oop: 4 (2/2)

    void setName(string name);  //oop:12
    string getName(void);

    void death();
    void battleship();

private:    //algemeen: 3
    string name;
};

#endif // USERSHIP_H
