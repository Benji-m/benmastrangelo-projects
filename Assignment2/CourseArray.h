#ifndef COURSEARRAY_H
#define COURSEARRAY_H

#include "defs.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


/*

Purpose: The purpose of this class is to create a CourseArray object that will be 
  used to store the courses that are offered at the school. 

You are be able to add a course, find a course, and print the courses.

*/


class CourseArray
{
    public:
        CourseArray();
        ~CourseArray();
        void add(Course* c);
        void print(const string&);
        bool find(int id, Course** c);

    private:
        Course* courses[MAX_ARR];
        int     size;
        int     nextId;
};

#endif