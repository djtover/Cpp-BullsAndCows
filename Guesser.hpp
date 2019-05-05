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
    
    virtual void startNewGame(uint Length){}
    virtual string guess()=0;
    virtual void learn(string reply){}
};
}; // namespace bullpgia