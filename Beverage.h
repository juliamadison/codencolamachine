#pragma once
#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <string>

class Beverage {
public:
    std::string name;
    float price;
    int stock;

    Beverage(std::string name, float price, int stock) : name(name), price(price), stock(stock) {}
};

#endif 