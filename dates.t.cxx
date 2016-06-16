#include <iostream>

#include "dates.h"

using namespace std;
using namespace HackerRank;

bool testDates(string& reason) {
  if (isLeapYear(1900)) {
    reason = "1900 isn't a leap year";
    return false;
  }

  if (not isLeapYear(1916)) {
    reason = "1916 is a leap year";
    return false;
  }

  if (not isLeapYear(2000)) {
    reason = "2000 is a leap year";
    return false;
  }

  YearType years = leapYears(2001);
  if (years != 25) {
    reason = "The expected number of leap years from 1900 to 2001 is 25. Result "
      + to_string(years);
    return false;
  }

  if (getWeekDay(1978) != SUNDAY) {
    reason = "1 Jan 1989 is SUNDAY";
    return false;
  }

  if (getWeekDay(20100) != FRIDAY) {
    reason = "1 Jan 20100 will be FRIDAY";
    return false;
  }

  if (getWeekDay(2016, JUL) != FRIDAY) {
    reason = "1 JUL 2016 is FRIDAY";
    return false;
  }

  if (getWeekDay(1961, APR) != SATURDAY) {
    reason = "1 APR 1961 was SATURDAY";
    return false;
  }

  return true;
}

int main() {
  string reason;
  if (not testDates(reason)) {
    cerr << "Test dates failed: " << reason << endl;
    return 1;
  }
  return 0;
}
