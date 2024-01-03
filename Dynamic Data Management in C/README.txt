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

USAGE OF GENERATIVE AI
----------------------


I used Generative Ai (ChatGPT) to implement the addGhostByLikelihood() function.


Prompt for addGhostByLikelihood():  "Give steps to implement addGhostByLikelihood" + specifications for addGhostByLikelihood
Response date: November 11th 2023

Sure, here are the steps to implement the addGhostByLikelihood function:

1) Allocate memory for a new node: 
- Use the malloc function to allocate memory for a new NodeType structure. 
- Check if the allocation was successful.

2) Initialize the node data: 
- Set the ghost field of the Node to the Ghost that’s passed as an argument to the function. 
- Set the next field of the Node to NULL.

3) Insert the node into the list: 
- If the list is empty (i.e., the head of the list is NULL), or if the likelihood of the new Ghost
 is greater than the likelihood of the Ghost at the head of the list, insert the new Node at the head of the list.
- If the list was empty, also set the tail of the list to the new node.

4) If the list is not empty and the likelihood of the new Ghost is less than or equal to the likelihood of the Ghost at the head of the list, 
	find the correct position in the list to insert the new Node. This is done by starting at the head of the list and moving to the next node as 
	long as the next node is not NULL and its Ghost’s likelihood is greater than the likelihood of the new Ghost.

5) Once the correct position is found, insert the new Node at that position. 
	This is done by setting the next field of the new Node to the next field of the current node, 
	and then setting the next field of the current node to the new Node.

6) If the new Node is the last node in the list (i.e., its next field is NULL), also set the tail of the list to the new node.


This function effectively inserts a Ghost into a GhostList in descending order based on the likelihood field. 
	The GhostList maintains a reference to the first (head) and last (tail) elements for efficient operations. 
	If the memory allocation for the new Node fails, the function does nothing.

Please note that the memory allocated for the Node should be freed when it’s no longer needed to prevent memory leaks. 
	This is typically done in a cleanup or delete function. If you have any other questions or need further clarification, feel free to ask! 


----------------------
