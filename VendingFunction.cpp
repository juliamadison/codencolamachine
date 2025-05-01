#include <iostream>
#include "Bin.h"
#include "SodaSlot.h"
#include "SodaCan.h"
#include "VendingFunction.h" 

using namespace std;

int main() {
   // Create a SodaSlot containing 5 Colas, each priced at 25 cents
   SodaSlot colaSlot("Cola", 0.25f, 5);

   // Create the Bin to store dispensed sodas
   Bin bin;

   // Call our vending function to simulate dispensing a soda into the bin
   dispenseFromSlotToBin(colaSlot, bin);

   // Output the updated stock
   cout << "Colas remaining in slot: " << colaSlot.getStock() << endl;

   // Output how many sodas are now in the bin
   cout << "Total items in bin: " << bin.getSize() << endl;

   return 0;
}