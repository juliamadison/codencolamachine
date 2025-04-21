#include "MaintenanceSystem.h"
#include "Beverage.h"
#include <iostream>
#include <limits>

using namespace std;

MaintenanceSystem::MaintenanceSystem() : accessCode("1234") {

    beverageCatalog = prepareBeverage();

}

std::vector<Beverage> MaintenanceSystem::prepareBeverage() {
	return{
		Beverage("Cola", 1.50f, 12),
		Beverage("Sprite", 1.25f, 9),
		Beverage("Water", 1.00f, 14)
	};
}

bool MaintenanceSystem::verifyMaintenanceUser() {
    string displayCode;
    std::cout << "Enter maintenance access code: ";
    std::cin >> displayCode;
    if (displayCode == accessCode) {
        return true;
    }
    else {
        std::cout << "Access Denied" << std::endl;
        return false;
    }
}

void MaintenanceSystem::ShowInventory() {
	cout << "Present Inventory:" << endl;
	for (size_t i = 0; i < beverageCatalog.size(); ++i) {
		cout << i << ". " << beverageCatalog[i].name << " | Price: $" << beverageCatalog[i].price << " | Stock: " << beverageCatalog[i].stock << endl;
	}
}

void MaintenanceSystem::refillBeverage() {
    int Basis, amount;
    cout << "Select beverage to refill";
    cin >> Basis;

    if (Basis < 0 || Basis >= static_cast<int>(beverageCatalog.size())) {
        cout << "Invalid selection." << endl;
        return;
    }

    cout << "Enter quantity to add (Max: " << MAX_DRINK_REFILL << "): ";
    cin >> amount;

    if (amount <= 0 || amount > MAX_DRINK_REFILL) {
        cout << "Error: Amount must be between 1 and " << MAX_DRINK_REFILL << endl;
        return;
    }

    beverageCatalog[Basis].stock += amount;
    cout << "Stock updated." << endl;
}

void MaintenanceSystem::updateBeverageDetails() {
    ShowInventory();
    int Basis;
    cout << "Select beverage to update:" << endl;
    cin >> Basis;

    if (cin.fail() || Basis < 1 || static_cast<size_t>(Basis) > beverageCatalog.size()) {
        cout << "Invalid selection." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    int selection;
    cout << "1. Update Name" << endl;
    cout << "2. Update Price" << endl;
    cout << "3. Cancel" << endl;
    cin >> selection;

    if (cin.fail()) {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    switch (selection) {
    case 1: {
        string newLabel;
        cout << "Enter new name (Max " << MAX_LABELNAME_LENGTH << " characters): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newLabel);
        if (newLabel.empty() || newLabel.length() > MAX_LABELNAME_LENGTH) {
            cout << "Error: Name must be 1–" << MAX_LABELNAME_LENGTH << " characters" << endl;
            return;
        }
        beverageCatalog[Basis].name = newLabel;
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

    cout << "Information updated." << endl;
}

void MaintenanceSystem::showMaintenanceMenu() {
    int selection;
    while (true) {
        cout << "--- Maintenance Menu ---" << endl;
        cout << "1. Show Inventory" << endl;
        cout << "2. Fill Beverage" << endl;
        cout << "3. Update Beverage" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> selection;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

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
            cout << "Depart maintenance mode..." << endl;
            return;
        default:
            cout << "Invalid option." << endl;
        }
    }
}

void MaintenanceSystem::start() {
    if (verifyMaintenanceUser()) {
        showMaintenanceMenu();
    }
}

