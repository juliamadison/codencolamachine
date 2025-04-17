// julia desimone
#ifndef COIN_ACCEPTOR_H
#define COIN_ACCEPTOR_H

#include <string>

class CoinAcceptor
{
private:
    int quarters;
    const std::string validCoin = "quarter";

    void rejectCoin(const std::string &coin);

public:
    CoinAcceptor();

    void coinsInserted();
    void validateCoin(const std::string &coin);
};

#endif
