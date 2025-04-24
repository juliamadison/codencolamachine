// julia desimone
// code n cola money component
// money.cpp

#include "Money.h"
#include <iostream>

using namespace std;

void Money::AddQuarter() // add quarter to change stock
{
    quarterStock++;
}

int Money::GetQuarterStock() const // return change stock for maintinence mode (will prolly have to change method name)
{
    return quarterStock;
}

void Money::CompleteTransaction()
{
    //DISPENSING COMPONENT
}
