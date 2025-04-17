#pragma once
#ifndef MAINTENANCE_SYSTEM_H
#define MAINTENANCE_SYSTEM_H

#include <string>
#include <vector>
#include <iostream>

class Beverage {
public:
	std::string name;
	float price;
	int stock;
	
	Beverage(const std::string& name, float price, int stock);

};

class MaintenanceSystem {
private:
	std::vector<Beverage> beverageList;
	const std::string correctCode = "1234";
	const int MAX_REFILL = 50;
	const int MAX_NAME_LEN = 20;
	const float MIN_PRICE = 0.50f;
	const float MAX_PRICE = 10.00f;

	std::vector<Beverage> initalizeBeverage();
	bool authenticateMaintenanceUser();
	void displayInventory() const;
	void refillBeverage();
	void modifyBeverageDetails();
	void maintenanceMenu();

	bool isValidIndex(int Index) const;
	bool isValidQuantity(int Quantity) const;
	bool isValidName(const std::string& name) const;
	bool isValidPrice(float price) const;

public:
	MaintenanceSystem();
	void start();
};

#endif
