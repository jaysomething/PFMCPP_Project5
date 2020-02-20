#pragma once

struct Speaker;
struct Bass;
struct Mixer;
struct SignalChain;
struct Studio;

struct SpeakerWrapper
{
    SpeakerWrapper(Speaker* ptr);
    ~SpeakerWrapper();
    Speaker *ptrSpeaker = nullptr;
};

struct BassWrapper
{
    BassWrapper(Bass *ptr);
    ~BassWrapper();
    Bass *ptrBass = nullptr;
};

struct MixerWrapper
{
    MixerWrapper(Mixer *ptr);
    ~MixerWrapper();
    Mixer *ptrMixer = nullptr;
};

struct SignalChainWrapper
{
    SignalChainWrapper(SignalChain* ptr);
    ~SignalChainWrapper();
    SignalChain* ptrSignalChain = nullptr;
};

struct StudioWrapper
{
    StudioWrapper(Studio* ptr);
    ~StudioWrapper();
    Studio* ptrStudio = nullptr;
};
