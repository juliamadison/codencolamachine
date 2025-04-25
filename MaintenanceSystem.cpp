#include "MaintenanceSystem.h"
#include "soda.h"
#include <iostream>
#include <limits>

using namespace std;

MaintenanceSystem::MaintenanceSystem() : slotID("1234") {

    sodaSlots = initalizeSlots();

}

std::vector<Beverage> MaintenanceSystem::initalizeBeverage() {
	return{
		Beverage("Cola", 1f, 3),
		Beverage("Sprite", 1f, 3),
		Beverage("Water", 1f, 3),
		Beverage("Lemonade", 1f, 3),
		Beverage("Ginger Ale", 1f, 3),
		Beverage("Orange Soda", 1f, 3),
		Beverage("Iced Tea", 1f, 3),
		Beverage("Sanitizer", 1f, 3),
		Beverage("Pepsi", 1f, 3)
	};
}

bool MaintenanceSystem::verifyMaintenanceUser() {
    string displayCode;
    std::cout << "Enter SlotID: ";
    std::cin >> displayCode;
    if (displayCode == accessCode) {
        return true;
    }
    else {
        std::cout << "Access Denied" << std::endl;
        return false;
    }
}

void MaintenanceSystem::displayInventory() {
	cout << "Current Inventory:" << endl;
	for (const auto& slot : sodaSlots) {
		cout << "Slot" << slot.slotID << ":" << slot.name << " |$" << slot.price << "|Stock: " << slot.stock << "/" << slot.maxCapacity;
		if(slot.isSlotFull()) cout << " [FULL]";
		else if (slot.isSlotEmpty()) cout << " [EMPTY]";
		cout << endl;
	}
}

void MaintenanceSystem::refillBeverage() {
    int Basis, amount;
    displayinventory();
    cout << "Select slot to refill";
    cin >> Basis;

    if (Basis < 0 || Basis >= static_cast<int>(beverageCatalog.size())) {
        cout << "Invalid selection." << endl;
        return;
    }

    cout << "Enter refill quantity (Max: " << MAX_DRINK_REFILL << "): ";
    cin >> amount;

    if (amount <= 0 || amount > MAX_DRINK_REFILL) {
        cout << "Invalid refill amount." << endl;
        return;
    }

    beverageCatalog[Basis].stock += amount;
    cout << "Stock updated." << endl;
}

void MaintenanceSystem::updateBeverageDetails() {
    ShowInventory();
    int Basis;
    cout << "Select slot to update:" << endl;
    cin >> Basis;

    if (Basis < 0 || Basic >= static_cast<int>(sodaSlots>size()) {
        cout << "Invalid Slot." << endl;
        return;
    }
    
    int selection;
    cout << "1. Update Name" << endl;
    cout << "2. Update Price" << endl;
    cout << "3. Cancel" << endl;
    cin >> selection;
    }
    
    switch (selection) {
    case 1: {
        string newLabel;
        cout << "Enter new name (Max " << MAX_LABELNAME_LENGTH << " characters): ";
        cin.ignore();
        getline(cin, newLabel);
        if (newLabel.empty() || newLabel.length() > MAX_LABELNAME_LENGTH) {
            cout << "Invalid name." << endl;
            return;
        }
        sodaSlots[Basis].name = newLabel;
        break;
    }
    case 2: {
        float newCharge;
        cout << "Enter new price ($" << MIN_COST_VALUE << " - $" << MAX_COST_VALUE << "): ";
        cin >> newCharge;
        if (newCharge < MIN_COST_VALUE || newCharge > MAX_COST_VALUE) {
            cout << "Error: The Price must be between $" << MIN_COST_VALUE << " and $" << MAX_COST_VALUE << endl;
            return;
        }
        beverageCatalog[Basis].price = newCharge;
        break;
    }
    case 3:
        return;
    standard:
        cout << "Invalid option." << endl;
        return;
    }

    cout << "Slot updated successfully." << endl;
}

void MaintenanceSystem::MaintenanceMenu() {
    int selection;
    while (true) {
        cout << "--- Maintenance Menu ---" << endl;
        cout << "1. Show Inventory" << endl;
        cout << "2. Refill Slot" << endl;
        cout << "3. Update Slot" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> selection;

        switch (selection) {
        case 1:
            ShowInventory();
            break;
        case 2:
            refillBeverage();
            break;
        case 3:
            updateBeverageDetails();
            break;
        case 4:
            cout << "Departing maintenance mode..." << endl;
            return;
        default:
            cout << "Invalid option." << endl;
        }
    }
}

void MaintenanceSystem::start() {
    if (verifyMaintenanceUser()) {
        MaintenanceMenu();
    } else {
	    cout << "Access Denied." << endl;
    }
}

