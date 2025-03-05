// Composite contains transport functionality and can be used both
// as an "Event" or a "Track" depending on the users needs

#pragma once

// Headers
#include "Component.h"
#include "RealVoicePool.h"
#include "VirtualVoicePool.h"

// Libraries
#include <list>
#include <string>
#include <iostream>

class Composite :
    public Component
{
protected:
    std::list<Component*> _children;

public:
    void Add(Component* component) override;
    void Remove(Component* component) override;
    bool IsComposite() const override;

    void play() override {}
    void stop() override {}

    std::string Operation() const override;
    
    void setVolume(float vol) override {}
    void adjustVolume() override {}
};

