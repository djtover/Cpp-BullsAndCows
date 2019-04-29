#pragma once

#include "Guesser.hpp"
using namespace std;
namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
     void startNewGame(uint length) override;
     string guess()override;
     void learn(int reply)override;
			
};
}; // namespace bullpgia
