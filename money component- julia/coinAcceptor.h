// julia desimone
// code n cola money component
// coinAcceptor.h

#ifndef COIN_ACCEPTOR_H
#define COIN_ACCEPTOR_H

#include "Coin.h"
#include "Money.h"
#include <string>
#include <vector>

using namespace std;

class CoinAcceptor
{
private:
    vector<Coin> acceptedCoins;
    void RejectCoin(const string& coin);

public:
    CoinAcceptor();
    void InsertCoin(Money& money);
    bool ValidCoin(const string& coin, float& value);
};

#endif
