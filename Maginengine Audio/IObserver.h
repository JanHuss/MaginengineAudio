#pragma once
#include "VoiceBase.h"

class IObserver
{
public:
	virtual ~IObserver(){}
	virtual void onVoiceSwitched(VoiceBase* newVoice) = 0;


};