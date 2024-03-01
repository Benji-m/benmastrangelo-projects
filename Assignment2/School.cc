#include "School.h"

using namespace std;

School::School(string name){
    this->name = name;
    cout << "School " << name << " is being created." << endl;
}

School::~School(){
    cout << "School " << name << " is being deleted." << endl;
}

void School::addCourse(Course* course){
    courses.add(course);
}

bool School::findCourse(int id, Course** course){
    return courses.find(id, course);
}

void School::printCourses(string term){
    courses.print(term);
}