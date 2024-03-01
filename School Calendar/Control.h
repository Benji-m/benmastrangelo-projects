#ifndef CONTROL_H
#define CONTROL_H

#include "School.h"
#include "Schedule.h"
#include "View.h"


/*

Purpose: The purpose of this class is to create a Control object that will be 
  used to control the flow of the program.

You are be able to launch the program, initialize the courses, add a schedule, and find a schedule.
The launch utilizes the View class to display the menu and get the user's input.

*/

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    int numScheds;
    School* school;
    Schedule* scheds[MAX_ARR];

    void initCourses(School*);
    bool addSched(Schedule*);
    bool findSched(string, Schedule**);

};

#endif
