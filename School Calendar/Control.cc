#include <iostream>
using namespace std;
#include <string>

#include "Control.h"

Control::Control(){
  numScheds = 0;
  school = new School("Carleton U. School of Computer Science");

  for (int i = 0; i < MAX_ARR; i++){
    scheds[i] = nullptr;
  }
}

Control::~Control(){
  for (int i = 0; i < numScheds; i++){
    delete scheds[i];
  }
  delete school;
}

bool Control::addSched(Schedule* sched){
  if (numScheds == MAX_ARR){
    cout << "Error, the array is full." << endl;
    return false;
  }

  if (sched == nullptr){
    cout << "Error, the schedule is null." << endl;
    return false;
  }

  scheds[numScheds++] = sched;
  return true;
}

bool Control::findSched(string term, Schedule** sched){
  for (int i = 0; i < numScheds; ++i){
    if (scheds[i] != nullptr && scheds[i]->getTerm() == term){
      *sched = scheds[i];
      return true;
    }
  }
  *sched = nullptr;
  return false; 
}


void Control::initCourses(School* sch)
{
  sch->addCourse(new Course("F23", "COMP", 2401, 'A', "Laurendeau", TUE_THU, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'B', "Hillen", WED_FRI, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'C', "Laurendeau", MON_WED, 13, 0));
  sch->addCourse(new Course("F23", "COMP", 2401, 'D', "Hillen", TUE_THU, 8, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'A', "Shaikhet", TUE_THU, 11, 30));
  sch->addCourse(new Course("F23", "COMP", 2402, 'B', "Shaikhet", MON_WED, 10, 0));
  sch->addCourse(new Course("F23", "COMP", 2404, 'A', "Hill", MON_WED, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2404, 'B', "Hill", MON_WED, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'A', "Nel", TUE_THU, 16, 0));
  sch->addCourse(new Course("F23", "COMP", 2406, 'B', "Shaikhet", TUE_THU, 18, 0));
  sch->addCourse(new Course("F23", "COMP", 2804, 'A', "Morin", TUE_THU, 14, 30));
  sch->addCourse(new Course("F23", "COMP", 2804, 'B', "Hill", MON_WED, 8, 30));

  sch->addCourse(new Course("W24", "COMP", 2401, 'A', "CI", MON_WED, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2401, 'B', "Lanthier", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'A', "Sharp", WED_FRI, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2402, 'B', "Sharp", TUE_THU, 14, 30));
  sch->addCourse(new Course("W24", "COMP", 2404, 'A', "Hill", TUE_THU, 16, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'B', "Laurendeau", TUE_THU, 13, 0));
  sch->addCourse(new Course("W24", "COMP", 2404, 'C', "Laurendeau", MON_WED, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'A', "Nel", TUE_THU, 10, 0));
  sch->addCourse(new Course("W24", "COMP", 2406, 'B', "Nel", MON_WED, 18, 0));
  sch->addCourse(new Course("W24", "COMP", 2804, 'A', "Hill", TUE_THU, 8, 30));
  sch->addCourse(new Course("W24", "COMP", 2804, 'B', "Hill", WED_FRI, 16, 0));
}

void Control::launch(){
  initCourses(school);

  View view;

  int choice;
  string term = "Not selected";
  Schedule* currentSched = nullptr;

  while (true){
    cout << endl << endl;
    cout << "Current term: " << term; 
    view.showMenu(choice);

    switch(choice){
      case 0: // exit  
        return;
      case 1: // Change current term
        while (true) {
          cout << "Enter term ('F23' or 'W24'): ";
          view.readStr(term);
          if (term == "F23" || term == "W24") {
            if (!findSched(term, &currentSched)){
              currentSched = new Schedule(term);
              addSched(currentSched);
              view.printStr("New term selected and schedule created.\n");
            } 
            else {
              view.printStr("Term already exists, schedule selected.\n");
            }
            break;
          } else {
            cout << "Invalid term entered. Please enter 'F23' or 'W24'\n";
          }
        }
        break;

      case 2: // View courses
        if (currentSched == nullptr){
          view.printStr("ERROR:  no term selected.\n");
          break;
        }
        view.printStr("\n");
        view.printStr("Carleton U. School of Computer Science COURSES FOR TERM " + term + "\n");
        school->printCourses(term);
        break;
      
      case 3: // View schedule
        if (currentSched == nullptr){
          view.printStr("ERROR:  no term selected.\n");
          break;
        }
        currentSched->print();
        break;

      case 4: // Add course to schedule
        if (!findSched(term, &currentSched)){
          view.printStr("Error, schedule for this term does not exist.\n");
          break;
        }

        int courseId;
        cout << "Enter the course ID: ";
        view.readInt(courseId);
        Course* course;
        if (!school->findCourse(courseId, &course) || course->getTerm() != term){
          view.printStr("Error, course not found or not offered in the selected term.\n");
          break;
        }

        if (!currentSched->addCourse(course)){
          view.printStr("Error, could not add the course to the schedule.\n");
        } else {
          view.printStr("Course added to the schedule.\n");
        }
        break;


      case 5: // Clear schedule
        if (currentSched == nullptr){
          view.printStr("ERROR:  no term selected.\n");
          break;
        }
        currentSched->clear();
        view.printStr("Schedule cleared.\n");
        break;

      default:
        view.printStr("Invalid choice.\n");
    }
  }
}