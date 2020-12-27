//
//  FakeOutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "I_OutputSystem.hpp"
#include <string>

class FakeOutputSystem: public I_OutputSystem
{
public:
   FakeOutputSystem();
   virtual ~FakeOutputSystem();

   // inherited
   void showTextToUser(const char* displayString) override;

   // helpers
   std::string mostRecentOutput();

private:
   std::string mostRecentOutput_;
};
