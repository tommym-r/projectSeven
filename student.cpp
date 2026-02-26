#include <iostream>
#include <sstream>
#include "student.h"

Student::Student(){
  firstName = "";
  lastName = "";
  creditHours = 0;

} // end constuctor

void Student::init(std::string studentString){
  //studentString is "firstName,lastName,street,city,state,zip,birthDate,gradDate,creditHours" or "fn,ln,address,bd,gd,credit"
  std::stringstream converter;
  std::string street, city, state, zip;
  std::string birth;
  std::string grad;
  std::string creditString;

  converter.str(studentString);
  getline(converter, firstName, ',');
  getline(converter, lastName, ',');
  getline(converter, street, ','); //street
  getline(converter, city, ','); //city
  getline(converter, state, ','); //state
  getline(converter, zip, ','); //zip
  getline(converter, birth, ',');
  getline(converter, grad, ',');
  getline(converter, creditString);
  
  converter.clear();
  converter.str("");

  converter << creditString;
  converter >> creditHours;

  birthDate = new Date();
  birthDate->init(birth);

  gradDate = new Date();
  gradDate->init(grad);

  address = new Address();
  address->init(street, city, state, zip);
} // end init

void Student::printStudent(){
  /*first name, last name
   *address
   *address (printAddress() ?
   *DOB: birthDate
   *Grad: gradDate
   *Credits: creditHours
   */
  std::cout << firstName << " " << lastName << std::endl;
  address->printAddress();
  std::cout << "DOB: ";
  birthDate->printDate();
  std::cout << "Grad: ";
  gradDate->printDate();
  std::cout << "Credits: " << creditHours << std::endl;
} // end printStudent

std::string Student::getLastFirst(){
  return lastName + ", " + firstName;
} // end getLastFirst

std::string Student::getLast(){
  return lastName;
} // end getLast

Student::~Student(){
  delete birthDate;
  delete gradDate;
  delete address;
} // end destructor

