#pragma once
#ifndef MAINTENANCE_SYSTEM_H
#define MAINTENANCE_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

#include "Beverage.h"


class MaintenanceSystem {
private:
	boll isMaintenanceMode;
	
public:
    void enterMaintenaceMode();
    void exitMaintenaceMode();
    bool inMaintenaceMode();
    void checkInventory();
    void refillChangeBin();

};

#endif
