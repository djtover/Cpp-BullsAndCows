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
    int j;
    int arrChoice[choice.length()];
    int arrGuess[guess.length()];

    for(i=0;i<choice.length();i++){
        arrChoice[i]=0;
    }
     for(i=0;i<guess.length();i++){
        arrGuess[i]=0;
    }
    // calculate bulls
    for (i = 0; i < guess.length(); i++)
    {
        if (guess.at(i) == choice.at(i))
        {
            bull++;
            arrChoice[i]=1;
            arrGuess[i]=1;
        }
    }
    // calculate cows
    for(i=0; i<guess.length();i++){
        for(j=0;j<choice.length();j++){
            if(i!=j){
                if(guess.at(i) == choice.at(j)){
                    if(arrChoice[j]==0 && arrGuess[i]==0){
                        arrChoice[j]=1;
                        arrGuess[i]=1;
                        pgia++;
                    }
                }
            }
        }
    }


    // cout << choice << "," << guess << "," << bull << "," << pgia << endl;
    string ans = std::to_string(bull) + "," + std::to_string(pgia);
    return ans;
}


}; // namespace bullpgia
