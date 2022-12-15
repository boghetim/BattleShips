# BattleShips
Cpp spacegame where u can shoot enemyships (played in terminal)

>WIP steps:

- welcome text with cartoon

- you can name your BattleShip and choice the difficulty of the game.
(option to select what Battleship you want -> DLC)

- the game will start 
(see the "gameplay" section of the readme)

- after u died in the game a goodbye text with some funny cartoon

>GAMEPLAY:

- the BattleShip can move left and right (with 'q' and 'd')
and u can shoot ('*') with the spacebar
(up and down -> DLC)

- the enemy Ships will come from above vertically down in slow or fast pace, depend on the difficulty u picked
(both difficulty will be slow and fast ships mixed -> DLC)

>making of the project:

First making the classes of the ships -> enemy ship and user ship.
Making an inheritance from enemy ship for slow and fast enemy ship.
Creating the game class where the game will be played in this with object composition with al ships in it
this with some default and parameterized constructors and the destructors.

After the classes are done we can make some functions and variabels

For the "enemyship" "Mother" class we set some functions for the "Mode" u wane play at.
This with getter and setter for choosing the difficulty (difficulty in protected)
and the name in private protection.
The "Mode" function is virtual because it can be use for both fast en slow enemy ship.
Also the value in "enemyship" is set on '0' to not be used in the base class.

For the fast en slow enemy almost everything was inherit from the "enemyship"
For the fast enemy we picked a static name in exception to the slow enemy.

In the "userShip" class we user some functions for the name through the getter and setter.
And the "death" function for when the usership is failed in hes mission and the game is game over.

For the game function we have some function for reading the map of the game.
Here we will read a double vector for determine the size of the game area
and we used a private member variabel for it so we can use it more freely.
We also made some variale for other class inputs for choosing the difficulty and picking up a name.

in the Game.cpp file we first print some welcome text and after asking and filling the name and difficulty from user input we go to the game.
after filling in the game area in the double vectors and clearing the terminal the game can begin.

This with starting the user ship on the bottom middle of the area.
after the controls for left and right the char for the ship will move in the "gameArea" vector.
And overwriting the old coordinates with blanks, same with the shooting of the ship.
while the ship only can move left and right within the area the missiles only goes from the bottom to the top starting from location of the ship.
after some movement ticks the enemy will appear on the top of the area and will go down in linear movement.

If the enemy is shot down he will reappear on the top on the area if not and the enemy gets to the bottom the game end.
The loop for the game will exit and the "GAME OVER" text will appear.






