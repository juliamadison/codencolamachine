#include "SodaShelfSlot.h"

// Constructor definition
SodaShelfSlot::SodaShelfSlot(int id, int capacity) {
   slotID = id;
   maxCapacity = capacity;
   currentStock = 0;
   isFull = false;
   isEmpty = true;
}

void SodaShelfSlot::addToTray() {
   if (currentStock < maxCapacity) {
      currentStock++;
      isEmpty = false;
      isFull = (currentStock == maxCapacity);
   }
}

void SodaShelfSlot::removeFromTray() {
   if (currentStock > 0) {
      currentStock--;
      isFull = false;
      isEmpty = (currentStock == 0);
   }
}

void SodaShelfSlot::clearTray() {
   currentStock = 0;
   isFull = false;
   isEmpty = true;
}

// Optional accessors
int SodaShelfSlot::getCurrentStock() const {
   return currentStock;
}

bool SodaShelfSlot::getIsFull() const {
   return isFull;
}

bool SodaShelfSlot::getIsEmpty() const {
   return isEmpty;
}