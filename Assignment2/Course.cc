#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "Course.h"
#include "Time.h"

Course::Course(string term, string subject, int code, char section, string instructor, LectDaysType days, int hours, int minutes)
{
    this->term = term;
    this->subject = subject;
    this->code = code;
    this->section = section;
    this->instructor = instructor;
    this->days = days;
    this->time = new Time(hours, minutes);

}

Course::~Course()
{
    delete time;
}

bool Course::computeSlot(TimeSlotType& slot)
{
    return time->computeSlot(slot);
}

bool Course::computeDays(WeekDayType& day1, WeekDayType& day2){
    if (days == MON_WED) {
        day1 = MON;
        day2 = WED;
    } else if (days == TUE_THU) {
        day1 = TUE;
        day2 = THU;
    } else if (days == WED_FRI) {
        day1 = WED;
        day2 = FRI;
    } else {
        day1 = BAD_WEEK_DAY;
        day2 = BAD_WEEK_DAY;
        return false;
    }
    return true;
}


bool Course::lessThan(Course* other){
    if (this->subject < other->subject){
        return true;
    } 
    else if (this->subject == other->subject){
        if (this->code < other->code){
            return true;
        } 
        else if (this->code == other->code){
            if (this->term < other->term){
                return true;
            }
            else if (this->term == other->term){
                if (this->section < other->section){
                    return true;
                }
            }
        }
    }
    return false;
}

void Course::print(){
    string daysStr = lectDaysToString(this->days);
    cout << id << " Term: " << term << " " << getCourseCode() << " "
         << daysStr << " ";

    time->print();
    cout << " Instr: " << instructor << endl;
}

string Course::getCourseCode()
{
    return subject + " " + to_string(code) + " "+ section;
}

int Course::getID()
{
    return id;
}

string Course::getTerm()
{
    return term;
}

string Course::getInstructor()
{
    return instructor;
}

void Course::setID(int newId)
{
    id = newId;
}

string Course::lectDaysToString(LectDaysType days)
{
    if (days == MON_WED) {
        return "MW";
    } else if (days == TUE_THU) {
        return "TR";
    } else if (days == WED_FRI) {
        return "WF";
    } else {
        return "Invalid";
    }
}