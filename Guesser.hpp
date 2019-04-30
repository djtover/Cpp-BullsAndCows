#pragma once
#include <iostream>
using namespace std;
#include "calculate.hpp"

namespace bullpgia
{
class Guesser
{
    protected:
   uint length;
    public:
    
    void startNewGame(uint Length){}
    virtual string guess()=0;
    void learn(int reply){}
};
}; // namespace bullpgia