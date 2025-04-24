#pragma once
#ifndef SODA_H
#define SODA_H

#include <string>

class Beverage {
public:
    std::string name;
    float price;
    int slotID;
    int stock;
    int maxCapacity;


    Beverage(std::string name, float price, int slotID, int stock, int maxCapacity) : name(name), price(price), slotID(slotID), stock(stock), maxCapacity(maxCapacity) {}
};

void updateStock(int amount) {
    stock += quantity
    if (stock > maxCapacity) stock = maxCapacity;
}

bool isSlotEmpty() const {
     return stock == 0;
}

bool isSlotFull() const {
    return stock >= maxCapacity;
}
};
    

#endif 
