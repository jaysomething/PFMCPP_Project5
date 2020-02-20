#include "Wrappers.h"
#include "Speaker.h"
#include "Bass.h"
#include "Mixer.h"
#include "SignalChain.h"
#include "Studio.h"

SpeakerWrapper::SpeakerWrapper(Speaker *ptr) : ptrSpeaker(ptr) {}
SpeakerWrapper::~SpeakerWrapper() { delete ptrSpeaker; }

BassWrapper::BassWrapper(Bass *ptr) : ptrBass(ptr) {}
BassWrapper::~BassWrapper() { delete ptrBass; }

MixerWrapper::MixerWrapper(Mixer *ptr) : ptrMixer(ptr) {}
MixerWrapper::~MixerWrapper() { delete ptrMixer; }

SignalChainWrapper::SignalChainWrapper(SignalChain* ptr) : ptrSignalChain(ptr) {}
SignalChainWrapper::~SignalChainWrapper() { delete ptrSignalChain; }

StudioWrapper::StudioWrapper(Studio* ptr) : ptrStudio(ptr) {}
StudioWrapper::~StudioWrapper() { delete ptrStudio; }
