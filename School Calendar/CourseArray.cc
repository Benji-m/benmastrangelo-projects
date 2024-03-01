#include <iostream>
#include <iomanip>
#include <string>

#include "CourseArray.h"

using namespace std;

CourseArray::CourseArray()
{
    size = 0;
    nextId = COURSE_ID;
}

CourseArray::~CourseArray()
{
    for (int i = 0; i < size; i++) {
        delete courses[i];
    }
}

void CourseArray::add(Course* c)
{
    if (size >= MAX_ARR) {
        cout << "CourseArray is full" << endl;
        return;
    }

    c->setID(nextId++);

    int i = size - 1;
    while (i >= 0 && c->lessThan(courses[i])) {
        courses[i + 1] = courses[i];
        i--;
    }

    courses[i + 1] = c;
    size++;
}

bool CourseArray::find(int id, Course** c){
    for (int i = 0; i < size; i++){
        if (courses[i]->getID() == id){
            *c = courses[i];
            return true;
        }
    }
    *c = nullptr;
    return false;
}

void CourseArray::print(const string& term)
{
    for (int i = 0; i < size; i++) {
        if (courses[i]->getTerm() == term){
            courses[i]->print();
        }
    }
}