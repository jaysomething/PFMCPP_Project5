/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 1) For any std::cout statements you had in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
 
 2) if you didn't have any std::cout statements in main() that accessed member variables:
         write some.
         then do 1a) & 1b)
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        void memberFunc() { std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; }  //3)
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    int main()
    {
        MyFoo mf;
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl;  //3)
        mf.memberFunc();
        return 0;
    }
}

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>

/*
 copied UDT 1:
 */

struct Speaker
{
    Speaker(std::string speakerName) : name(speakerName)
    {
        std::cout << "Speaker ctor: " + name << std::endl;
    }
    ~Speaker()
    {
        std::cout << "Speaker dtor: " + name << std::endl;
    }

    std::string name;
    bool isOn{false};
    float coneSize{6.0f};
    bool isPorted{true};

    struct Eq
    {
        Eq() : isOn(true), shape("Bell"), freq(200.0), gain(0.0) 
        {
            std::cout << "Eq ctor\n";
        }

        ~Eq()
        {
            isOn = false;
            std::cout << "Eq dtor\n";
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
};

bool Speaker::toggleOnOff()
{
    if (isOn)
    {
        isOn = false;
        std::cout << "Speaker is turned OFF" << std::endl;
        return false;
    }

    isOn = true;
    std::cout << "Speaker is turned ON" << std::endl;
    return true;
}

void Speaker::turnOnEq(Eq eq1)
{
    eq1.isOn = true;
    std::cout << "EQ has been turned ON" << std::endl;
}

void Speaker::Eq::printStatus()
{
    if (isOn)
    {
        std::cout << "EQ is ON" << std::endl;
    }
    else
    {
        std::cout << "EQ is OFF" << std::endl;
    }
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
    Bass(std::string bassName, int numString) : name(bassName), numberOfStrings(numString)
    {
        std::cout << "Bass ctor: " << name << numberOfStrings << std::endl;
    }
    ~Bass()
    {
        std::cout << "Bass dtor: " << name << numberOfStrings << std::endl;
    }

    std::string name;
    int numberOfStrings;
    int scale{34};
    bool isActive{true};
    std::array<std::string, 12> circleOfFourths = {"C", "G", "D", "A", "E", "B", "Gb", "Db", "Ab", "Eb", "Bb", "F"};

    void playInstrument();
    void playOpenStrings(int numberOfStrings);
};

void Bass::playInstrument()
{
    std::cout << "Playing bass" << std::endl;
    std::cout << name << " " << numberOfStrings << "-string" << std::endl;
    std::cout << scale << "' scale";
    if (isActive)
    {
        std::cout << " active bass" << std::endl;
    }
    else
    {
        std::cout << " passive bass" << std::endl;
    }
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
        std::cout << circleOfFourths[(index + i) % 12] << std::endl;
    }
}

/*
 copied UDT 3:
 */

struct Mixer
{
    Mixer(std::string mixerName, size_t numChan) : name(mixerName), numberOfChannels(numChan)
    {
        std::cout << "Mixer ctor: " << name << numberOfChannels << std::endl;
        channels.reserve(numberOfChannels);
        for (size_t i = 0; i < numberOfChannels; i++)
        {
            channels[i].number = int(i) + 1;
        }
    }
    ~Mixer()
    {
        std::cout << "Mixer dtor: " << name << numberOfChannels << std::endl;
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
};

void Mixer::printStatus()
{
    std::cout << name << " " << numberOfChannels << "-channel mixer is ";

    if (isOn)
    {
        std::cout << "ON" << std::endl;
    }
    else
    {
        std::cout << "OFF" << std::endl;
    }
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
        if (channels[i].isMuted)
        {
            std::cout << "Channel " << channels[i].number << " is muted" << std::endl;
        }
        else
        {
            std::cout << "Channel " << channels[i].number << " is ON" << std::endl;
        }
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
    SignalChain() : fender5("Fender", 5), midas("Midas", 32), adam("ADAM")
    {
        std::cout << "SignalChain ctor\n";
        fender5.playInstrument();
    }
    ~SignalChain()
    {
        std::cout << "SignalChain dtor\n";
    }

    Bass fender5;
    Mixer midas;
    Speaker adam;
};

/*
 new UDT 5:
 */

struct Studio
{
    Studio() : ks6{"Ken Smith", 6}, mackie{"Mackie", 8}, genelec{"Genelec"}
    {
        std::cout << "Studio ctor\n";
        mackie.printStatus();
        genelec.toggleOnOff();
        ks6.playOpenStrings(6);
    }
    ~Studio()
    {
        std::cout << "Studio dtor\n";
    }

    Bass ks6;
    Mixer mackie;
    Speaker genelec;
};


int main()
{
    Example::main();
    SignalChain chain1;
    Studio studio1;
    std::cout << "good to go!" << std::endl;
}
