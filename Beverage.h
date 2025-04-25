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

// Shows a drink item in inventory
class Beverage {
public:
    std::string name; //Title Of The Drink
    float cost; //Cost per unit
    int stock; //Stock Quantity available

    //Constructor to set up all properites
    Beverage(std::string name, float price, int stock) : name(name), price(price), stock(stock) {}
}; //Old Code

#endif 
