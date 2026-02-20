#include <iostream>
#include <sstream>
#include "date.h"

Date::Date(){
  month = 1;
  day = 1;
  year = 2000;
} // end constructor

void Date::init(std::string dateString){
  //date string is mm/dd/yyyy

  //make a string stream
  std::stringstream converter;
  std::string sMonth;
  std::string sDay;
  std::string sYear;

  //separate to temp strings
  converter.str(dateString);
  getline(converter, sMonth, '/');
  getline(converter, sDay, '/');
  getline(converter, sYear);
  
  //convert to ints
  converter.clear();
  converter.str("");

  converter << sMonth << " " << sDay << " " << sYear;
  converter >> month >> day >> year;

  //make string array for months
} //end init

void Date::printDate(){
  //make string array for months
  std::string sMonth2;
  std::string monthNames[] = {"null", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  for (int i = 0; i < 13; i++){
    if (month == i){
      sMonth2 = monthNames[i];
    } // end if
  } // end for

  std::cout << sMonth2 << " " << day << " " << year << std::endl;
} //end printDate
