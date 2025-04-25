#include "MaintenanceSystem.h"
#include "Beverage.h"
#include <iostream>
#include <limits>

using namespace std;

// The constructor sets up the access code and loads the drink catalog.
MaintenanceSystem::MaintenanceSystem() : accessCode("1234") {

    beverageCatalog = prepareBeverage(); // Load The List Of Drinks

}

std::vector<Beverage> MaintenanceSystem::prepareBeverage() {
	return{
		
	};
}

bool MaintenanceSystem::verifyMaintenanceUser() {
    string displayCode;
    cout << "Enter maintenance access code: ";
    cin >> displayCode;
    if (displayCode == accessCode) { // Allow Access
        return true;
    }
    else {
        std::cout << "Access Denied" << std::endl; //Acess Denied
        return false;
    }
}


void MaintenanceSystem::ShowInventory() {
	cout << "Present Inventory:" << endl;
	for (size_t i = 0; i < beverageCatalog.size(); ++i) {
		cout << i << ". " << beverageCatalog[i].name << " | Price: $" << beverageCatalog[i].price << " | Stock: " << beverageCatalog[i].stock << endl;
	}
}

// Ask the user to pick a drink and restock it
void MaintenanceSystem::refillBeverage() {
    int Basis, amount;
    cout << "Select beverage to refill: ";
    cin >> Basis;

    if (Basis < 0 || Basis >= static_cast<int>(beverageCatalog.size())) {
        cout << "Invalid selection." << endl;  // Check if the selection index is valid
        return;
    }

    cout << "Enter quantity to add (Max: " << MAX_DRINK_REFILL << "): "; // Check if the refill amount is valid
    cin >> amount;

    if (amount <= 0 || amount > MAX_DRINK_REFILL) {
        cout << "Error: Amount must be between 1 and " << MAX_DRINK_REFILL << endl;
        return;
    }

    beverageCatalog[Basis].stock += amount;
    cout << "Stock updated." << endl; // Adjust the stock quantity
}

void MaintenanceSystem::updateBeverageDetails() {
    ShowInventory();
    int Basis;
    cout << "Select beverage to update:" << endl; // Update drink details like name or price
    cin >> Basis;
    cin >> Basis;

    if (cin.fail() || Basis < 1 || static_cast<size_t>(Basis) > beverageCatalog.size()) {
        cout << "Invalid selection." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Check the index input
        return;
    }
    
    int selection;
    cout << "1. Update Name" << endl;
    cout << "2. Update Price" << endl;
    cout << "3. Cancel" << endl;
    cin >> selection; // Ask the user what they want to change

    if (cin.fail()) {
        cout << "Invalid input." << endl; // Manage cases of invalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    switch (selection) {
    case 1: {
        string newLabel;
        cout << "Enter new name (Max " << MAX_LABELNAME_LENGTH << " characters): "; // Change the drink name
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
        cout << "Enter new price ($" << MIN_COST_VALUE << " - $" << MAX_COST_VALUE << "): "; // Change the drink price
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
        cout << "Invalid option." << endl; //option to cancel
        return;
    }

    cout << "Information updated." << endl;
}

// Menu of maintenance tasks
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

	 // Handle cases of non-integer input
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

	// Direct to the chosen function
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
            return; // Exit Menu
        default:
            cout << "Invalid option." << endl;
        }
    }
}

// Start the maintenance process
void MaintenanceSystem::start() {
    if (verifyMaintenanceUser()) {
        showMaintenanceMenu(); // Continue if the access code
    }
}
