#pragma once
#ifndef MAINTENANCE_SYSTEM_H
#define MAINTENANCE_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

#include "Beverage.h"


class MaintenanceSystem { //New Code
private:
	bool isMaintenanceMode;
	
public:
    Maintenace(); 

    void enterMaintenaceMode();
    void exitMaintenaceMode();
    bool inMaintenaceMode();
    void checkInventory(const Dispenser& d);
    void refillChangeBin(const Money& m);

};

// Takes care of admin for managing drink stock
class MaintenanceSystem { //Old Code
private:
	std::vector<Beverage> beverageCatalog; // Code needed to perform maintenance tasks
	const std::string accessCode;
	static const int MAX_DRINK_REFILL = 50; // Stops overfilling
	static const int MAX_LABELNAME_LENGTH = 20; //Keeps label formatting consistent
    const float MIN_COST_VALUE = 0.50f; // Min Cost Limit
    const float MAX_COST_VALUE = 10.00f; // Max Cost Limit

        // Utility functions for system tasks
	std::vector<Beverage> prepareBeverage(); // setting up defaults or tests
	bool verifyMaintenanceUser(); // verifiying user security
	void ShowInventory(); // Show Current Drinks
	void refillBeverage(); // Restocking Drinks
	void updateBeverageDetails(); //Changing prices and names
	void showMaintenanceMenu(); // offering a user friendly menu

public:
	MaintenanceSystem(); // constructor
	void start(); // Kick off for MaintenanceSystem
};

#endif
