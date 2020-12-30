//
//  FakeOutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "I_OutputSystem.hpp"
#include <list>
#include <string>

class FakeOutputSystem: public I_OutputSystem
{
public:
   FakeOutputSystem();
   virtual ~FakeOutputSystem();

   // inherited
   void showTextToUser(const char* displayString) override;

   // helpers
   std::string mostRecentOutput() const;
   bool contains(const std::string& outputEntry) const;

private:
   std::string mostRecentOutput_;
   std::list<std::string> capturedOutput_;
};
