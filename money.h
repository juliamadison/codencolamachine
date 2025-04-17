// julia desimone
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
    float customerBalance = 0.0f;
    float changeStock = 0.0f;
    bool canReturnChange = false;

    void UpdateCoinStock(float insertedCoin);
    void DispenseChange(float amount);
    void CalculateChange();
    bool HasSufficientChange(float change);

public:
    void AddCoin(float insertedCoin);
    void ValidatePayment(float total);
    void CompleteTransaction(float total);
    void Refund();
};

#endif
