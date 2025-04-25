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
