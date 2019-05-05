#pragma once

#include "Guesser.hpp"
using namespace std;
namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
     private:
     string best;
     string current;
     uint size=0;
     uint start;
     uint end;
     uint bbull;
     uint bpgia;
     uint cbull;
     uint cpgia;
     int count[10]; 
     string switchCase();
     public:
     void startNewGame(uint length) override;
     string guess()override;
     void learn(string reply)override;
			
};
}; // namespace bullpgia
