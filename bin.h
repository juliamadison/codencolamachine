#ifndef BIN_H
#define BIN_H

#include <vector>
#include "SodaCan.h"

// Class that represents the collection bin in the vending machine.
// The bin holds sodas that have been dispensed to the user.
class Bin {
private:
   std::vector<SodaCan> trayContents; // Stores the dispensed sodas

public:
   // Default constructor
   Bin();

   // Check if the bin is empty
   bool isEmpty() const;

   // Add a SodaCan to the bin
   void addToTray(const SodaCan& can);

   // Remove and return the last SodaCan from the bin
   SodaCan removeFromTray();

   // Get how many sodas are currently in the bin
   int getSize() const;
};

#endif