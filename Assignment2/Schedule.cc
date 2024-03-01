#include <iostream>
#include <iomanip>
#include <string>

#include "Schedule.h"

using namespace std;

Schedule::Schedule(string term){
    this->term = term;

    for (int i = 0; i < NUM_DAYS; i++){
        for (int j = 0; j < NUM_SLOTS; j++){
            schedule[i][j] = nullptr;
        }
    }
}

bool Schedule::addCourse(Course* course){
    if (course == nullptr){
        cout << "Error, the course is null." << endl;
        return false;
    }

    if (course->getTerm() != term){
        cout << "Error, the term does not match." << endl;
        return false;
    }

    WeekDayType day1, day2;
    if (!course->computeDays(day1, day2)){
        cout << "Error, the days are not valid." << endl;
        return false;
    }

    TimeSlotType slot;
    if (!course->computeSlot(slot)){
        cout << "Error, the time slot is not valid." << endl;
        return false;
    }

    // maybe change this part
    if (schedule[day1][slot] != nullptr || schedule[day2][slot] != nullptr){
        cout << "Error, there is a conflict." << endl;
        return false;
    }

    schedule[day1][slot] = course;
    schedule[day2][slot] = course;
    return true;
}


void Schedule::print(){
  const char *weekDays[5] = {"MON", "TUE", "WED", "THU", "FRI"};
  Time times[7] = {Time(8, 30), Time(10, 0), Time(11, 30), Time(13, 0), Time(14, 30), Time(16, 0), Time(18, 0)};

  int scheduleWidth = 107;

  cout << "Schedule for current term: " << term << endl;
  
  cout << string(scheduleWidth, '-') << endl;

  cout << "|";
  for(int i = 0; i < 5; i++) {
    cout << string(15, ' ');
    cout << weekDays[i];
  }
  cout << string(15, ' ');
  cout << "|" << endl;

  for(int i = 0; i < scheduleWidth; i++) {
    cout << "-";
  }
  cout << endl;

  for(int i = 0; i < 7; i++) {
    for(int j = 0; j < 3; j++) {
      cout << "| ";
      if(j == 0) {
        times[i].print();
      } else {
        cout << "     ";
      }
      cout << " |       ";

      for(int k = 0; k < 5; k++) {
        if(schedule[k][i] == NULL) {
          cout << setfill(' ') << setw(18) << " ";
          continue;
        }

        if(j == 0) {
          cout << left << setfill(' ') << setw(18) << schedule[k][i]->getCourseCode();
        } 
        else if(j == 1) {
          cout << "CN:  " << setfill(' ') << setw(13) << schedule[k][i]->getID();
        } 
        else {
          cout << "Pr:  " << setfill(' ') << setw(13) << schedule[k][i]->getInstructor();
        }
      }
      cout << "|\n";
    }

    cout << (i == 6 ? "-" : "|");
    cout << string(scheduleWidth - 2, '-') << (i == 6 ? "-" : "|\n");
  }
}


void Schedule::clear(){
    for (int i=0; i < NUM_DAYS; i++){
        for (int j = 0; j < NUM_SLOTS; j++){
            schedule[i][j] = nullptr;
        }
    }
}

string Schedule::getTerm(){
    return term;
}
