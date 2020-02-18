/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main to use your wrapper classes, which have your UDTs as pointer member variables.
 
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>

#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */

struct Speaker
{
    Speaker(std::string speakerName) : name(speakerName) {}
    ~Speaker() {}

    std::string name;
    bool isOn{false};
    float coneSize{6.0f};
    bool isPorted{true};

    struct Eq
    {
        Eq() : isOn(true), shape("Bell"), freq(200.0), gain(0.0) {}
        ~Eq()
        {
            isOn = false;
        }

        bool isOn;
        std::string shape;
        double freq;
        double gain;

        void printStatus();
        void setFreq(double bandFreq);
        void setGain(double bandGain);
        void sweepFrequency(double freqStart, double freqEnd);
    };

    Eq eq;

    bool toggleOnOff();
    void turnOnEq(Eq eq1);
    void selfToggleOnOFF()
    {
        std::cout << "This " + this->name + " speaker has turned itself ";
        std::cout << (this->toggleOnOff() ? "ON!!!\n" : "OFF!!!\n");
    }

    JUCE_LEAK_DETECTOR(Speaker)
};

struct SpeakerWrapper
{
    SpeakerWrapper(Speaker *ptr) : ptrSpeaker(ptr) {}
    ~SpeakerWrapper() { delete ptrSpeaker; }
    Speaker *ptrSpeaker = nullptr;
};

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

/*
 copied UDT 2:
 */

struct Bass
{
    Bass() : name("Fender"), numberOfStrings(5) {}
    Bass(std::string bassName, int numString) : name(bassName), numberOfStrings(numString) {}

    std::string name;
    int numberOfStrings;
    int scale{34};
    bool isActive{true};
    std::array<std::string, 12> circleOfFourths = {"C", "G", "D", "A", "E", "B", "Gb", "Db", "Ab", "Eb", "Bb", "F"};

    void playInstrument();
    void playOpenStrings(int numberOfStrings);
    bool activeStatus() { return isActive; }
    void reportActive()
    {
        std::cout << "This " + this->name + " is ";
        std::cout << (this->activeStatus() ? "an active" : "a passive") << " bass" << std::endl;
    }

    JUCE_LEAK_DETECTOR(Bass)
};

struct BassWrapper
{
    BassWrapper(Bass *ptr) : ptrBass(ptr) {}
    ~BassWrapper() { delete ptrBass; }
    Bass *ptrBass = nullptr;
};

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

/*
 copied UDT 3:
 */

struct Mixer
{
    Mixer(std::string mixerName, size_t numChan) : name(mixerName), numberOfChannels(numChan)
    {
        channels.reserve(numberOfChannels);
        for (size_t i = 0; i < numberOfChannels; i++)
        {
            channels[i].number = int(i) + 1;
        }
    }

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

            Eq() : shape("Bell"), freq(200.0), gain(0.0) {}

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

    void printStatus();
    void muteChannels(size_t channelStart, size_t channelEnd);
    void showMuteStatus();

    JUCE_LEAK_DETECTOR(Mixer)
};

struct MixerWrapper
{
    MixerWrapper(Mixer *ptr) : ptrMixer(ptr) {}
    ~MixerWrapper() { delete ptrMixer; }
    Mixer *ptrMixer = nullptr;
};

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

/*
 new UDT 4:
 */

struct SignalChain
{
    BassWrapper bassWrapper{new Bass("Fender", 5)};
    Bass &bass = *bassWrapper.ptrBass;

    MixerWrapper mixerWrapper{new Mixer("Midas", 32)};
    Mixer &mixer = *mixerWrapper.ptrMixer;

    SpeakerWrapper speakerWrapper{new Speaker("ADAM")};
    Speaker &speaker = *speakerWrapper.ptrSpeaker;

    JUCE_LEAK_DETECTOR(SignalChain)
};

struct SignalChainWrapper
{
    SignalChainWrapper(SignalChain *ptr) : ptrSignalChain(ptr) {}
    ~SignalChainWrapper() { delete ptrSignalChain; }
    SignalChain *ptrSignalChain = nullptr;
};

/*
 new UDT 5:
 */

struct Studio
{
    BassWrapper bassWrapper{new Bass("Ken Smith", 6)};
    Bass &bass = *bassWrapper.ptrBass;

    MixerWrapper mixerWrapper{new Mixer("Mackie", 8)};
    Mixer &mixer = *mixerWrapper.ptrMixer;

    SpeakerWrapper speakerWrapper{new Speaker("Genelec")};
    Speaker &speaker = *speakerWrapper.ptrSpeaker;

    JUCE_LEAK_DETECTOR(Studio)
};

struct StudioWrapper
{
    StudioWrapper(Studio *ptr) : ptrStudio(ptr) {}
    ~StudioWrapper() { delete ptrStudio; }
    Studio *ptrStudio = nullptr;
};

int main()
{
    std::cout << std::endl;

    SignalChainWrapper signalChainWrapper{new SignalChain};
    SignalChain &chain1 = *signalChainWrapper.ptrSignalChain;

    std::cout << "The " + chain1.speaker.name + " speaker has been turned ";
    std::cout << (chain1.speaker.toggleOnOff() ? "ON\n" : "OFF\n");

    chain1.speaker.selfToggleOnOFF();
    std::cout << std::endl;

    StudioWrapper studioWrapper{new Studio};
    Studio &studio1 = *studioWrapper.ptrStudio;

    std::cout << "The " + studio1.bass.name + " is ";
    std::cout << (studio1.bass.activeStatus() ? "an active bass\n" : "a passive bass\n");

    studio1.bass.reportActive();
    std::cout << std::endl;

    std::cout << "good to go!" << std::endl;
}
