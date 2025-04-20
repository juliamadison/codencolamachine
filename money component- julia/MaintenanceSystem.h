#pragma once
#ifndef MAINTENANCE_SYSTEM_H
#define MAINTENANCE_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

#include "Beverage.h"

class MaintenanceSystem {
private:
	std::vector<Beverage> beverageList;
	const std::string correctCode;
	const int MAX_REFILL = 50;
	const int MAX_NAME_LEN = 20;
	const float MIN_PRICE = 0.50f;
	const float MAX_PRICE = 10.00f;

	std::vector<Beverage> initalizeBeverage();
	bool authenticateMaintenanceUser();
	void DisplayInventory();
	void refillBeverage();
	void modifyBeverageDetails();
	void maintenanceMenu();

public:
	MaintenanceSystem();
	void start();
};

#endif
