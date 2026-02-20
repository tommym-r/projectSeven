#include <string>
#include "address.h"
#include "date.h"
#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

class Student{
  private:
    std::string firstName;
    std::string lastName;
    Date birthDate;
    Date gradDate;
    Address address;
    int creditHours;
  public:
    Student();
    void init(std::string studentString);
    void printStudent();
    std::string getLastFirst();
};

#endif
