#ifndef SODA_CAN_H
#define SODA_CAN_H

#include <string>

// Class that represents a single soda drink.
// It holds the soda's name and price.
class SodaCan {
public:
   std::string name;   // Name of the soda (e.g., "Coke")
   float price;        // Price of the soda

   // Default constructor (empty soda)
   SodaCan();

   // Constructor that sets name and price
   SodaCan(const std::string& n, float p);
};

#endif