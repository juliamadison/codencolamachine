// julia desimone
// code n cola money component
// componentTest.cpp

#include <iostream>
#include "CoinAcceptor.h"
#include "Money.h"

using namespace std;

int main()
{
    CoinAcceptor acceptor;
    Money money;

    acceptor.InsertCoin(money);

    cout << "quarters stock: " << money.GetQuarterStock() << endl; // for testing purposes, display how many quarters r in the stock

    return 0;
}
