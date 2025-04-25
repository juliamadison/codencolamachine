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

void MaintenanceSystem::start() {
    if (verifyMaintenanceUser()) {
        showMaintenanceMenu();
    }
}
