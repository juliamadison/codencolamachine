// julia desimone
// code n cola money component
// coinAcceptor.cpp

#include "CoinAcceptor.h"
#include <iostream>

using namespace std;

CoinAcceptor::CoinAcceptor() {
    acceptedCoins.push_back(Coin("quarter", 0.25f)); // creates an object for the coin class for a quarter and adds it to a vector of accepted coins. if we wanted to take any more coins, we'd add another object in here
}

void CoinAcceptor::InsertCoin(Money& money)
{
    string coin;
    cout << "insert coin: "; // this might be done in the ui component idk
    cin >> coin;

    float value = 0.0f; // by default, coin value is 0
    if (ValidCoin(coin, value)) {
        if (value > 0.25f) {  // only accepts coin if value is over 25 cents. this is to avoid doing change and stuff. if we accept dollar or half dollar coins in the future this will be helpful
            if (coin == "quarter") {
                money.AddQuarter();  // add a quarter to change stock
            }
            money.CompleteTransaction();  // if coin is accepted and value is enough to pay, complete transaction
        }
        else {
            RejectCoin(coin);  // reject coin if value is less than 25 cents
        }
    }
}

bool CoinAcceptor::ValidCoin(const string& coin, float& value) // checks if coin is valid to be used
{
    for (const Coin& accepted : acceptedCoins) { // looping thru list of accepted coins to see if valid
        if (coin == accepted.name) {
            value = accepted.value;  // set coin value
            return true;  // coin is valid yay!
        }
    }

    // if the coin is not found in valid coins list, reject it
    RejectCoin(coin);
    return false;
}

void CoinAcceptor::RejectCoin(const string& coin)
{
    // coin is rejected idk what else to do here LOL
}
