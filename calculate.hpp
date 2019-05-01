#pragma once
#include <iostream>
using namespace std;
namespace bullpgia
{
static string calculateBullAndPgia(string choice, string guess)
{

    int bull = 0;
    int pgia = 0;
    int i;
    for (i = 0; i < guess.length(); i++)
    {
        if (guess.at(i) == choice.at(i))
        {
            bull++;
        }
    }
    cout << choice << "," << guess << "," << bull << "," << pgia << endl;
    string ans = std::to_string(bull) + "," + std::to_string(pgia);
    return ans;
}

}; // namespace bullpgia
