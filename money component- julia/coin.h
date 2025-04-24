// julia desimone
// code n cola money component
// coin.h

// *note i did not add a cpp file because there are no methods in this class :) just pure data thats all 
// the reason the coins were done this way so if in the future the machine needs to take different coins, we have this class to do that!
// dr d placed emphasis on making our machine able to be updated to add more features in the future even if we dont have them in the mvp :P

#ifndef COIN_H
#define COIN_H
#include <string>

using namespace std;

class Coin {
public:
    string name; 
    float value;

    Coin(const string& name, float value) : name(name), value(value) {}
};

#endif
