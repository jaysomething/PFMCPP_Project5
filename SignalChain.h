#pragma once

#include "Bass.h"
#include "Mixer.h"
#include "Speaker.h"
#include "Wrappers.h"
#include "LeakedObjectDetector.h"

struct SignalChain
{
    BassWrapper bassWrapper{new Bass("Fender", 5)};
    Bass& bass = *bassWrapper.ptrBass;

    MixerWrapper mixerWrapper{new Mixer("Midas", 32)};
    Mixer& mixer = *mixerWrapper.ptrMixer;

    SpeakerWrapper speakerWrapper{new Speaker("ADAM")};
    Speaker& speaker = *speakerWrapper.ptrSpeaker;

    JUCE_LEAK_DETECTOR(SignalChain)
};
