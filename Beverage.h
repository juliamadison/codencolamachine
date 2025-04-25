#pragma once
#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class VendingMachine { //New  Code
private:
   int machineID;
   std::string location;
   float totalSales;
   std::string status;

public:
    VendingMachine(int id, const std::string&loc);

    void refillSlot(int slotID);
    void collectBin();
    std::string checkDiagnostics();
    void resetMachine();
    
};

class Beverage {
public:
    std::string name;
    float price;
    int stock;

    Beverage(std::string name, float price, int stock) : name(name), price(price), stock(stock) {}
}; //Old Code

#endif 
