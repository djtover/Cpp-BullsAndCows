#pragma once
#include <iostream>
#include <string>
#include "calculate.hpp"
using namespace std;



namespace bullpgia
{
class Chooser
{
    public:
    Chooser();

    virtual string choose(uint length);
    
};
}; // namespace bullpgia