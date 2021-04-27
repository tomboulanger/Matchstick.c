# Matchstick - Leave the last matchstick!

- **Binary name:** matchstick
- **Language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

This project is based on a very famous game based on matchsticks.<br />
There is a certain number of matchstick lines.<br />
The two players take turns; each player can, on a same line, take one or several matchsticks.<br />
The losing player is the one to take the last matchstick.

The goal of the project is to create a program that you can play against.
The basic version must generate a game board with n matchstick lines (1 < n < 100) and have a simple interface so that the user could play against the computer.

The number of lines is given as parameter to the program.
The second parameter of the program indicates the maximum number of matches that can be taken out each turn (must be > 0).<br />
When matchsticks are removed, they must be removed starting from the right (like in the example below).<br />
The user will always start the game.

The program’s output (error messages included) must correspond to the examples below. Error messages which happens during a game and which are destined to the player must be displayed on the standard output.<br />
In case of bad input, you must ask for the line by displaying **Line:** " again, and it’s up to the player to indicate again the line he/she wants to play on.

> :exclamation: If the user wins, the program must return 1.<br />
> If the AI wins, it must return 2.

# Examples

```
∼/B-CPE-200> ./matchstick 4 5
*********
*   |   *
*  |||  *
* ||||| *
*|||||||*
*********

Your turn:
Line: 4
Matches: 2
Player removed 2 match(es) from line 4
*********
*   |   *
*  |||  *
* ||||| *
*|||||  *
*********

AI's turn...
AI removed 2 match(es) from line 3
*********
*   |   *
*  |||  *
* |||   *
*|||||  *
*********

Your turn:
Line: 1
Matches: 1
Player removed 1 match(es) from line 1
*********
*       *
*  |||  *
* |||   *
*|||||  *
*********

AI's turn...
AI removed 1 match(es) from line 2
*********
*       *
*  ||   *
* |||   *
*|||||  *
*********

Your turn:
Line: 12
Error: this line is out of range
Line: 2
Matches: 2
Player removed 2 match(es) from line 2
*********
*       *
*       *
* |||   *
*|||||  *
*********

AI's turn...
AI removed 2 match(es) from line 4
*********
*       *
*       *
* |||   *
*|||    *
*********

Your turn:
Line: 4
Matches: 7
Error: you cannot remove more than 5 matches per turn
Line: 3
Matches: 1
Player removed 1 match(es) from line 3
*********
*       *
*       *
* ||    *
*|||    *
*********

AI's turn...
AI removed 2 match(es) from line 3
*********
*       *
*       *
*       *
*|||    *
*********

Your turn:
Line: 4
Matches: 2
Player removed 2 match(es) from line 4
*********
*       *
*       *
*       *
*|      *
*********

AI's turn...
AI removed 1 match(es) from line 4
*********
*       *
*       *
*       *
*       *
*********
I lost... snif... but I'll get you next time!!

∼/B-CPE-200> echo $?
1
```

```
∼/B-CPE-200> ./matchstick 2 10
*****
* | *
*|||*
*****

Your turn:
Line: 1
Matches: 1
Player removed 1 match(es) from line 1
*****
*   *
*|||*
*****

AI's turn...
AI removed 2 match(es) from line 2
*****
*   *
*|  *
*****

Your turn:
Line: 2
Matches: 1
Player removed 1 match(es) from line 2
*****
*   *
*   *
*****
You lost, too bad...

∼/B-CPE-200> echo $?
2
```

```
∼/B-CPE-200> ./matchstick 2 5
*****
* | *
*|||*
*****

Your turn:
Line: 0
Error: this line is out of range
Line: %

∼/B-CPE-200> ./matchstick 2 5
*****
* | *
*|||*
*****

Your turn:
Line: aze
Error: invalid input (positive number expected)
Line: 2

...

*****
* | *
*|  *
*****

Your turn:
Line: 1
Matches: 0
Error: you have to remove at least one match
Line: 1
Matches: aze
Error: invalid input (positive number expected)
Line: 1
Matches: 3
Error: not enough matches on this line
```

## Authorized functions

- read, write, malloc, free, time, getpid, random, srandom and getline

