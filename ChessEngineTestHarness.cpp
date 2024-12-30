//
//  ChessEngineTestHarness.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#include "ChessEngineTestHarness.hpp"

#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"
#include "ChessEngine.hpp"
#include "CommandDefines.hpp"

using namespace std;

ChessEngineTestHarness::ChessEngineTestHarness()
: inputSystem_(new FakeInputSystem())
, outputSystem_(new FakeOutputSystem())
, engine_(new ChessEngine(*inputSystem_, *outputSystem_))
{

}

ChessEngineTestHarness::~ChessEngineTestHarness()
{
   
}

FakeInputSystem& ChessEngineTestHarness::fakeInput()
{
   return *inputSystem_;
}

FakeOutputSystem& ChessEngineTestHarness::fakeOutput()
{
   return *outputSystem_;
}

ChessEngine& ChessEngineTestHarness::chessEngine()
{
   return *engine_;
}

void ChessEngineTestHarness::setInputSequenceAppendingQuit(const list<string>& inputSequence)
{
   list<string> finalInputSequence = inputSequence;
   finalInputSequence.push_back(CommandDefines::QUIT_COMMAND);

   fakeInput().setInputSequence(finalInputSequence);
}

bool ChessEngineTestHarness::isLastOutputBeforeQuittingEqualTo(const string &outputString)
{
   if (fakeOutput().size() < 2)
      {
         return false;
      }
    bool stringsCompareAsEqual = (fakeOutput().secondLastOutput() == outputString);
    if (!stringsCompareAsEqual)
    {
        fprintf(stderr, "Expected: %s\nActual:   %s", outputString.c_str(), fakeOutput().secondLastOutput().c_str());
    }
   return stringsCompareAsEqual;
}
