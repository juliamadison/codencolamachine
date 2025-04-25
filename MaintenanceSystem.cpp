#include "MaintenanceSystem.h"
#include "Beverage.h"
#include <iostream>
#include <limits>

using namespace std;

MaintenanceSystem::MaintenanceSystem() : accessCode("1234") {

    beverageCatalog = prepareBeverage();

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
