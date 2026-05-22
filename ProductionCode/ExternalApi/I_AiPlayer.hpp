//
//  I_AiPlayer.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-22.
//

#include "I_InputSystem.hpp"
#include "I_OutputSystem.hpp"
#include <string>

class I_AiPlayer : public I_InputSystem, public I_OutputSystem
{
public:
    virtual std::string playerIdentifier() const = 0;
};
