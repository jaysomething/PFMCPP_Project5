#pragma once

#include <string>
#include "LeakedObjectDetector.h"

struct Speaker
{
    std::string name;
    bool isOn{false};
    float coneSize{6.0f};
    bool isPorted{true};

    struct Eq
    {
        bool isOn;
        std::string shape;
        double freq;
        double gain;

        Eq();
        ~Eq();

        void printStatus();
        void setFreq(double bandFreq);
        void setGain(double bandGain);
        void sweepFrequency(double freqStart, double freqEnd);
    };

    Eq eq;

    Speaker(std::string speakerName);
    ~Speaker();

    bool toggleOnOff();
    void turnOnEq(Eq eq1);
    void selfToggleOnOFF();

    JUCE_LEAK_DETECTOR(Speaker)
};
