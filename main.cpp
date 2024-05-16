#include <iostream>
#include <cassert>
#include "Date.h" // Предполагается, что класс Date находится в файле Date.h

void testConstructor() {
  // Проверка конструктора
  Date date1(2024, 2, 29);
  assert(date1.GetYear() == 2024);
  assert(date1.GetMonth() == 2);
  assert(date1.GetDay() == 29);

  // Проверка на некорректную дату
  Date date2(2022, 13, 32);
  assert(date2.GetYear() == 1970);
  assert(date2.GetMonth() == 1);
  assert(date2.GetDay() == 1);
}

void testDiffDays() {
  // Проверка функции DiffDays()
  Date date1(2024, 1, 1);
  Date date2(2025, 1, 1);
  assert(date1.DiffDays(date2) == 366);
}

void testAddSubtract() {
  // Проверка функций add() и subtract()
  Date date(2024, 1, 1);
  Date addedDate = date.add(10);
  Date subtractedDate = date.subtract(5);
  assert(addedDate.GetYear() == 2024 && addedDate.GetMonth() == 1 && addedDate.GetDay() == 11);
  assert(subtractedDate.GetYear() == 2023 && subtractedDate.GetMonth() == 12 && subtractedDate.GetDay() == 27);
}

void testReplace() {
  // Проверка функции replace()
  Date date(2024, 1, 1);
  Date replacedDate = date.replace(10, 5, 2025);
  assert(replacedDate.GetYear() == 2025 && replacedDate.GetMonth() == 5 && replacedDate.GetDay() == 10);
}

void testWeek() {
  // Проверка функции week()
  Date date(2024, 5, 15);
  assert(date.week() == 19); // Предполагается, что это 19-я неделя в 2024 году
}

void testTotalWeeks() {
  // Проверка функции totalWeeks()
  Date date(2024, 5, 15);
  assert(date.totalWeeks() == 2836); // Предполагается, что это 2836 неделя с 1 января 1970 года
}

void testIsoformat() {
  // Проверка функции isoformat()
  Date date(2024, 5, 15);
  assert(strcmp(date.isoformat(), "2024-05-15") == 0);
}

int main() {
  testConstructor();
  testDiffDays();
  testAddSubtract();
  testReplace();
  testWeek();
  testTotalWeeks();
  testIsoformat();

  std::cout << "All tests passed successfully!" << std::endl;
  return 0;
}
