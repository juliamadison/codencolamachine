#include "SodaCan.h"

// Default constructor initializes empty soda
SodaCan::SodaCan() {
   name = "";
   price = 0.0f;
}

// Constructor with parameters to set name and price
SodaCan::SodaCan(const std::string& n, float p) {
   name = n;
   price = p;
}