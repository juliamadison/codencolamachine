#ifndef BIN_H
#define BIN_H

#include <vector>

class Product;

class Bin
{
private:
    std::vector<Product> trayContents;

public:
    bool isEmpty();
    void addToTray(Product product);
    Product removeFromTray();
};

#endif
