#ifndef SODA_SLOT_H
#define SODA_SLOT_H

#include <string>
#include "SodaCan.h"

// Class that represents a shelf slot in the vending machine.
// Each slot holds multiple sodas of the same type.
class SodaSlot {
private:
   std::string name; // Name of the soda inside the slot
   float price;      // Price of the soda
   int stock;        // How many sodas are in the slot

public:
   // Default constructor (empty slot)
   SodaSlot();

   // Constructor that sets name, price, and starting stock
   SodaSlot(const std::string& n, float p, int s);

   // Getters
   std::string getName() const; // Get soda name
   float getPrice() const;      // Get soda price
   int getStock() const;        // Get number of sodas left

   // Setters
   void setName(const std::string& n);
   void setPrice(float p);
   void setStock(int s);

   // Dispenses one SodaCan if stock is available
   // Reduces stock by 1 and returns a SodaCan
   SodaCan dispenseBeverage();
};

#endif