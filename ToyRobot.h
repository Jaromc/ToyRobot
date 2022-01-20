#pragma once

#include <sstream>

//---------------------------------------------------------------------------------------------------------------------
// ToyRobot main Class.
// This handles autonomous game logic and accessors for unit testing.
class ToyRobot
{
public:
   ToyRobot();
   ~ToyRobot(){}

   //Starts the application.
   //This will automatically capture input and pass onto PerformCommand().
   void Run();
   //Primarily used for unit testing.
   bool PerformCommand(const std::string& input);

   //Gets the current ToyRobot position and facing
   const std::string& GetFacing() const { return m_facing; }
   int GetX() const { return m_x; }
   int GetY() const { return m_y; }

   //Commands used to drive game logic. Publicly available for unit testing
   static const int GridSize;
   static const std::string CommandPlace;
   static const std::string CommandMove;
   static const std::string CommandLeft;
   static const std::string CommandRight;
   static const std::string CommandReport;
   static const std::string CommandQuit;

   static const std::string CommandNorth;
   static const std::string CommandEast;
   static const std::string CommandSouth;
   static const std::string CommandWest;

private:
   bool Move();
   void Report();
   void TurnLeft();
   void TurnRight();

   int m_x = 0;
   int m_y = 0;
   std::string m_facing;
};
//---------------------------------------------------------------------------------------------------------------------
