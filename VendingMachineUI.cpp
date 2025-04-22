#include "VendingMachineUI.h"
#include <iostream>

using namespace std;


int main() {
    VendingMachineUI ui;
    ui.run();
    return 0;
}

VendingMachineUI::VendingMachineUI() {
    
    slots.push_back({ "Cola", 1, 3 });             // Slot 1: Cola, $1, 3 in stock
    slots.push_back({ "Lemonade", 1, 0 });        // Slot 2: Lemonade, $1, out of stock
    slots.push_back({ "Water", 1, 3 });          // Slot 3: Water, $1, 3 in stock
    slots.push_back({ "Ginger Ale", 1, 3 });    // Slot 4: Ginger Ale
    slots.push_back({ "Orange Soda", 1, 3 });  // Slot 5: Orange Soda 
    slots.push_back({ "Iced Tea", 1, 3 });    // Slot 6: Iced Tea
    slots.push_back({ "Sanitizer", 1, 3 });  // Slot 7: Sanitizer
    slots.push_back({ "Pepsi", 1, 3 });     // Slot 8: Pepsi
   
}


void VendingMachineUI::displayMenu() {
    cout << "\n--- Vending Machine Menu ---" << endl;
    cout << "1. View Available Beverages" << endl;
    cout << "2. Select a Beverage" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice: ";
}

void VendingMachineUI::showAvailableBeverages() {
    for (size_t i = 0; i < slots.size(); ++i) {
        cout << i + 1 << ". ";
        if (slots[i].quantity > 0) {
            cout << slots[i].name << " - Price: $" << slots[i].price << ", Quantity: " << slots[i].quantity << endl;
        }
        else {
            cout << slots[i].name << " - OUT OF STOCK" << endl;
        }
    }
}

bool VendingMachineUI::isValidSlot(int slotIndex) {
    return slotIndex >= 0 && slotIndex < static_cast<int>(slots.size());
}

// Handles the process of selecting and purchasing a beverage
void VendingMachineUI::selectBeverage() {
    int choice;
    cout << "Enter slot number of beverage you'd like to purchase: ";
    cin >> choice;
    choice -= 1; // Adjust for 0-based index
    
    // Validate slot index and stock
    if (!isValidSlot(choice) || slots[choice].quantity == 0) {
        cout << "Invalid slot or out of stock." << endl;
        return;
    }

    int insertedAmount;
    cout << "Insert $" << slots[choice].price << " to proceed: ";
    cin >> insertedAmount;

    if (insertedAmount == slots[choice].price) {
        slots[choice].quantity--;
        cout << "Please take your beverage: " << slots[choice].name << endl;
    }
    else if (insertedAmount < slots[choice].price) {
        cout << "Insufficient funds. Please add more or cancel." << endl;
        cout << "1. Add more coins\n2. Cancel\nEnter choice: ";
        int subChoice;
        cin >> subChoice;

        if (subChoice == 1) {
            int moreCoins;
            cout << "Enter additional amount: ";
            cin >> moreCoins;
            if (insertedAmount + moreCoins >= slots[choice].price) {
                slots[choice].quantity--;
                cout << "Please take your beverage: " << slots[choice].name << endl;
                if (insertedAmount + moreCoins > slots[choice].price) {
                    cout << "Change returned: $" << (insertedAmount + moreCoins - slots[choice].price) << endl;
                }
            }
            else {
                cout << "Still insufficient. Transaction canceled." << endl;
            }
        }
        else {
            cout << "Transaction canceled." << endl;
        }
    }
    else {
        slots[choice].quantity--;
        cout << "Please take your beverage: " << slots[choice].name << endl;
        cout << "Change returned: $" << (insertedAmount - slots[choice].price) << endl;
    }
}

void VendingMachineUI::run() {
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            showAvailableBeverages();
            break;
        case 2:
            selectBeverage();
            break;
        case 3:
            cout << "Thank you! Goodbye." << endl;
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
