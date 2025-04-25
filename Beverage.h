#pragma once
#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class VendingMachine {
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

#endif 
