#include "SodaSlot.h"

// Default constructor sets blank soda
SodaSlot::SodaSlot() {
   name = "";
   price = 0.0f;
   stock = 0;
}

// Constructor that sets soda details
SodaSlot::SodaSlot(const std::string& n, float p, int s) {
   name = n;
   price = p;
   stock = s;
}

// Get the name of the soda
std::string SodaSlot::getName() const {
   return name;
}

// Get the price of the soda
float SodaSlot::getPrice() const {
   return price;
}

// Get the number of sodas left
int SodaSlot::getStock() const {
   return stock;
}

// Change the soda name
void SodaSlot::setName(const std::string& n) {
   name = n;
}

// Change the soda price
void SodaSlot::setPrice(float p) {
   price = p;
}

// Change the soda stock
void SodaSlot::setStock(int s) {
   stock = s;
}

// Dispenses one soda if available
// If stock is greater than 0, it creates and returns a SodaCan
// Reduces the stock count by 1
SodaCan SodaSlot::dispenseBeverage() {
   if (stock > 0) {
      stock--;
      return SodaCan(name, price);
   }
   return SodaCan(); // Return empty SodaCan if no stock
}