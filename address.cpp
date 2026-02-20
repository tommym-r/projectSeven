#include <iostream>
#include "address.h"

Address::Address(){
  street = ""; 
  city = "";
  state = "";
  zip = "";
} // end constructor

void Address::init(std::string streetstr, std::string citystr, std::string statestr, std::string zipstr){
  street = streetstr;
  city = citystr;
  state = statestr;
  zip = zipstr;
} // end init

void Address::printAddress(){
  std::cout << street << std::endl << city << " " << state << ", " << zip << std::endl;
} // end printAddress
