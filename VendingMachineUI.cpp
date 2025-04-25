#include "VendingMachineUI.h"
#include <iostream>

using namespace std;

int main() {
    VendingMachineUI ui;
    ui.run();
    return 0;
}

// Constructor - No beverage definitions here; to be populated externally
VendingMachineUI::VendingMachineUI() {

    // Note: slots empty here — other component will populate
    
}

// Displays the main menu options to the user
void VendingMachineUI::displayMenu() {
    cout << "\n--- Vending Machine Menu ---" << endl;
    cout << "1. View Available Beverages" << endl;
    cout << "2. Select a Beverage" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
}

// Displays all available beverages in 2 rows and 4 columns format

void VendingMachineUI::showAvailableBeverages() {
    cout << "\n--- Available Beverages (25 cents each) ---" << endl;
    for (size_t i = 0; i < slots.size(); ++i) {

        // Displays index and beverage name; shows OUT OF STOCK if quantity is 0

        if (slots[i].quantity > 0) {
            cout << i + 1 << ". " << slots[i].name << "\t";
        } else {
            cout << i + 1 << ". " << slots[i].name << " (OUT OF STOCK)\t";
        }

        // After every 4th item, move to the next line

        if ((i + 1) % 4 == 0) cout << endl;
    }
    cout << endl;
}

// Checks if slot index is valid 
bool VendingMachineUI::isValidSlot(int slotIndex) {
    return slotIndex >= 0 && slotIndex < static_cast<int>(slots.size());
}

// Handles the process of selecting a beverage 
void VendingMachineUI::selectBeverage() {
    int choice;
    cout << "Enter slot number of beverage you'd like to select: ";
    cin >> choice;
    choice -= 1;                        // Adjust for 0-based index

    // Validates slot index and ensures if beverage is in stock or not
    if (!isValidSlot(choice) || slots[choice].quantity == 0) {
        cout << "Invalid slot or out of stock." << endl;
        return;
    }

    // Confirms beverage selection (Money transaction confirmed within money component)
    cout << "You selected: " << slots[choice].name << endl;

    // Note: here you'd notify the money component or transaction handler
}

// Main UI loop to run the program interface
void VendingMachineUI::run() {
    while (true) {
        displayMenu();                 // Show menu options
        int choice;
        cin >> choice;                 // Get user input
        
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from the menu.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;                 // Get user input

        switch (choice) {
            case 1:
                showAvailableBeverages(); // Show beverage list
                break;
            case 2:
                selectBeverage();         // Handle beverage selection
                break;
            case 3:
                cout << "Thank you! Goodbye." << endl; // Exit
                return;
            default:
                cout << "Invalid choice. Try again." << endl; // Invalid input handler
        }
    }
}

