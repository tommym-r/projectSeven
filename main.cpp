#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//void testAddress();
//void testDate();
//void testStudent();

void loadStudents(std::vector<Student*>&);
void printStudents(std::vector<Student*>&);
void showStudentNames(std::vector<Student*>&);
void findStudent(std::vector<Student*>&);
std::string menu();

int main(){
  //std::cout << "Hello!" << std::endl;
  //testAddress();
  //testDate();
  //testStudent();
  std::vector<Student*> students;
  loadStudents(students);
  std::string input;
  bool going = true;
  while (going){
    input = menu();
    if (input == "0"){
      going = false;
    } else if (input == "1"){
      showStudentNames(students);
    } else if (input == "2"){
      printStudents(students);
    } else if (input == "3"){
      findStudent(students);
    } else {
      std::cout << "invalid input, try again" << std::endl;
    } // end if else
  } // end while going

  students.clear();
  return 0;
} // end main

void loadStudents(std::vector<Student*>& students){
  std::ifstream inFile;
  std::string currentLine;

  inFile.open("students.csv");
  while (getline(inFile, currentLine)){
    Student* stu = new Student();
    stu->init(currentLine);
    students.push_back(stu);
  } // end while
  inFile.close();
} // end loadStudents

void printStudents(std::vector<Student*>& students){
  for (Student* s : students){
    s->printStudent();
  } // end for
  std::cout << std::endl;
} // end printStudents

void showStudentNames(std::vector<Student*>& students){
  std::string name;
  for (Student* s: students){
    name = s->getLastFirst();
    std::cout << name << std::endl;
  } // end for
} // end showStudentNames

void findStudent(std::vector<Student*>& students){
  std::string search;
  std::string lName;
  std::vector<Student*> matches;
  std::cout << "Last name of student: " << std::endl;
  std::cin >> search;
  for (Student* s: students){
    lName = s->getLast();
    if (lName.find(search) != std::string::npos){
      matches.push_back(s);
    } // end if
  } // end for
  if (matches.size() == 0){
    std::cout << "No matches found" << std::endl;
  } else {
    printStudents(matches);
  } // end if else
} // end findStudents

std::string menu(){
  std::string input;
  std::cout << "0) quit" << std::endl << "1) print all student names" << std::endl << "2) print all student data" << std::endl << "3) find a student" << std::endl;
  std::cin >> input;
  return input;
}

/*
std::string menu(){
  std::string input;
  bool going = true;
  while (going){
    std::cout << "0) quit" << std::endl << "1) print all student names" << std::endl << "2) print all student data" << std::endl << "3) find a student" << std::endl;
    std::cin >> input;
    if (input == "0"){
      going = false;
      run = false;
    } else if (input == "1"){
      return showStudentNames(students);
    } else if (input == "2"){
      printStudents(students);
    } else if (input == "3"){
      findStudent(students);
    } else {
      std::cout << "invalid input, try again" << std::endl;
    } // end if else
  } // end while
} // end menu
*/

/*
void testAddress(){
  Address a;
  a.init("123 W Main St", "Muncie", "IN", "47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate

void testStudent(){
  std::string studentString = "Danielle,Johnson,32181 Johnson Course Apt. 389,New Jamesside,IN,59379,02/17/2004,05/15/2027,65";
  Student* student = new Student();
  student->init(studentString);
  student->printStudent();
  std::cout << std::endl;
  std::cout << student->getLastFirst();
  delete student;
} // end testStudent
*/

