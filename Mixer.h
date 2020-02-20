#pragma once

#include <string>
#include <array>
#include <vector>
#include "LeakedObjectDetector.h"

struct Mixer
{
    std::string name;
    size_t numberOfChannels;
    bool isOn{true};

    struct Channel
    {
        int number{0};
        bool isMuted{false};

        struct Eq
        {
            std::string shape;
            double freq;
            double gain;

            Eq();

            void setFreq(double freq);
            void setGain(double gain);
        };

        struct Fader
        {
            double position{0.0};

            Fader() {}
        };

        void adjustEq(Eq eq1);
    };

    std::vector<Channel> channels;

    Mixer(std::string mixerName, size_t numChan);

    void printStatus();
    void muteChannels(size_t channelStart, size_t channelEnd);
    void showMuteStatus();

    JUCE_LEAK_DETECTOR(Mixer)
};
