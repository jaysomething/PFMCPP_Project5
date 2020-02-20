#include "Mixer.h"

Mixer::Mixer(std::string mixerName, size_t numChan) : name(mixerName), numberOfChannels(numChan)
{
    channels.reserve(numberOfChannels);
    for (size_t i = 0; i < numberOfChannels; i++)
    {
        channels[i].number = int(i) + 1;
    }
}

void Mixer::printStatus()
{
    std::cout << name << " " << numberOfChannels << "-channel mixer is ";
    std::cout << (isOn ? "ON" : "OFF") << std::endl;
}

void Mixer::muteChannels(size_t channelStart, size_t channelEnd)
{
    if (channelEnd > numberOfChannels)
    {
        channelEnd = numberOfChannels;
    }

    if (channelStart < 1)
    {
        channelStart = 1;
    }

    for (size_t i = channelStart - 1; i < channelEnd; i++)
    {
        channels[i].isMuted = true;
    }
}

void Mixer::showMuteStatus()
{
    for (size_t i = 0; i < numberOfChannels; i++)
    {
        std::cout << "Channel " << channels[i].number << " is " << (channels[i].isMuted ? "muted" : "ON") << std::endl;
    }
}

Mixer::Channel::Eq::Eq() : shape("Bell"), freq(200.0), gain(0.0) {}

void Mixer::Channel::Eq::setFreq(double bandFreq)
{
    freq = bandFreq;
    std::cout << "Frequency is set to " << bandFreq << " Hz" << std::endl;
}

void Mixer::Channel::Eq::setGain(double bandGain)
{
    gain = bandGain;
    std::cout << "Gain is set to " << bandGain << " dB" << std::endl;
}

void Mixer::Channel::adjustEq(Eq eq1)
{
    double freq;
    double gain;

    std::cout << "Set frequency to: " << std::endl;
    freq = 80.0;
    eq1.setFreq(freq);

    std::cout << "Set gain to: " << std::endl;
    gain = 1.0;
    eq1.setGain(gain);
}
