#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "defs.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/*

Purpose: The purpose of this class is to create a Schedule object that will be 
  used to store the term and the courses that are offered in the term.

You are be able to add a course, print the schedule, and clear the schedule.

*/


class Schedule
{
    public:
        Schedule(string = "");
        bool addCourse(Course*);
        void print();
        void clear();
        string getTerm();

    private:
        string term;
        Course* schedule[NUM_DAYS][NUM_SLOTS];
    
};

#endif