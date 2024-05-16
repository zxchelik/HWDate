//
// Created by Михаил Немыкин on 28.04.2024.
//

#include "Date.h"
Date::Date(int year, int month, int day) {
  try {
    if (day < 1 || day > GetMaxDaysInMonth(month, year)) {
      throw std::invalid_argument("invalid day");
    }
    this->year = year;
    this->month = month;
    this->day = day;
  } catch (...) {
    this->year = 1970;
    this->month = 1;
    this->day = 1;
  }

}
int Date::GetMaxDaysInMonth(int month_, int year_) {
  if (month_ < 1 || month_ > 12) {
    throw std::invalid_argument("invalid month");
  }
  if (month_ == 2) {
    return (year_ % 400 == 0 || year_ % 4 == 0 && year_ % 100 != 0 ? 29 : 28);
  }
  static std::map<int, const int> days = {
      {1, 31},
      {3, 31},
      {4, 30},
      {5, 31},
      {6, 30},
      {7, 31},
      {8, 31},
      {9, 30},
      {10, 31},
      {11, 30},
      {12, 31}
  };
  return days[month_];
}
int Date::GetDay() const {
  return day;
}
int Date::GetMonth() const {
  return month;
}
int Date::GetYear() const {
  return year;
}

void Date::IncrementDay() {
  ++day;
  if (day > GetMaxDaysInMonth(month, year)) {
    day = 1;
    ++month;
    if (month > 12) {
      month = 1;
      ++year;
    }
  }
}

void Date::DecrementDay() {
  --day;
  if (day == 0) {
    day = GetMaxDaysInMonth(month--, year);
    if (month == 0) {
      month = 12;
      --year;
    }
  }
}

Date Date::add(int days) {
  Date copy(*this);
  for (int i = 0; i < days; ++i) {
    copy.IncrementDay();
  }
  return copy;
}

Date Date::subtract(int days) {
  Date copy(*this);
  for (int i = 0; i < days; ++i) {
    copy.DecrementDay();
  }
  return copy;
}

Date Date::replace(int day_ = 0, int month_ = 0, int year_ = 0) {
  day_ = day_ == 0 ? day : day_;
  month_ = month_ == 0 ? month : month_;
  year_ = year_ == 0 ? year : year_;
  return Date(year_, month_, day_);
}

bool operator>(const Date &left, const Date &right) {
  if (left.GetYear() > right.GetYear())
    return true;
  if (left.GetYear() < right.GetYear())
    return false;
  if (left.GetMonth() > right.GetMonth())
    return true;
  if (left.GetMonth() < right.GetMonth())
    return false;
  return left.GetDay() > right.GetDay();
}

bool operator==(const Date &left, const Date &right) {
  return left.GetYear() == right.GetYear() && left.GetMonth() == right.GetMonth() && left.GetDay() == right.GetDay();
}

bool operator!=(const Date &left, const Date &right) {
  return !(left == right);
}

bool operator<(const Date &left, const Date &right) {
  return !(left > right) && !(left == right);
}

int Date::DiffDays(const Date &date) const {
  Date first = *this;
  Date second = date;

  int diff = 0;
  if (first > second) {
    std::swap(first, second);
  }

  while (first != second) {
    ++diff;
    first.IncrementDay();
  }

  return diff;
}

int Date::DaysInYear(int year_) {
  return (year_ % 4 == 0 && (year_ % 100 != 0 || year_ % 400 == 0)) ? 366 : 365;
}

int Date::TotalDays() const {
  int days = day - 1;

  for (int i = 1970; i < year; ++i) {
    days += DaysInYear(i);
  }

  for (int i = 1; i < month; ++i) {
    days += Date::GetMaxDaysInMonth(i, year);
  }

  return days;
}

int Date::TotalDaysInYear() const {
  int days = day - 1;

  for (int i = 1; i < month; ++i) {
    days += Date::GetMaxDaysInMonth(i, year);
  }

  return days;
}
int Date::totalWeeks() const {
  return TotalDays() / 7;
}

int Date::week() const {
  return TotalDaysInYear() / 7;
}

char *Date::isoformat() const {
  char *result = new char[11];
  snprintf(result, 11, "%04d-%02d-%02d", year, month, day);
  return result;
}

