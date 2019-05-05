#include <string>
#include <iostream>

#include "SmartGuesser.hpp"
using std::string;
namespace bullpgia
{

string SmartGuesser::switchCase()
{
    string ans = "";
    
    switch (size)
    {
    case (0):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '0';
            ans += c;
        }
        break;
    case (1):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '1';
            ans += c;
            
        }
        break;
    case (2):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '2';
            ans += c;
            
        }
        break;
    case (3):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '3';
            ans += c;
        }
        break;
    case (4):
    for (uint i = 0; i < this->length; ++i)
        {
            char c = '4';
            ans += c;
        }
        break;
    case (5):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '5';
            ans += c;
        }
        break;
    case (6):
    for (uint i = 0; i < this->length; ++i)
        {
            char c = '6';
            ans += c;
        }
        break;
    case (7):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '7';
            ans += c;
        }
        break;
    case (8):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '8';
            ans += c;
        }
        break;
    case (9):
        for (uint i = 0; i < this->length; ++i)
        {
            char c = '9';
            ans += c;
        }
        break;

    }
    return ans;
}
void SmartGuesser::learn(string reply)
{
    int i = reply.find(",");
    string b = reply.substr(0,i);
    string p = reply.substr(i+1,reply.length());
    cbull = std::stoi(b);
    cpgia = std::stoi(p);

    if(size<=10){
        count[size-1]=cbull;
    }
}
string SmartGuesser::guess()
{
    string ans="";
    if (size < 10)
    {
        ans = switchCase();
    }
    else if(size==10){
        for(int i=0; i<10;i++){
            for(int j=0;j<count[i];j++){

                ans += std::to_string(i);
                best = ans;
            }
        }
          
    }
    else{
        if(cbull > bbull){
            best = current;
            bbull = cbull;
            start = 0;
            end = 1;
        }
        if(end < length){
            ans = best;
            std::swap(best[start], best[end]);
            ans.swap(best); 
        }
        else{
            start++;
            end = start + 1;
            ans = best;
            std::swap(best[start], best[end]);
            ans.swap(best);
        }

    }
   
    current = ans;
    size++;
    return current;
}
void SmartGuesser::startNewGame(uint Length)
{
    best = "";
    current = "";
    start = cbull = cpgia = bbull = bpgia = 0;
    end = 1;
    length = Length;
    size=0;
    for(int i=0;i<10;i++){
        count[i]=0;
    }
}
}; // namespace bullpgia