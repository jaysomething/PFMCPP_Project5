#pragma once

#include "Bass.h"
#include "LeakedObjectDetector.h"
#include "Mixer.h"
#include "Speaker.h"
#include "Wrappers.h"

struct Studio
{
    BassWrapper bassWrapper{new Bass("Ken Smith", 6)};
    Bass& bass = *bassWrapper.ptrBass;

    MixerWrapper mixerWrapper{new Mixer("Mackie", 8)};
    Mixer& mixer = *mixerWrapper.ptrMixer;

    SpeakerWrapper speakerWrapper{new Speaker("Genelec")};
    Speaker& speaker = *speakerWrapper.ptrSpeaker;

    JUCE_LEAK_DETECTOR(Studio)
};
