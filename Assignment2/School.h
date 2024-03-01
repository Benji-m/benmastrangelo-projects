#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>

#include "defs.h"
#include "Course.h"
#include "CourseArray.h"

using namespace std;

/*

Purpose: The purpose of this class is to create a School object that will be 
  used to store the name of the school and the courses that are offered at the school.

You are be able to add a course, find a course, and print the courses.

*/

class School
{
  public:
    School(string);
    ~School();
    void addCourse(Course*);
    bool findCourse(int, Course**);
    void printCourses(string);

  private:
    string name;
    CourseArray courses;
    
};

#endif
