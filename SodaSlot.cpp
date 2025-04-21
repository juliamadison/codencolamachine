#include "SodaSlot.h"

SodaSlot::SodaSlot() {
   name = "";
   price = 0.0f;
   stock = 0;
}

SodaSlot::SodaSlot(const std::string& n, float p, int s) {
   name = n;
   price = p;
   stock = s;
}

std::string SodaSlot::getName() const {
   return name;
}

float SodaSlot::getPrice() const {
   return price;
}

int SodaSlot::getStock() const {
   return stock;
}

void SodaSlot::setName(const std::string& n) {
   name = n;
}

void SodaSlot::setPrice(float p) {
   price = p;
}

void SodaSlot::setStock(int s) {
   stock = s;
}
