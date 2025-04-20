#include "MaintenanceSystem.h"
#include "Beverage.h"
#include <iostream>
#include <limits>

using namespace std;

MaintenanceSystem::MaintenanceSystem() : correctCode("1234") {

    beverageList = initalizeBeverage();

}

std::vector<Beverage> MaintenanceSystem::initalizeBeverage() {
	return{
		Beverage("Cola", 1.50f, 10),
		Beverage("Sprite", 1.25f, 8),
		Beverage("Water", 1.00f, 12)
	};
}

bool MaintenanceSystem::authenticateMaintenanceUser() {
    string accessCode;
    std::cout << "Enter maintenance access code: ";
    std::cin >> accessCode;
    if (accessCode == correctCode) {
        return true;
    }
    else {
        std::cout << "Access Denied" << endl;
        return false;
    }
}

void MaintenanceSystem::DisplayInventory() {
	std::cout << "Current Inventory:" << std::endl;
	for (size_t i = 0; i < beverageList.size(); ++i) {
		cout << i << ". " << beverageList[i].name
			<< " | Price: $" << beverageList[i].price
			<< " | Stock: " << beverageList[i].stock << endl;
	}
}

void MaintenanceSystem::refillBeverage() {
    int index, quantity;
    std::cout << "Select beverage to refill (index): ";
    std::cin >> index;

    if (index < 0 || index >= static_cast<int>(beverageList.size())) {
        std::cout << "Invalid selection." << std::endl;
        return;
    }

    cout << "Enter quantity to add (Max: " << MAX_REFILL << "): ";
    cin >> quantity;

    if (quantity <= 0 || quantity > MAX_REFILL) {
        cout << "Error: Quantity must be between 1 and " << MAX_REFILL << endl;
        return;
    }

    beverageList[index].stock += quantity;
    cout << "Stock updated." << endl;
}

void MaintenanceSystem::modifyBeverageDetails() {
    DisplayInventory();
    int index;
    std::cout << "Select beverage to modify (index): " << std::endl;
    std::cin >> index;

    if (std::cin.fail() || index < 1 || static_cast<size_t>(index) > beverageList.size()) {
        std::cout << "Invalid selection." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    
    int choice;
    std::cout << "1. Change Name, 2. Change Price, 3. Cancel" << std::endl;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cout << "Invalid input." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    switch (choice) {
    case 1: {
        std::string newName;
        std::cout << "Enter new name (Max " << MAX_NAME_LEN << " characters): ";
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::getline(cin, newName);
        if (newName.empty() || newName.length() > MAX_NAME_LEN) {
            cout << "Error: Name must be 1–" << MAX_NAME_LEN << " characters" << endl;
            return;
        }
        beverageList[index].name = newName;
        break;
    }
    case 2: {
        float newPrice;
        cout << "Enter new price ($" << MIN_PRICE << " - $" << MAX_PRICE << "): ";
        cin >> newPrice;
        if (newPrice < MIN_PRICE || newPrice > MAX_PRICE) {
            cout << "Error: Price must be between $" << MIN_PRICE << " and $" << MAX_PRICE << endl;
            return;
        }
        beverageList[index].price = newPrice;
        break;
    }
    case 3:
        return;
    default:
        cout << "Invalid option." << endl;
        return;
    }

    cout << "Details updated." << endl;
}

void MaintenanceSystem::maintenanceMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- Maintenance Menu ---" << std::endl;
        std::cout << "1. Display Inventory" << std::endl;
        std::cout << "2. Refill Beverage" << std::endl;
        std::cout << "3. Modify Beverage" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter choice: ";
        cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1:
            DisplayInventory();
            break;
        case 2:
            refillBeverage();
            break;
        case 3:
            modifyBeverageDetails();
            break;
        case 4:
            std::cout << "Exiting maintenance mode..." << std::endl;
            return;
        default:
            cout << "Invalid option." << endl;
        }
    }
}

void MaintenanceSystem::start() {
    if (authenticateMaintenanceUser()) {
        maintenanceMenu();
    }
}

