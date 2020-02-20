#include <iostream>
#include <string>

#include "Bass.h"

Bass::Bass() : name("Fender"), numberOfStrings(5) {}
Bass::Bass(std::string bassName, int numString) : name(bassName), numberOfStrings(numString) {}

void Bass::playInstrument()
{
    std::cout << "Playing bass" << std::endl;
    std::cout << name << " " << numberOfStrings << "-string" << std::endl;
    std::cout << scale << "' scale";
    std::cout << (isActive ? " active bass" : " passive bass") << std::endl;
}

void Bass::playOpenStrings(int numStrings)
{
    int index{1};

    if (numStrings == 6)
    {
        index = 0;
    }

    for (int i = 0; i < numStrings; i++)
    {
        std::cout << circleOfFourths[(index + i) % 12];

        if (i < numStrings - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

bool Bass::activeStatus() 
{ 
    return isActive; 
}

void Bass::reportActive()
{
    std::cout << "This " + this->name + " is ";
    std::cout << (this->activeStatus() ? "an active" : "a passive") << " bass" << std::endl;
}
