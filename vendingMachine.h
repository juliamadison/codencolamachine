#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <string>

class VendingMachine
{
private:
    int machineID;
    std::string location;
    float totalSales;
    std::string status;

public:
    void refillSlot(int slotID);
    void collectBin();
    std::string checkDiagnostics();
    void resetMachine();
};

#endif
