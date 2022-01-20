#include "ToyRobot.h"

#include <iostream>
#include <assert.h>

int RunTests()
{
   ToyRobot toyRobot;

   //test for commands before PLACE
   assert(toyRobot.PerformCommand(ToyRobot::CommandLeft) == false);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);

   //test place position out of bounds
   assert(toyRobot.PerformCommand("PLACE 10 0 NORTH") == false);
   //other commands should still fail
   assert(toyRobot.PerformCommand(ToyRobot::CommandLeft) == false);

   //test place position
   assert(toyRobot.PerformCommand("PLACE 0 0 NORTH") == true);
   assert(toyRobot.GetX() == 0);
   assert(toyRobot.GetY() == 0);
   assert(toyRobot.GetFacing() == ToyRobot::CommandNorth);

   //test board northern limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 0);
   assert(toyRobot.GetY() == 4);

   //test right rotation then eastern limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandRight) == true);
   assert(toyRobot.GetFacing() == ToyRobot::CommandEast);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 4);
   assert(toyRobot.GetY() == 4);

   //test right rotation then southern limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandRight) == true);
   assert(toyRobot.GetFacing() == ToyRobot::CommandSouth);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 4);
   assert(toyRobot.GetY() == 0);

   //test right rotation then western limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandRight) == true);
   assert(toyRobot.GetFacing() == ToyRobot::CommandWest);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 0);
   assert(toyRobot.GetY() == 0);

   //test left rotation then southern limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandLeft) == true);
   assert(toyRobot.GetFacing() == ToyRobot::CommandSouth);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 0);
   assert(toyRobot.GetY() == 0);

   //test left rotation then eastern limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandLeft) == true);
   assert(toyRobot.GetFacing() == ToyRobot::CommandEast);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 4);
   assert(toyRobot.GetY() == 0);

   //test left rotation then northern limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandLeft) == true);
   assert(toyRobot.GetFacing() == ToyRobot::CommandNorth);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 4);
   assert(toyRobot.GetY() == 4);

   //test left rotation then western limits
   assert(toyRobot.PerformCommand(ToyRobot::CommandLeft) == true);
   assert(toyRobot.GetFacing() == ToyRobot::CommandWest);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == true);
   assert(toyRobot.PerformCommand(ToyRobot::CommandMove) == false);
   assert(toyRobot.GetX() == 0);
   assert(toyRobot.GetY() == 4);

   //test bad entries
   assert(toyRobot.PerformCommand("PLACE 0 0 NORTHEAST") == false);
   assert(toyRobot.PerformCommand("PLACE bad 0 NORTHEAST") == false);
   assert(toyRobot.PerformCommand("PLACE 0 0") == false);
   assert(toyRobot.PerformCommand("bad") == false);
   assert(toyRobot.PerformCommand("") == false);

   //test report function
   assert(toyRobot.PerformCommand(ToyRobot::CommandReport) == true);

   std::cout << "Success" << std::endl;
   return 0;
}

int main(int argc, char *argv[])
{
   if (argc > 1)
   {
      if (strcmp(argv[1], "test") == 0)
      {
         return RunTests();
      }
   }

   ToyRobot toyRobot;
   toyRobot.Run();

   return 0;
}