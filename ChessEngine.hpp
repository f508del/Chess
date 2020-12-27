//
//  ChessEngine.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

class I_InputSystem;
class I_OutputSystem;

class ChessEngine
{
public:
   explicit ChessEngine(I_InputSystem& inputSystem,
                        I_OutputSystem& outputSystem);

   virtual ~ChessEngine();

   void runChessEngine();

private:
   void displayMainMenu();

private:
   I_InputSystem& inputSystem_;
   I_OutputSystem& outputSystem_;
};
