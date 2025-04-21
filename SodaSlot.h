#ifndef SODA_SLOT_H
#define SODA_SLOT_H

#include <string>

class SodaSlot {
private:
   std::string name;
   float price;
   int stock;

public:
   SodaSlot(); // Default constructor
   SodaSlot(const std::string& n, float p, int s);

   std::string getName() const;
   float getPrice() const;
   int getStock() const;

   void setName(const std::string& n);
   void setPrice(float p);
   void setStock(int s);
};

#endif 