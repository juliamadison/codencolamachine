#pragma once
#ifndef MAINTENANCE_SYSTEM_H
#define MAINTENANCE_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

#include "Beverage.h"


class MaintenanceSystem {
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

#endif
