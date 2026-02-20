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
  std::string addressString;
  std::string birth;
  std::string grad;
  std::string creditString;

  converter.str(studentString);
  getline(converter, firstName, ',');
  getline(converter, lastName, ',');
  getline(converter, addressString, ','); //street
  getline(converter, addressString, ','); //city
  getline(converter, addressString, ','); //state
  getline(converter, addressString, ','); //zip
  getline(converter, birth, ',');
  getline(converter, grad, ',');
  getline(converter, creditString);
  
  converter.clear();
  converter.str("");

  converter << creditString;
  converter >> creditHours;

  Date birthDate;
  birthDate.init(birth);

  Date gradDate;
  gradDate.init(grad);

  Address address;
  address.init(addressString);
} // end init

void Student::printStudent(){
  /*first name, last name
   *address
   *address (printAddress() ?
   *DOB: birthDate
   *Grad: gradDate
   *Credits: creditHours

 
