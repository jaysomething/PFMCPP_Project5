#include <iostream>
#include <string>

#include "Speaker.h"

Speaker::Speaker(std::string speakerName) : name(speakerName) {}
Speaker::~Speaker() {}

bool Speaker::toggleOnOff()
{
    if (isOn)
    {
        isOn = false;
        return false;
    }

    isOn = true;
    return true;
}

void Speaker::turnOnEq(Eq eq1)
{
    eq1.isOn = true;
    std::cout << "EQ has been turned ON" << std::endl;
}

Speaker::Eq::Eq() : isOn(true), shape("Bell"), freq(200.0), gain(0.0) {}
Speaker::Eq::~Eq() { isOn = false; }

void Speaker::Eq::printStatus()
{
    std::cout << (isOn ? "EQ is ON" : "EQ is OFF") << std::endl;
    std::cout << "Shape is " << shape << std::endl;
    std::cout << "Frequency is " << freq << " Hz" << std::endl;
    std::cout << "Gain is " << gain << " dB" << std::endl;
}

void Speaker::Eq::setFreq(double bandFreq)
{
    freq = bandFreq;
    std::cout << "Frequency set to " << freq << " Hz" << std::endl;
}

void Speaker::Eq::setGain(double bandGain)
{
    gain = bandGain;
    std::cout << "Gain set to " << gain << " dB" << std::endl;
}

void Speaker::Eq::sweepFrequency(double freqStart, double freqEnd)
{
    std::cout << "Begin sweep, starting from " << freqStart << std::endl;

    for (freq = freqStart; freq <= freqEnd; freq++)
    {
        std::cout << freq << std::endl;
    }

    freq = freqEnd;
    std::cout << "End sweep" << std::endl;
}

void Speaker::selfToggleOnOFF()
{
    std::cout << "This " + this->name + " speaker has turned itself ";
    std::cout << (this->toggleOnOff() ? "ON!!!\n" : "OFF!!!\n");
}
