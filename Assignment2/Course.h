#ifndef COURSE_H
#define COURSE_H

#include "defs.h"
#include "Time.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/*

Purpose: The purpose of this class is to create a Course object that will be 
  used to store the term, subject, code, section, instructor, and days of the course.

You are be able to print the course, compute the days of the course, compute the slot of the course, 
  and compare the course to another course.

*/



class Course
{
    public:
        Course(string="", string="", int=0, char=' ', string="", LectDaysType = BAD_LECT_DAYS, int=0, int=0);
        ~Course();
        void print();
        bool computeDays(WeekDayType& day1, WeekDayType& day2);
        bool computeSlot(TimeSlotType& slot);
        bool lessThan(Course*);
        int getID();
        string getTerm();
        string getInstructor();
        string getCourseCode();
        void setID(int);

        string lectDaysToString(LectDaysType);

    private:
        Time* time; // don't know if this is correct
        int id;
        string term;
        string subject;
        int code;
        char section;
        string instructor;
        LectDaysType days;

};

#endif