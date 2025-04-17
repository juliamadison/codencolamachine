#ifndef SODA_SHELF_SLOT_H
#define SODA_SHELF_SLOT_H

class SodaShelfSlot
{
private:
    int slotID;
    int currentStock;
    int maxCapacity;
    bool isFull;
    bool isEmpty;

public:
    void addToTray();
    void removeFromTray();
    void clearTray();
};

#endif
