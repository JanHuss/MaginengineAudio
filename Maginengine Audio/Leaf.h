// Leaf is designated for "Tracks" that can make use of the transport 
// controls.
// Currently, Tracks are Children only and can only hold one audio asset.

#pragma once

// Headers
#include "Component.h"

// Libraries
#include <string>

class Leaf :
    public Component
{
    public:
    std::string Operation() const override; 
};

