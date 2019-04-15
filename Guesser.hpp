#pragma once
#include <iostream>
#include <string>
using  std::string;

namespace bullpgia
{

class Guesser
{
    // private:
    // uint length;

    public:
    uint length;
    Guesser();
    void startNewGame(uint length);

    virtual string guess();
    void learn(int reply);
};
}; // namespace bullpgia