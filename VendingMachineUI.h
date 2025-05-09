#ifndef VENDING_MACHINE_UI_H
#define VENDING_MACHINE_UI_H

using namespace std;

#include <string>
#include <vector>

struct Beverage {
    std::string name;
    int price;
    int quantity;
};

class VendingMachineUI {

public:
    VendingMachineUI();

    void displayMenu();
    void showAvailableBeverages();
    void selectBeverage();
    bool isValidSlot(int slotIndex);
    void run();

private:
    std::vector<Beverage> slots;
};

#endif

