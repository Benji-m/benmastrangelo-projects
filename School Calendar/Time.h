#ifndef TIME_H
#define TIME_H

#include "defs.h"
#include <string>

/*

PURPOSE: The purpose of this class is to create a Time object that will be used to store the time 
  of a course.
You are be able to set the time, print the time, convert the time to minutes, 
  compute the time slot, and set the time from a time slot.

*/

class Time
{
  public:
    Time(int=0, int=0);
    void print();
    bool computeSlot(TimeSlotType& slot);
    bool setFromSlot(TimeSlotType slot); 

    

  private:
    int  hours;
    int  minutes;
    void set(int, int);
    int  convertToMins();
};

#endif
