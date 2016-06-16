#pragma once

namespace HackerRank {

typedef unsigned long long YearType;

// Returns true if Y is a leap year, not include Y itself
// Constant time/memory complexity.
int isLeapYear(YearType Y) {
  if (Y % 4 == 0) {
    if (Y % 100 == 0) return Y % 400 == 0;
    return 1;
  }
  return 0;
}

enum Week { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

enum Monthes { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

// Returns the number of leap years from 1900 to 'year'
// Constant time/memory complexity.
YearType leapYears(YearType year) {
  if (year == 1900) return 0;
  
  YearType delta = (year - 1900 - 1);
  YearType leaps = delta / 4 - delta / 100;
  leaps += (year - 1600 - 1) / 400;

  return leaps;
}

// Returns the week day for 1 Jan year, Sunday is 0, Monday is 1 etc
// year should be >= 1900
// Constant time/memory complexity.
int getWeekDay(YearType year) {
  int days = (((year - 1900) % 7) * 365 % 7) % 7;
  int day = (days + (leapYears(year) + 1) % 7) % 7;
  return day;
}

// Returns the week day for 1 month year, Sunday is 0, Monday is 1 etc
// year should be >= 1900
// Constant time/memory complexity.
int getWeekDay(YearType year, int month) {
  static int days[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
  static int leapdays[] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
  int leap = isLeapYear(year);
  int day = (getWeekDay(year) + (leap ? leapdays[month-1] : days[month-1]) % 7);
  return day %= 7;
}

} // namespace HackerRank
