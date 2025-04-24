// julia desimone
// code n cola money component
// money.h

#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
    int quarterStock = 0;

public:
    void AddQuarter();
    int GetQuarterStock() const;
    void CompleteTransaction();
};

#endif
