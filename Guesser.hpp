#pragma once
#include <iostream>
#include <string>
#include "calculate.hpp"
using namespace std;

namespace bullpgia
{
class Guesser
{
    protected:
uint length;
    public:
    // uint length;
    Guesser();
    void startNewGame(uint length);

    virtual string guess();
    virtual void learn(int bp);
};
}; // namespace bullpgia