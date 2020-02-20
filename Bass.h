#pragma once

#include <string>
#include <array>
#include <vector>
#include "LeakedObjectDetector.h"

struct Bass
{
    std::string name;
    int numberOfStrings;
    int scale{34};
    bool isActive{true};
    std::array<std::string, 12> circleOfFourths = {"C", "G", "D", "A", "E", "B", "Gb", "Db", "Ab", "Eb", "Bb", "F"};

    Bass();
    Bass(std::string bassName, int numString);

    void playInstrument();
    void playOpenStrings(int numberOfStrings);
    bool activeStatus();
    void reportActive();

    JUCE_LEAK_DETECTOR(Bass)
};
