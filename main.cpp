#include <iostream>
#include "Bin.h"
#include "SodaSlot.h"

int main() {
   // Create some SodaSlots
   SodaSlot sprite("Sprite", 1.25f, 10);
   SodaSlot coke("Coke", 1.50f, 5);

   // Create a Bin and add SodaSlots to it
   Bin bin;
   bin.addToTray(sprite);
   bin.addToTray(coke);

   std::cout << "Bin size: " << bin.getSize() << std::endl;

   // Remove one from the bin
   SodaSlot removed = bin.removeFromTray();
   std::cout << "Removed: " << removed.getName() << std::endl;

   std::cout << "Bin size after removal: " << bin.getSize() << std::endl;

   return 0;
} 