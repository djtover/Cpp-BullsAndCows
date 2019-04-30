#pragma once

#include "Guesser.hpp"
using namespace std;
namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
     void startNewGame(uint length);
     string guess()override;
     void learn(int reply);
			
};
}; // namespace bullpgia
