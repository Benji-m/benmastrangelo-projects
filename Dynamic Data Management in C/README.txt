AUTHOR:
-------

BENJAMIN MASTRANGELO    
101270320

-------

PURPOSE:
--------

This program acts almost as a game or simulation. The purpose of this program is to resemble a building with a bunch of different rooms,
and in those rooms you can find a number of different ghosts with their own attributes. This program is interactive, allowing the user
to select a number of different commands via the menu displayed when executing the program.

--------

LIST OF FILES:
--------------

main.c
building.c
room.c
ghost.c
defs.h
README.txt

--------------

COMPILING INSTRUCTIONS:
-----------------------

gcc -Wall -Wextra -o a4 main.c ghost.c room.c building.c

-----------------------

RUNNING INSTRUCTIONS:
---------------------

./a4
valgrind --leak-check=full ./a4

---------------------

HOW TO USE THE PROGRAM
----------------------

Start by compiling and running. Once done, the user will notice an interactive menu in the terminal.

1) Typing '1' will print all the rooms in the building along with every ghost situated in each room.
2) Typing '2' will print every ghost in the building in an unsorted manner.
3) Typing '3' will print every ghost in the building sorted from likelihood (most likely to least).
4) Typing '4' will print the ghost with the highest likelihood and the ghost with the lowest likelihood. 
0) Typing '0' will terminate the program.

If the user enters an unvalid number, the user will be prompted once again.

----------------------
