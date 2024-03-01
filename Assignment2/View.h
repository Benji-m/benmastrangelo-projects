#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>

using namespace std;


/*

Purpose: This class is responsible for the user interface. It will display the menu,
   prompt the user for input, and display output.

*/


class View
{
  public:
    void showMenu(int&);
    void printStr(string);
    void readInt(int&);
    void readStr(string&);
};

#endif
