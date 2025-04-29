#include <iostream>
#include "Bin.h"
#include "SodaSlot.h"
#include "SodaCan.h"

using namespace std;

// Main program to simulate a vending machine dispensing Cola
int main() {
   // Create a SodaSlot for Cola, price is 25 cents, 5 Colas available
   SodaSlot colaSlot("Cola", 0.25f, 5);

   // Create the bin to collect dispensed sodas
   Bin bin;

   // --- Simulate a user buying a Cola ---

   // Dispense one Cola from the slot
   SodaCan dispensedCola = colaSlot.dispenseBeverage();

   // Add the dispensed Cola to the bin
   bin.addToTray(dispensedCola);

   // Display information about the dispensed Cola
   cout << "User purchased: " << dispensedCola.name << " for $" << dispensedCola.price << endl;

   // Show how many Colas are left in the slot
   cout << "Remaining Colas in slot: " << colaSlot.getStock() << " cans" << endl;

   // Show how many sodas are currently collected in the bin
   cout << "Total items in bin: " << bin.getSize() << endl;

   return 0;
}
