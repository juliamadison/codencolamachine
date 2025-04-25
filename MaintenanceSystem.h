#pragma once
#ifndef MAINTENANCE_SYSTEM_H
#define MAINTENANCE_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

#include "Soda.h"

class MaintenanceSystem {
private:
	std::vector<Beverage> beverageCatalog;
	const std::string slotID;
	static const int MAX_DRINK_REFILL = 50;
	static const int MAX_LABELNAME_LENGTH = 20;
    const float MIN_COST_VALUE = 0.50f;
    const float MAX_COST_VALUE = 10.00f;

	std::vector<Beverage> InitializeSlots();
	bool verifyMaintenanceUser();
	void checkInventory();
	void refillSlot();
	void updateSlotDetails();
	void MaintenanceMenu();

public:
	MaintenanceSystem();
	void start();
};

#endif
