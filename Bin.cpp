#include "Bin.h"

// Constructor clears the bin initially
Bin::Bin() {
   trayContents.clear();
}

// Returns true if there are no sodas in the bin
bool Bin::isEmpty() const {
   return trayContents.empty();
}

// Adds a SodaCan to the bin
void Bin::addToTray(const SodaCan& can) {
   trayContents.push_back(can);
}

// Removes and returns the last SodaCan
// If bin is empty, returns an empty SodaCan
SodaCan Bin::removeFromTray() {
   if (!trayContents.empty()) {
      SodaCan last = trayContents.back();
      trayContents.pop_back();
      return last;
   }
   return SodaCan();
}

// Returns the number of sodas in the bin
int Bin::getSize() const {
   return static_cast<int>(trayContents.size());
}