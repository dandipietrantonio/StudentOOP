#include <iostream>
#include "date.h"

using namespace std;

//Constructor for Date Class
Date::Date(int d, int m, int y) :
    day(d), month(m), year(y) {
    }

//Output for Date Class
ostream& operator<<(ostream& os, const Date& date){
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}
