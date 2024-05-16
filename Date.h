//
// Created by Михаил Немыкин on 28.04.2024.
//

#ifndef HOME_TASK2804_DATE_H_
#define HOME_TASK2804_DATE_H_
#include <map>
#include <exception>

class Date {
 public:
  Date(int year, int month, int day);
  Date() = default;
  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;
  int DiffDays(const Date &date) const;
  Date add(int days);
  Date subtract(int days);
  Date replace(int day, int month, int year);
  int week() const;
  int totalWeeks() const;
  char *isoformat() const;

 private:
  int year = 1970;
  int month = 1;
  int day = 1;

  static int GetMaxDaysInMonth(int month, int year_);
  void IncrementDay();
  void DecrementDay();
  static int DaysInYear(int year_);
  int TotalDaysInYear() const;
  int TotalDays() const;
};

#endif //HOME_TASK2804_DATE_H_
