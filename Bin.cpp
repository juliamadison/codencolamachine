#include "Bin.h"

Bin::Bin() {
   trayContents.clear();
}

bool Bin::isEmpty() const {
   return trayContents.empty();
}

void Bin::addToTray(const SodaSlot& slot) {
   trayContents.push_back(slot);
}

SodaSlot Bin::removeFromTray() {
   if (!trayContents.empty()) {
      SodaSlot last = trayContents.back();
      trayContents.pop_back();
      return last;
   }
   return SodaSlot(); // Return default SodaSlot if bin is empty
}

int Bin::getSize() const {
   return static_cast<int>(trayContents.size());
}